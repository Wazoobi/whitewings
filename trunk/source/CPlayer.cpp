////////////////////////////////////////////////////////////////////////
//	File Name	:	"CPlayer.cpp"
//
//	Author		:	Juno Madden (JM)
//
//	Purpose		:	To encapsulate all player data 
////////////////////////////////////////////////////////////////////////

#include "CPlayer.h"

#include "SGD Wrappers/CSGD_TextureManager.h"
#include "SGD Wrappers/CSGD_DirectInput.h"
#include "CGame.h"

#include "CEnemy.h"

#include "CMessageManager.h"

#include "CHackingState.h"

CPlayer::CPlayer(void)
{
	m_fStunGunTimer = SHOT_DELAY;
	m_bStunGunReady = false;
	m_bEnemyHacked = false;
	m_fDashTimer = 0.0f;
	m_bIsDashing = false;
	m_bIsJumping = false;
	m_bIsHacking = false;
	m_nHealth = 100;
	m_nHackOrbs = 0;
	m_nDirection = 1;

	m_bTouchingTerminal = false;
	m_bIsHackingTerminal = false;
	m_pCurrentlyHackedEnemy = NULL;

	m_nDisplayDepth = 1;	// Z-sorting
	m_uiRefCount = 2;
	m_uiType = OBJ_PLAYER;
	SetPosX(400.0f);
	SetPosY(300.0f);
	SetVelX(100.0f);
	SetVelY(50.0f);

	m_nImageID = CSGD_TextureManager::GetInstance()->LoadTexture("resource/graphics/JuM_CrossHair.bmp", D3DCOLOR_XRGB(0,0,0));
}

CPlayer::~CPlayer(void)
{

}

CPlayer* CPlayer::GetInstance()
{
	static CPlayer instance;
	return &instance;
}

void CPlayer::Update(float fElapsedTime)
{
	m_fStunGunTimer += fElapsedTime;
	m_bIsHacking = false;


	if((CSGD_DirectInput::GetInstance()->KeyDown(DIK_DOWN) || CSGD_DirectInput::GetInstance()->JoystickGetLStickDirDown(DIR_DOWN,0)) && !m_bIsDashing && !m_bIsHackingTerminal)
		SetPosY(GetPosY() + GetVelY()*fElapsedTime);

	
	if((CSGD_DirectInput::GetInstance()->KeyDown(DIK_LEFT) || CSGD_DirectInput::GetInstance()->JoystickGetLStickDirDown(DIR_LEFT,0)) && !m_bIsDashing && !m_bIsHackingTerminal)
	{
		SetPosX(GetPosX()-GetVelX()*fElapsedTime);
		m_nDirection = 0;
	}

	if((CSGD_DirectInput::GetInstance()->KeyDown(DIK_RIGHT) || CSGD_DirectInput::GetInstance()->JoystickGetLStickDirDown(DIR_RIGHT,0)) && !m_bIsDashing && !m_bIsHackingTerminal)
	{
		SetPosX(GetPosX()+GetVelX()*fElapsedTime);
		m_nDirection = 1;
	}

	if(CSGD_DirectInput::GetInstance()->KeyPressed(DIK_SPACE) && !m_bIsJumping && !m_bIsHackingTerminal)
	{
		m_bIsJumping = true;
	}

	if(CSGD_DirectInput::GetInstance()->KeyPressed(DIK_A) && !m_bIsDashing && !m_bIsHackingTerminal)
	{
		m_bIsDashing = true;
		SetVelX(GetVelX()*10.0f);
		m_fDashTimer = 0.0f;
	}

	if(CSGD_DirectInput::GetInstance()->KeyPressed(DIK_S) && m_fStunGunTimer > SHOT_DELAY && !m_bIsHackingTerminal)
	{
		m_fStunGunTimer = 0.0f;
		CMessageManager::GetInstance()->SendMsg(new CCreateStunShotMessage(this));
	}

	if(CSGD_DirectInput::GetInstance()->KeyPressed(DIK_D))
	{
		m_bIsHacking = true;

		// This block of code releases the currently hacked enemy if player hits the "hack button" while
		// not colliding with a hack station.
		if(m_bEnemyHacked && !m_bTouchingTerminal)
		{
			// TODO: Change the state that the enemy is in when you release him. CANNOT be STUNNED.
			m_pCurrentlyHackedEnemy->SetState(PATROL);
			m_pCurrentlyHackedEnemy = NULL;
			m_bEnemyHacked = false;
			m_bIsHacking = false;
		}

	}

	if(m_bIsDashing)
	{
		m_fDashTimer += fElapsedTime;
		
		if(m_nDirection == 0)
			SetPosX(GetPosX()-GetVelX()*fElapsedTime);
		else
			SetPosX(GetPosX()+GetVelX()*fElapsedTime);

		if(m_fDashTimer > 0.25f)
		{
			m_bIsDashing = false;
			SetVelX(GetVelX()/10.0f);
		}
	}

	CSGD_DirectInput::GetInstance()->ReadDevices();
}

void CPlayer::Render(void)
{
	// TODO:	Render the current frames image
	CSGD_TextureManager::GetInstance()->Draw(m_nImageID, GetPosX(), GetPosY());
}

bool CPlayer::CheckCollision(CBase* pBase)
{
	// TODO:	Use the current frame of the animation instance to grab the collision rect and 
	//			compare it to the collision rect of the passed in CBase pointer's animation instance's 
	//			current frame's collision rect.
	
	if(CBase::CheckCollision(pBase))
	{
		if(pBase->GetObjectType() == OBJ_HACKSTATION)
		{
			m_bTouchingTerminal = true;
			if(m_bIsHacking)
			{
				// TODO: Initiate Mini-game here!!!
				if(!m_bIsHackingTerminal)
				{
					m_bIsHacking = false;
					m_bIsHackingTerminal = true;
					CGame::GetInstance()->PushState(CHackingState::GetInstance());
				}
				else
				{
					m_bIsHacking = false;
					m_bIsHackingTerminal = false;
					CGame::GetInstance()->PopState();
				}
			}
		}
		else
			m_bTouchingTerminal = false;

		if(pBase->GetObjectType() == OBJ_ENEMY)
		{
			CEnemy *pEnemy = (CEnemy*)pBase;

			if(m_bIsHacking && pEnemy->GetState() == STUNNED)
			{
				pEnemy->SetState(HACKED);
				m_pCurrentlyHackedEnemy = pEnemy;
				m_bEnemyHacked = true;
				m_bIsHacking = false;
			}
		}
	}

	return false;
}