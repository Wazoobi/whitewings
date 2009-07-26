#include "CJumper.h"

CJumper::CJumper()
{
	m_uiState = PATROL;
	m_uiEnemyType = JUMPER;

	m_nDisplayDepth = 1;	// Z-sorting
	m_uiRefCount = 1;		// Always start with a reference to yourself
	m_uiType = OBJ_ENEMY;

	SetPosX(0.0f);
	SetPosY(0.0f);
	SetVelX(0.0f);
	SetVelY(0.0f);
}

CJumper::~CJumper()
{

}

bool CJumper::CheckCollision(CBase* pBase)
{
	// TODO: See CBase Check Collision TODO
	return false;
}

void CJumper::Update(float fElapsedTime)
{
	// TODO: Implement switch based on m_uiState
}

void CJumper::Render(void)
{
	// TODO: See CBase Render TODO
}