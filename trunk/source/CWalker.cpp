#include "CWalker.h"

CWalker::CWalker()
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
}

void CWalker::Render(void)
{
	// TODO: See CBase Render TODO
}