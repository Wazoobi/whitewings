#include "CEnemy.h"

CEnemy::CEnemy()
{
	m_uiState = PATROL;
	m_uiEnemyType = WALKER;

	m_nDisplayDepth = 1;	// Z-sorting
	m_uiRefCount = 1;		// Always start with a reference to yourself
	m_uiType = OBJ_ENEMY;

	SetPosX(0.0f);
	SetPosY(0.0f);
	SetVelX(0.0f);
	SetVelY(0.0f);
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
}

void CEnemy::Render(void)
{
	// TODO: See CBase Render TODO
}