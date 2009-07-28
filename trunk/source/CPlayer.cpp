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
#include "CDoor.h"
#include "CHackStation.h"

#include "CPausedState.h"

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
	SetVelY(0.0f);

	m_nImageID = CSGD_TextureManager::GetInstance()->LoadTexture("resource/graphics/Ping.bmp");
	m_nHackableImageID = CSGD_TextureManager::GetInstance()->LoadTexture("resource/graphics/Hackable.jpg");

	m_bDrawHackableImage = false;

	m_fGravity = 25.0f;
	m_fGravityTimer = 0.0f;

	m_nCollisionType = 0;
	
	m_fInvulnerableTimer = 0.0f;
	m_bIsInvulnerable = false;
}

CPlayer::~CPlayer(void)
{
	
}

void CPlayer::ResetPlayer()
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
	SetVelY(0.0f);

	m_bDrawHackableImage = false;

	m_fGravity = 25.0f;
	m_fGravityTimer = 0.0f;

	m_nCollisionType = 0;

	m_fInvulnerableTimer = 0.0f;
	m_bIsInvulnerable = false;
}

CPlayer* CPlayer::GetInstance()
{
	static CPlayer instance;
	return &instance;
}

void CPlayer::Update(float fElapsedTime)
{
	m_fStunGunTimer += fElapsedTime;
	

	// TODO: Set up a losing state
	if(m_nHealth <= 0)
		CGame::GetInstance()->PushState(CPausedState::GetInstance());

	if(m_bIsInvulnerable)
	{
		m_fInvulnerableTimer += fElapsedTime;
		if(m_fInvulnerableTimer > 2.0f)
		{
			m_bIsInvulnerable = false;
			m_fInvulnerableTimer = 0.0f;
		}
	}

	if(m_bIsHacking)
		m_bIsHacking = false;
	
	if(m_bDrawHackableImage)
		m_bDrawHackableImage = false;

	SetPosY(GetPosY() + GetVelY()*fElapsedTime);

// 	if((CSGD_DirectInput::GetInstance()->KeyDown(DIK_DOWN) || CSGD_DirectInput::GetInstance()->JoystickGetLStickDirDown(DIR_DOWN,0)) && !m_bIsDashing && !m_bIsHackingTerminal)
// 		SetPosY(GetPosY() + GetVelY()*fElapsedTime);
// 
// 	if((CSGD_DirectInput::GetInstance()->KeyDown(DIK_UP) || CSGD_DirectInput::GetInstance()->JoystickGetLStickDirDown(DIR_UP,0)) && !m_bIsDashing && !m_bIsHackingTerminal)
// 		SetPosY(GetPosY() - GetVelY()*fElapsedTime);

	if((CSGD_DirectInput::GetInstance()->KeyDown(DIK_LEFT) || CSGD_DirectInput::GetInstance()->JoystickGetLStickDirDown(DIR_LEFT,0)) && !m_bIsDashing && !m_bIsHackingTerminal && m_nCollisionType != 2)
	{
		SetPosX(GetPosX()-GetVelX()*fElapsedTime);
		m_nDirection = 0;
	}

	if((CSGD_DirectInput::GetInstance()->KeyDown(DIK_RIGHT) || CSGD_DirectInput::GetInstance()->JoystickGetLStickDirDown(DIR_RIGHT,0)) && !m_bIsDashing && !m_bIsHackingTerminal && m_nCollisionType != 1)
	{
		SetPosX(GetPosX()+GetVelX()*fElapsedTime);
		m_nDirection = 1;
	}

	if(CSGD_DirectInput::GetInstance()->KeyPressed(DIK_SPACE) && !m_bIsJumping && !m_bIsHackingTerminal)
	{
		if(!m_bIsJumping)
		{
			m_bIsJumping = true;
			SetVelY(-400.0f);
		}
	}

	if(CSGD_DirectInput::GetInstance()->KeyPressed(DIK_Q) && !m_bIsDashing && !m_bIsHackingTerminal)
	{
		m_bIsDashing = true;
		SetVelX(GetVelX()*10.0f);
		m_fDashTimer = 0.0f;
	}

	if(CSGD_DirectInput::GetInstance()->KeyPressed(DIK_W) && m_fStunGunTimer > SHOT_DELAY && !m_bIsHackingTerminal)
	{
		m_fStunGunTimer = 0.0f;
		CMessageManager::GetInstance()->SendMsg(new CCreateStunShotMessage(this));
	}

	if(CSGD_DirectInput::GetInstance()->KeyPressed(DIK_E))
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
			m_fDashTimer = 0.0f;
		}
	}

	if(m_bIsJumping)
	{
		m_fGravityTimer += fElapsedTime;
		SetVelY(GetVelY()+m_fGravity*m_fGravityTimer*m_fGravityTimer);
	}
	else
	{
		SetVelY(100.0f);
		m_fGravityTimer = 0.0f;
	}

// 	if(GetPosY() > 300.0f)
// 	{
// 		SetPosY(300.0f);
// 		m_bIsJumping = false;
// 		SetVelY(0.0f);
// 		m_fGravityTimer = 0.0f;
// 	}

	CSGD_DirectInput::GetInstance()->ReadDevices();

	m_nCollisionType = 0;
}

void CPlayer::Render(void)
{
	// TODO:	Render the current frames image
	CSGD_TextureManager::GetInstance()->Draw(m_nImageID, GetPosX(), GetPosY());

	if(m_bDrawHackableImage)
		CSGD_TextureManager::GetInstance()->Draw(m_nHackableImageID, GetPosX(), GetPosY()-35);

	CSGD_Direct3D::GetInstance()->SpriteEnd();
	CSGD_Direct3D::GetInstance()->DeviceEnd();

	if(m_bIsInvulnerable)
		CSGD_Direct3D::GetInstance()->DrawText("Invulnerable", GetPosX(), GetPosY() + 32);

	CSGD_Direct3D::GetInstance()->DeviceBegin();
	CSGD_Direct3D::GetInstance()->SpriteBegin();
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
					CHackStation* pHackStation = (CHackStation*)pBase;
					m_bIsHacking = false;
					m_bIsHackingTerminal = true;
					CHackingState::GetInstance()->SetTerminalSignature(pHackStation->GetTerminalSignature());
					CGame::GetInstance()->PushState(CHackingState::GetInstance());
				}
				else
				{
					m_bIsHacking = false;
					m_bIsHackingTerminal = false;
					CGame::GetInstance()->PopState();
				}
			}

			if(!m_bIsHacking && !m_bIsHackingTerminal)
				m_bDrawHackableImage = true;

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
			else if(!m_bIsHacking && pEnemy->GetState() == STUNNED)
			{
				m_bDrawHackableImage = true;
			}
			else if(!m_bIsInvulnerable && pEnemy->GetState() != HACKED)
			{
				// TODO: Make the player take damage and immune to damage for a short period of time.
				m_nHealth -= 10;
				m_bIsInvulnerable = true;
			}
		}

		if(pBase->GetObjectType() == OBJ_DOOR)
		{
			CDoor* pDoor = (CDoor*)pBase;

			if(pDoor->GetIsLocked())
			{
				// The Door is on the right of the player
				if(pBase->GetPosX() > GetPosX())
				{
					m_nCollisionType = 1;
					SetPosX(pBase->GetPosX()-32.0f);
					if(m_bIsDashing)
					{
						m_bIsDashing = false;
						SetVelX(GetVelX()/10.0f);
						m_fDashTimer = 0.0f;
					}
				}
				// The Door is on the left of the player
				else
				{
					m_nCollisionType = 2;
					SetPosX(pBase->GetPosX()+32.0f);
					if(m_bIsDashing)
					{
						m_bIsDashing = false;
						SetVelX(GetVelX()/10.0f);
						m_fDashTimer = 0.0f;
					}
				}
			}
		}
	}

	return false;
}