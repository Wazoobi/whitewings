#include "CWalker.h"

#include "CPlayer.h"

#include "SGD Wrappers/CSGD_DirectInput.h"

#include "SGD Wrappers/SGD_Math.h"

#include "SGD Wrappers/CSGD_TextureManager.h"
#include "CTileManager.h"

#define OFFSET_X CTileManager::GetInstance()->GetCamera()->GetCameraPosX()
#define OFFSET_Y CTileManager::GetInstance()->GetCamera()->GetCameraPosY()

CWalker::CWalker()
{
	m_uiState = PATROL;
	m_uiEnemyType = WALKER;

	m_nDisplayDepth = 1;	// Z-sorting
	m_uiRefCount = 1;		// Always start with a reference to yourself
	m_uiType = OBJ_ENEMY;

	SetPosX(750.0f);
	SetPosY(300.0f);
	SetVelX(100.0f);
	SetVelY(100.0f);

	m_fStunnedTimer = 0.0f;
	m_fAlertTimer = 0.0f;

	m_nImageID = CSGD_TextureManager::GetInstance()->LoadTexture("resource/graphics/Walker.bmp");

	///////////////////////////////////////
	// Anim
	
	m_WalkerAnimationInstance = CAnimationManager::GetInstance()->SetAnimationInstance("../Resource/AnimationManagerStuff/RobotSentinel.bmp", "Walking");
	m_WalkerAnimationInstance.m_CurrSheet->m_nImageID = CSGD_TextureManager::GetInstance()->LoadTexture("Resource/AnimationManagerStuff/RobotSentinel.bmp", D3DCOLOR_XRGB(0,96,64));
	m_WalkerAnimationInstance.m_CurrAnimation->m_bIsLooping = true;
	
	

	///////////////////////////////////////

}

CWalker::~CWalker()
{

}

bool CWalker::CheckCollision(CBase* pBase)
{
	// TODO: See CBase Check Collision TODO
	return false;
}

void CWalker::Update(float fElapsedTime)
{
	// TODO: Implement switch based on m_uiState
	switch (m_uiState)
	{
	case PATROL:
		{
			SetPosX(GetPosX() - GetVelX()*fElapsedTime);

			tVector2D currentPosVector;
			currentPosVector.fX = GetPosX();
			currentPosVector.fY = GetPosY();

			tVector2D playerPosVector;
			playerPosVector.fX = CPlayer::GetInstance()->GetPosX();
			playerPosVector.fY = CPlayer::GetInstance()->GetPosY();

			if(Vector2DLength(currentPosVector - playerPosVector) < m_fDetectionRange)
				m_uiState = CHASE;
			break;
		}
	case CHASE:
		{
			SetPosX(GetPosX() - GetVelX()*2*fElapsedTime);

			tVector2D currentPosVector;
			currentPosVector.fX = GetPosX();
			currentPosVector.fY = GetPosY();

			tVector2D playerPosVector;
			playerPosVector.fX = CPlayer::GetInstance()->GetPosX();
			playerPosVector.fY = CPlayer::GetInstance()->GetPosY();

			if(Vector2DLength(currentPosVector - playerPosVector) > m_fDetectionRange)
				m_uiState = PATROL;
			break;
		}
	case ATTACK:
		{
			break;
		}
	case STUNNED:
		{
			m_fStunnedTimer += fElapsedTime;
			if(m_fStunnedTimer > STUN_DURATION)
			{
				m_fStunnedTimer = 0.0f;
				m_uiState = PATROL;
			}
			break;
		}
	case HACKED:
		{
			// TODO: Implement Hack Specials

			if(CSGD_DirectInput::GetInstance()->KeyPressed(DIK_D))
			{

			}

			if(CSGD_DirectInput::GetInstance()->KeyPressed(DIK_F))
			{

			}

			if((CSGD_DirectInput::GetInstance()->KeyDown(DIK_DOWN) || CSGD_DirectInput::GetInstance()->JoystickGetLStickDirDown(DIR_DOWN,0)))
				SetPosX(GetPosX()-GetVelX()*fElapsedTime);

			if((CSGD_DirectInput::GetInstance()->KeyDown(DIK_UP) || CSGD_DirectInput::GetInstance()->JoystickGetLStickDirDown(DIR_UP,0)))
				SetPosX(GetPosX()+GetVelX()*fElapsedTime);

			break;
		}
	case ALERT:
		{
			m_fAlertTimer += fElapsedTime;
			if(m_fAlertTimer > ALERT_TIME)
			{
				m_fAlertTimer = 0.0f;
				m_uiState = PATROL;
			}
			break;
		}
	}

	/*if(GetPosX() < -32.0f)
		SetPosX(832.0f);*/

	SetPosY(GetPosY() + (GetVelY() * fElapsedTime));

	if(GetPosY() > 480.0f)
		SetPosY(480.0f);

	m_WalkerAnimationInstance = CAnimationManager::GetInstance()->Animate(m_WalkerAnimationInstance);
}

void CWalker::Render(void)
{
	// TODO: See CBase Render TODO

	CEnemy::Render();
	//CSGD_TextureManager::GetInstance()->Draw(m_nImageID, GetPosX() - CTileManager::GetInstance()->GetCamera()->GetCameraPosX(), GetPosY() - CTileManager::GetInstance()->GetCamera()->GetCameraPosY());
	CSGD_TextureManager::GetInstance()->Draw(m_WalkerAnimationInstance.m_CurrSheet->m_nImageID,
		(GetPosX() + m_WalkerAnimationInstance.m_CurrFrame->m_shAnchorX - m_WalkerAnimationInstance.m_CurrFrame->m_RImageRect.left)- OFFSET_X,
		(GetPosY() - 5) - OFFSET_Y, -0.5, 0.5, &m_WalkerAnimationInstance.m_CurrFrame->m_RImageRect);
}