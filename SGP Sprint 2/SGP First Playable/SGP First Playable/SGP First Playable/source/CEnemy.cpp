#include "CEnemy.h"

#include "SGD Wrappers/SGD_Math.h"

#include "CPlayer.h"

#include "SGD Wrappers/CSGD_DirectInput.h"
#include "SGD Wrappers/CSGD_Direct3D.h"
#include "SGD Wrappers/CSGD_TextureManager.h"

#include "CTileManager.h"

#define OFFSET_X CTileManager::GetInstance()->GetCamera()->GetCameraPosX()
#define OFFSET_Y CTileManager::GetInstance()->GetCamera()->GetCameraPosY()

CEnemy::CEnemy()
{
	m_nDetectionRangeImageID = CSGD_TextureManager::GetInstance()->LoadTexture("resource/graphics/JuM_DetectionRange.bmp", D3DCOLOR_XRGB(255,255,255));

	m_uiState = PATROL;
	m_uiEnemyType = WALKER;
	m_fDetectionRange = 200.0f;

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

	CSGD_Direct3D::GetInstance()->DrawText(szCurrentState, GetPosX() - OFFSET_X,
		(GetPosY() - 32) - OFFSET_Y);
//  	CSGD_Direct3D::GetInstance()->DrawLine(GetPosX(), GetPosY(), GetPosX()-m_fDetectionRange, GetPosY(), 255, 0, 0);
//  	CSGD_Direct3D::GetInstance()->DrawLine(GetPosX(), GetPosY(), GetPosX()+m_fDetectionRange, GetPosY(), 128, 0, 0);

	CSGD_Direct3D::GetInstance()->DeviceBegin();
	CSGD_Direct3D::GetInstance()->SpriteBegin();

	if(m_uiState == PATROL)
		CSGD_TextureManager::GetInstance()->Draw(m_nDetectionRangeImageID, (GetPosX() - (252.0f * 0.80f)) - OFFSET_X,
		(GetPosY() - (232.0f * 0.80f)) - OFFSET_Y, 0.80f, 0.80f);
}