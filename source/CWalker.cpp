#include "CWalker.h"


#include "SGD Wrappers/CSGD_TextureManager.h"

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
	SetVelY(0.0f);

	m_fStunnedTimer = 0.0f;
	m_fAlertTimer = 0.0f;

	m_nImageID = CSGD_TextureManager::GetInstance()->LoadTexture("resource/graphics/JuM_CrossHair.bmp", D3DCOLOR_XRGB(0,0,0));;

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
	CEnemy::Update(fElapsedTime);
}

void CWalker::Render(void)
{
	// TODO: See CBase Render TODO

	CEnemy::Render();
	CSGD_TextureManager::GetInstance()->Draw(m_nImageID, GetPosX(), GetPosY());
}