#include "CEnemy.h"

#include "SGD Wrappers/SGD_Math.h"

#include "CPlayer.h"

#include "SGD Wrappers/CSGD_DirectInput.h"
#include "SGD Wrappers/CSGD_Direct3D.h"
#include "SGD Wrappers/CSGD_TextureManager.h"

CEnemy::CEnemy()
{
	m_nDetectionRangeImageID = CSGD_TextureManager::GetInstance()->LoadTexture("resource/graphics/JuM_DetectionRange.bmp", D3DCOLOR_XRGB(255,255,255));

	m_uiState = PATROL;
	m_uiEnemyType = WALKER;
	m_nDetectionRange = 200.0f;

	m_nDisplayDepth = 1;	// Z-sorting
	m_uiRefCount = 1;		// Always start with a reference to yourself
	m_uiType = OBJ_ENEMY;

	SetPosX(750.0f);
	SetPosY(300.0f);
	SetVelX(100.0f);
	SetVelY(0.0f);

	m_fStunnedTimer = 0.0f;
	m_fAlertTimer = 0.0f;
}

CEnemy::~CEnemy()
{

}

bool CEnemy::CheckCollision(CBase* pBase)
{
	// TODO: See CBase Check Collision TODO

	return false;
}

void CEnemy::Update(float fElapsedTime)
{
	// TODO: Check if the enemy is within the view of the camera.
	// TODO: Implement switch based on m_uiState
	// TODO: Check the distance between the player and the enemy.
	// TODO: If the player is within the view radius, change the enemies state to chase.

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

			if(Vector2DLength(currentPosVector - playerPosVector) < m_nDetectionRange)
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

			if(Vector2DLength(currentPosVector - playerPosVector) > m_nDetectionRange)
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
			if(CPlayer::GetInstance()->GetDirection() == 0)
				SetPosX(CPlayer::GetInstance()->GetPosX() - 32);
			else
				SetPosX(CPlayer::GetInstance()->GetPosX() + 32);

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

void CEnemy::Render(void)
{
	// TODO: See CBase Render TODO

	char *szCurrentState;

	switch(m_uiState)
	{
	case PATROL:
		{
			szCurrentState = "PATROL";
			break;
		}
	case CHASE:
		{
			szCurrentState = "CHASE";
			break;
		}
	case ATTACK:
		{
			szCurrentState = "ATTACK";
			break;
		}
	case STUNNED:
		{
			szCurrentState = "STUNNED";
			break;
		}
	case HACKED:
		{
			szCurrentState = "HACKED";
			break;
		}
	case ALERT:
		{
			szCurrentState = "ALERT";
			break;
		}
	}

	CSGD_Direct3D::GetInstance()->SpriteEnd();
	CSGD_Direct3D::GetInstance()->DeviceEnd();

	CSGD_Direct3D::GetInstance()->DrawText(szCurrentState, GetPosX(), GetPosY() - 32);
// 	CSGD_Direct3D::GetInstance()->DrawLine(GetPosX(), GetPosY(), GetPosX()-200.0f, GetPosY(), 255, 0, 0);
// 	CSGD_Direct3D::GetInstance()->DrawLine(GetPosX(), GetPosY(), GetPosX()+200.0f, GetPosY(), 128, 0, 0);

	CSGD_Direct3D::GetInstance()->DeviceBegin();
	CSGD_Direct3D::GetInstance()->SpriteBegin();
	
	if(m_uiState == PATROL)
		CSGD_TextureManager::GetInstance()->Draw(m_nDetectionRangeImageID, GetPosX() - (252.0f * 0.80f), GetPosY() - (232.0f * 0.80f), 0.80f, 0.80f);

}