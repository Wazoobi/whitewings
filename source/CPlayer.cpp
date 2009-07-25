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

CPlayer::CPlayer(void)
{
	m_fStunGunTimer = 0.0f;
	m_bStunGunReady = false;
	m_bEnemyHacked = false;
	m_fDashTimer = 0.0f;
	m_bIsDashing = false;
	m_bIsJumping = false;
	m_nHealth = 100;
	m_nHackOrbs = 0;
	m_nDirection = 1;

	m_nDisplayDepth = 1;	// Z-sorting
	m_uiRefCount = 1;		// Always start with a reference to yourself
	m_uiType = OBJ_PLAYER;
	SetPosX(400.0f);
	SetPosY(300.0f);
	SetVelX(100.0f);
	SetVelY(100.0f);

	m_nImageID = CSGD_TextureManager::GetInstance()->LoadTexture("resource/graphics/JuM_CrossHair.bmp", D3DCOLOR_XRGB(0,0,0));
}

CPlayer::~CPlayer(void)
{

}

void CPlayer::Update(float fElapsedTime)
{
	if((CSGD_DirectInput::GetInstance()->KeyDown(DIK_LEFT) || CSGD_DirectInput::GetInstance()->JoystickGetLStickDirDown(DIR_LEFT,0)) && !m_bIsDashing)
	{
		SetPosX(GetPosX()-GetVelX()*fElapsedTime);
		m_nDirection = 0;
	}

	if((CSGD_DirectInput::GetInstance()->KeyDown(DIK_RIGHT) || CSGD_DirectInput::GetInstance()->JoystickGetLStickDirDown(DIR_RIGHT,0)) && !m_bIsDashing)
	{
		SetPosX(GetPosX()+GetVelX()*fElapsedTime);
		m_nDirection = 1;
	}

	if(CSGD_DirectInput::GetInstance()->KeyPressed(DIK_SPACE) && !m_bIsJumping)
	{
		m_bIsJumping = true;
	}

	if(CSGD_DirectInput::GetInstance()->KeyPressed(DIK_A) && !m_bIsDashing)
	{
		m_bIsDashing = true;
		SetVelX(GetVelX()*10.0f);
		m_fDashTimer = 0.0f;
	}

	if(CSGD_DirectInput::GetInstance()->KeyPressed(DIK_S))
	{
		// TODO: Set up the object factory to create the stun shot based on direction.
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
	return false;
}