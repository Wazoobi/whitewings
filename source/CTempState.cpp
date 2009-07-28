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
#include "CHackingState.h"

#include "CStunShot.h"
#include "CPlayer.h"
#include "CWalker.h"
#include "CFlyer.h"
#include "CMessageManager.h"
#include "CHackOrb.h"
#include "CHackStation.h"
#include "CBullet.h"
#include "CTurret.h"
#include "CDoor.h"

#include "CLogger.h"

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

	SetStateType(OTHER);

	
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
	CPlayer::GetInstance()->ResetPlayer();
	//TODO: Change Background

	m_vLoggers.push_back(new CLogger("CTempState Render"));
	m_vLoggers.push_back(new CLogger("CTempState Check Collision"));

	m_pOF = CSGD_ObjectFactory<string, CBase>::GetInstance();
	m_pOM = CObjectManager::GetInstance();

	m_nBackgroundID = m_pTM->LoadTexture("resource/graphics/JuM_MissileCommand_BasicBackground.bmp");
	m_pOF->RegisterClassType<CStunShot>("CStunShot");
	m_pOF->RegisterClassType<CBullet>("CBullet");

	m_pPlayer = CPlayer::GetInstance();
	m_pPlayer->AddRef();

	m_pOM->AddObject(m_pPlayer);

	CWalker* pWalker = new CWalker();
	
	m_pOM->AddObject(pWalker);

	SAFE_RELEASE(pWalker);

	CFlyer* pFlyer = new CFlyer();

	pFlyer->SetPosX(600.0f);
	pFlyer->SetPosY(150.0f);

	m_pOM->AddObject(pFlyer);

	SAFE_RELEASE(pFlyer);

	CTurret* pTurret = new CTurret();

	pTurret->SetPosX(100.0f);
	pTurret->SetPosY(300.0f);

	m_pOM->AddObject(pTurret);

	SAFE_RELEASE(pTurret);

	CHackOrb* pHackOrb = new CHackOrb();

	pHackOrb->SetPosX(700.0f);
	pHackOrb->SetPosY(300.0f);

	m_pOM->AddObject(pHackOrb);

	SAFE_RELEASE(pHackOrb);

	CDoor* pDoor = new CDoor();

	pDoor->SetPosX(645.0f);
	pDoor->SetPosY(300.0f);

	m_pOM->AddObject(pDoor);

	SAFE_RELEASE(pDoor);

	CHackStation* pHackStation = new CHackStation();

	pHackStation->SetPosX(200.0f);
	pHackStation->SetPosY(300.0f);

	m_pOM->AddObject(pHackStation);

	SAFE_RELEASE(pHackStation);
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

	int nNumOfLoggers = m_vLoggers.size();
	for(int i = 0; i < nNumOfLoggers; ++i)
	{
		delete m_vLoggers[i];
	}

	m_vLoggers.clear();
}

// split up Execute() into the 3 main steps of a game
bool CTempState::Input(void)
{
	if(m_pDI->KeyPressed(DIK_ESCAPE) || CSGD_DirectInput::GetInstance()->JoystickButtonPressed(DIR_START,0))
	{
		pGame->PushState(CPausedState::GetInstance());
		//pGame->PushState(CHackingState::GetInstance());
	}

	return true;
}

void CTempState::Update(float fElapsedTime)
{
	m_pOM->UpdateObjects(fElapsedTime);

	m_vLoggers[1]->BeginPerformance();
	m_pOM->CheckCollisions();
	m_vLoggers[1]->EndPerformance();
	
	CMessageManager::GetInstance()->ProcessMessages();
}

void CTempState::Render(void)
{
	//TODO: Change Background
	//m_pTM->Draw(m_nBackgroundID,0, 0, 1, 1, 0, 0, 0, 0, D3DCOLOR_ARGB(255, 0, 0, 0));

	m_vLoggers[0]->BeginPerformance();
	m_pOM->RenderObjects();
	m_vLoggers[0]->EndPerformance();

}