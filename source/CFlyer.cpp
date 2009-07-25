#include "CFlyer.h"

CFlyer::CFlyer()
{
	m_uiState = PATROL;
	m_uiEnemyType = FLYER;

	m_nDisplayDepth = 1;	// Z-sorting
	m_uiRefCount = 1;		// Always start with a reference to yourself
	m_uiType = OBJ_ENEMY;

	SetPosX(0.0f);
	SetPosY(0.0f);
	SetVelX(0.0f);
	SetVelY(0.0f);
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
}

void CFlyer::Render(void)
{
	// TODO: See CBase Render TODO
}