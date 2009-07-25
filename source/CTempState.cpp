//////////////////////////////////////////////////////////////////////////
//	File Name	:	"CTempState.h"
//
//	Author		:	Juno Madden (JM)
//
//	Purpose		:	Spike Solution... ish
//////////////////////////////////////////////////////////////////////////

#include "CTempState.h"
#include "CPausedState.h"
#include "CMainMenuState.h"
#include "COptionsState.h"

#include "CStunShot.h"
#include "CPlayer.h"
#include "CWalker.h"
#include "CSGD_MessageSystem.h"

CTempState::CTempState(void)
{
	// Get pointers to the SGD singletons
	m_pD3D = CSGD_Direct3D::GetInstance();
	m_pTM = CSGD_TextureManager::GetInstance();
	m_pDI = CSGD_DirectInput::GetInstance();
	m_pFM = CFontManager::GetInstance();

	m_pOF = NULL;
	m_pOM = NULL;

	pGame = CGame::GetInstance();

	m_nBackgroundID = 0;
	m_pPlayer = NULL;
}

CTempState::~CTempState(void)
{

}

CTempState* CTempState::GetInstance(void)
{
	// Lazy Instantiation
	static CTempState instance;
	return &instance;
}

void CTempState::Enter(void)
{	
	//TODO: Change Background

	m_pOF = CSGD_ObjectFactory<string, CBase>::GetInstance();
	m_pOM = CObjectManager::GetInstance();

	m_nBackgroundID = m_pTM->LoadTexture("resource/graphics/JuM_MissileCommand_BasicBackground.bmp");
	m_pOF->RegisterClassType<CStunShot>("CStunShot");

	m_pPlayer = CPlayer::GetInstance();

	m_pOM->AddObject(m_pPlayer);

	CWalker* pWalker = new CWalker();

	m_pOM->AddObject(pWalker);
}

void CTempState::Exit(void)
{
	m_pTM->UnloadTexture(m_nBackgroundID);

	m_pOF->UnregisterClassType("CStunShot");

	SAFE_RELEASE(m_pPlayer);

	m_pOM->RemoveAllObjects();

	if(m_pOF)
	{
		m_pOF->ShutdownObjectFactory();
		m_pOF = NULL;
	}

	m_pOM->DeleteInstance();
}

// split up Execute() into the 3 main steps of a game
bool CTempState::Input(void)
{
	if(m_pDI->KeyPressed(DIK_ESCAPE) || CSGD_DirectInput::GetInstance()->JoystickButtonPressed(DIR_START,0))
	{
		pGame->PushState(CPausedState::GetInstance());
	}

	return true;
}

void CTempState::Update(float fElapsedTime)
{
	m_pOM->UpdateObjects(fElapsedTime);
	m_pOM->CheckCollisions();
	CSGD_MessageSystem::GetInstance()->ProcessMessages();
}

void CTempState::Render(void)
{
	//TODO: Change Background
	m_pTM->Draw(m_nBackgroundID,0, 0, 1, 1, 0, 0, 0, 0, D3DCOLOR_ARGB(255, 0, 0, 0));

	m_pOM->RenderObjects();

}