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

	// TODO : Register Class Types through the ObjectFactory HERE

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
	CMessageManager::GetInstance()->ProcessMessages();
	CSGD_EventSystem::GetInstance()->ProcessEvents();
}

void CGamePlayState::Render(void)
{
	//TODO:
	//m_pTM->Draw(m_nBackgroundID, 0, 0, 1.25f, 1.0f);
	m_pOM->SortObjects();
	m_pOM->RenderObjects();
	
	//char buffer[128];
	//sprintf_s(buffer, _countof(buffer), "W00T");
	//CFontManager::GetInstance()->Draw(buffer, 30, 10, 0.4f, 0.4f);
}