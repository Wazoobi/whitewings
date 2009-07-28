#include "CTurret.h"

#include "SGD Wrappers/CSGD_TextureManager.h"

#include "SGD Wrappers/CSGD_DirectInput.h"

#include "CMessageManager.h"

#include "CPlayer.h"

#include "SGD Wrappers/SGD_Math.h"

CTurret::CTurret()
{
	m_uiState = PATROL;
	m_uiEnemyType = TURRET;

	m_nDisplayDepth = 1;	// Z-sorting
	m_uiRefCount = 1;		// Always start with a reference to yourself
	m_uiType = OBJ_ENEMY;

	SetPosX(0.0f);
	SetPosY(0.0f);
	SetVelX(0.0f);
	SetVelY(0.0f);

	m_fFireRange = 200.0f;
	m_fShotDelay = 1.5f;
	m_fShotTimer = 0.5f;

	m_fDetectionRange = 200.0f;

	m_nImageID = CSGD_TextureManager::GetInstance()->LoadTexture("resource/graphics/Turret.bmp");
}

CTurret::~CTurret()
{
	// TODO: Unload textures!!! ALL TEXTURES!!!
}

bool CTurret::CheckCollision(CBase* pBase)
{
	// TODO: See CBase Check Collision TODO
	return false;
}

void CTurret::Update(float fElapsedTime)
{
	// TODO: Implement switch based on m_uiState
	switch (m_uiState)
	{
	case PATROL:
		{
			tVector2D currentPosVector;
			currentPosVector.fX = GetPosX();
			currentPosVector.fY = GetPosY();

			tVector2D playerPosVector;
			playerPosVector.fX = CPlayer::GetInstance()->GetPosX();
			playerPosVector.fY = CPlayer::GetInstance()->GetPosY();

			if(Vector2DLength(currentPosVector - playerPosVector) < m_fFireRange)
				m_uiState = ATTACK;
			break;
		}
	case CHASE:
		{
			
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

			if(Vector2DLength(currentPosVector - playerPosVector) > m_fDetectionRange)
				m_uiState = PATROL;

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
}

void CTurret::Render(void)
{
	// TODO: See CBase Render TODO
	CEnemy::Render();

	CSGD_TextureManager::GetInstance()->Draw(m_nImageID, GetPosX(), GetPosY());
}