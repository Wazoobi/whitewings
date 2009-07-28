#include "CFlyer.h"

#include "SGD Wrappers/CSGD_TextureManager.h"

#include "CMessageManager.h"

#include "CPlayer.h"

#include "SGD Wrappers/SGD_Math.h"

#include "SGD Wrappers/CSGD_DirectInput.h"

CFlyer::CFlyer()
{
	m_nDetectionRangeImageID = CSGD_TextureManager::GetInstance()->LoadTexture("resource/graphics/JuM_DetectionRange.bmp", D3DCOLOR_XRGB(255,255,255));

	m_uiState = PATROL;
	m_uiEnemyType = FLYER;

	m_nDisplayDepth = 1;	// Z-sorting
	m_uiRefCount = 1;		// Always start with a reference to yourself
	m_uiType = OBJ_ENEMY;

	m_fFireRange = 100.0f;
	m_fShotDelay = 1.5f;
	m_fShotTimer = 0.5f;

	m_fDetectionRange = 200.0f;

	SetPosX(0.0f);
	SetPosY(0.0f);
	SetVelX(80.0f);
	SetVelY(100.0f);

	m_nImageID = CSGD_TextureManager::GetInstance()->LoadTexture("resource/graphics/Flyer.bmp");
}

CFlyer::~CFlyer()
{

}

bool CFlyer::CheckCollision(CBase* pBase)
{
	// TODO: See CBase Check Collision TODO
	return false;
}

void CFlyer::Update(float fElapsedTime)
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

			if(Vector2DLength(currentPosVector - playerPosVector) < m_fFireRange)
				m_uiState = ATTACK;

			break;
		}
	case ATTACK:
		{
			m_fShotTimer += fElapsedTime;

			if(m_fShotTimer > m_fShotDelay)
			{
				m_fShotTimer -= m_fShotDelay;

				// TODO: Make him shoot a bullet at the player's current location
				CMessageManager::GetInstance()->SendMsg(new CCreateBulletMessage(this));
			}

			tVector2D currentPosVector;
			currentPosVector.fX = GetPosX();
			currentPosVector.fY = GetPosY();

			tVector2D playerPosVector;
			playerPosVector.fX = CPlayer::GetInstance()->GetPosX();
			playerPosVector.fY = CPlayer::GetInstance()->GetPosY();

			if(Vector2DLength(currentPosVector - playerPosVector) > m_fFireRange)
				m_uiState = CHASE;

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
			SetPosX(CPlayer::GetInstance()->GetPosX());

			if((CSGD_DirectInput::GetInstance()->KeyDown(DIK_DOWN) || CSGD_DirectInput::GetInstance()->JoystickGetLStickDirDown(DIR_DOWN,0)))
				SetPosY(GetPosY()+GetVelY()*fElapsedTime);

			if((CSGD_DirectInput::GetInstance()->KeyDown(DIK_UP) || CSGD_DirectInput::GetInstance()->JoystickGetLStickDirDown(DIR_UP,0)))
				SetPosY(GetPosY()-GetVelY()*fElapsedTime);

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

	if(GetPosX() < -32.0f)
		SetPosX(832.0f);
}

void CFlyer::Render(void)
{
	// TODO: See CBase Render TODO
	CEnemy::Render();

	CSGD_TextureManager::GetInstance()->Draw(m_nImageID, GetPosX(), GetPosY());
}