//////////////////////////////////////////////////////////////////////////
//	File Name	:	"CGamePlayState.cpp"
//
//	Author		:	Juno Madden (JM)
//
//	Purpose		:	To encapsulate all gameplay code.
//////////////////////////////////////////////////////////////////////////

#include "CGamePlayState.h"
#include "CMainMenuState.h"
#include "CPausedState.h"
#include "CLogger.h"
#include "SGD Wrappers/SGD_Math.h"
#include "CMessageManager.h"
#include "CSGD_EventSystem.h"

#include "CBullet.h"
#include "CStunShot.h"
#include "CTurret.h"
#include "CHackOrb.h"
#include "CDoor.h"
#include "CHackStation.h"

#include <fstream>

CGamePlayState::CGamePlayState(void)
{
	// Get pointers to the SGD singletons
	m_pD3D = CSGD_Direct3D::GetInstance();
	m_pTM = CSGD_TextureManager::GetInstance();
	m_pDS = CSGD_DirectSound::GetInstance();
	m_pWM = CSGD_WaveManager::GetInstance();
	m_pDI = CSGD_DirectInput::GetInstance();
	m_pOF = NULL;
	m_pOM = NULL;
	m_pTileManager = NULL;
	
	pGame = CGame::GetInstance();

	m_pGodMode = NULL;
	m_pLevelUp = NULL;
	m_pBigBang = NULL;

	SetStateType(GAME);
}

CGamePlayState::~CGamePlayState(void)
{

}

CGamePlayState* CGamePlayState::GetInstance(void)
{
	// Lazy Instantiation
	static CGamePlayState instance;
	return &instance;
}

void CGamePlayState::Enter(void)
{
	m_pGodMode = "godmode";
	m_pLevelUp = "levelup";
	m_pBigBang = "bigbang";

	// Load common resources used by the game
	m_nSoundID = m_pWM->LoadWave("resource/sound/JuM_SGD_BGM.wav");
	
	//TODO: Change Background
	//m_nBackgroundID = m_pTM->LoadTexture("resource/graphics/JuM_City.bmp");

	m_pOF = CSGD_ObjectFactory<string, CBase>::GetInstance();
	m_pOM = CObjectManager::GetInstance();
	m_pTileManager = CTileManager::GetInstance();
	m_pTileManager->InitManager();

	// TODO : Register Class Types through the ObjectFactory HERE
	m_pOF->RegisterClassType<CBase>("CBase");
	m_pOF->RegisterClassType<CStunShot>("CStunShot");
	m_pOF->RegisterClassType<CBullet>("CBullet");

	CPlayer::GetInstance()->ResetPlayer();

	CPlayer::GetInstance()->SetPosX(300.0f);
	CPlayer::GetInstance()->SetPosY(300.0f);
	CPlayer::GetInstance()->SetVelY(100.0f);


	m_pOM->AddObject(CPlayer::GetInstance());

	CTurret* pTurret = new CTurret();

	pTurret->SetPosX(100.0f);
	pTurret->SetPosY(480.0f);

	m_pOM->AddObject(pTurret);

	SAFE_RELEASE(pTurret);

	CHackOrb* pHackOrb = new CHackOrb();

	pHackOrb->SetPosX(924.0f);
	pHackOrb->SetPosY(416.0f);

	m_pOM->AddObject(pHackOrb);

	SAFE_RELEASE(pHackOrb);

	CDoor* pDoor = new CDoor();

	pDoor->SetPosX(860.0f);
	pDoor->SetPosY(416.0f);

	m_pOM->AddObject(pDoor);

	SAFE_RELEASE(pDoor);

	CHackStation* pHackStation = new CHackStation();

	pHackStation->SetPosX(200.0f);
	pHackStation->SetPosY(480.0f);

	m_pOM->AddObject(pHackStation);

	SAFE_RELEASE(pHackStation);

	m_pWM->SetVolume(m_nSoundID,pGame->GetBGMVolume());
	m_pWM->SetPan(m_nSoundID,pGame->GetRightPan() * 2 - 100);
	m_pWM->Play(m_nSoundID, DSBPLAY_LOOPING);
}

void CGamePlayState::Exit(void)
{
	//m_pTM->UnloadTexture(m_nBackgroundID);
	m_pWM->Stop(m_nSoundID);
	m_pWM->UnloadWave(m_nSoundID);

	// TODO : Unregister Class Types from the ObjectFactory HERE!
	
	m_pOM->RemoveAllObjects();

	if(m_pOF)
	{
		m_pOF->ShutdownObjectFactory();
		m_pOF = NULL;
	}
	if(m_pTileManager)
	{
		m_pTileManager->ReleaseManager();
		m_pTileManager = NULL;
	}
		
	m_pOM->DeleteInstance();
}

// split up Execute() into the 3 main steps of a game
bool CGamePlayState::Input(void)
{
	char cKeyPressed = m_pDI->CheckBufferedKeysEx();

	if(cKeyPressed)
		m_szCheatSequence.push_back(cKeyPressed);

	if (strstr(m_szCheatSequence.c_str(),m_pGodMode))
	{
		//TODO: Implement Godmode

		m_szCheatSequence.clear();
	}

	if (strstr(m_szCheatSequence.c_str(),m_pLevelUp))
	{
		//TODO: Implement Level Up

		m_szCheatSequence.clear();
	}

	if (strstr(m_szCheatSequence.c_str(),m_pBigBang))
	{
		//TODO: Implement Big Bang

		m_szCheatSequence.clear();
	}

	if (m_szCheatSequence.size() > 7 )
		m_szCheatSequence.erase(m_szCheatSequence.begin());

	if(m_pDI->KeyPressed(DIK_ESCAPE) || CSGD_DirectInput::GetInstance()->JoystickButtonPressed(DIR_START,0))
	{
		pGame->PushState(CPausedState::GetInstance());
	}

	return true;
}

void CGamePlayState::Update(float fElapsedTime)
{
	m_pOM->UpdateObjects(fElapsedTime);
	m_pOM->CheckCollisions();
	m_pTileManager->Update(CPlayer::GetInstance());
	CMessageManager::GetInstance()->ProcessMessages();
	CSGD_EventSystem::GetInstance()->ProcessEvents();
}

void CGamePlayState::Render(void)
{
	//TODO:
	//m_pTM->Draw(m_nBackgroundID, 0, 0, 1.25f, 1.0f);
	//m_pOM->SortObjects();
	m_pOM->RenderObjects();
	m_pTileManager->Render();
	
	//char buffer[128];
	//sprintf_s(buffer, _countof(buffer), "W00T");
	//CFontManager::GetInstance()->Draw(buffer, 30, 10, 0.4f, 0.4f);
}