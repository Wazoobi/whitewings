//////////////////////////////////////////////////////////////////////////
//	File Name	:	"CGame.h"
//
//	Author		:	Juno Madden (JM)
//
//	Purpose		:	To encapsulate all game related code.
//////////////////////////////////////////////////////////////////////////

#include "CGame.h"
#include "IGameState.h"
#include "CMainMenuState.h"
#include "CMessageManager.h"
#include "CSGD_ObjectFactory.h"
#include "CObjectManager.h"
#include "CSGD_EventSystem.h"
#include "CGamePlayState.h"
#include "CLogger.h"
#include <string>
#include <iterator>
using std::iterator;

#include "SGD Wrappers/SGD_Math.h"
#include <fstream>

#include "CStunShot.h"
#include "CPlayer.h"

using std::string;

// Proper Singleton
// Constructor
CGame::CGame(void)
{
	m_pD3D = NULL;
	m_pTM = NULL;
	m_pDS = NULL;
	m_pWM = NULL;
	m_pDI = NULL;
	m_pMM = NULL;


	m_nBGMVolume = 100;
	m_nSFXVolume = 100;
	m_nLeftPan = 50;
	m_nRightPan = 50;
}

//	Destructor
CGame::~CGame(void)
{

}

CGame* CGame::GetInstance(void)
{
	// Lazy Instantiation
	static CGame instance;
	return &instance;
}

// 3 steps a game goes through in it's lifetime:
//  1. Initialization
void CGame::Initialize(HWND hWnd, HINSTANCE hInstance, int nScreenWidth, int nScreenHeight, bool bIsWindowed)
{
	// Get pointers to the SGD singletons
	m_pD3D = CSGD_Direct3D::GetInstance();
	m_pTM = CSGD_TextureManager::GetInstance();
	m_pDS = CSGD_DirectSound::GetInstance();
	m_pWM = CSGD_WaveManager::GetInstance();
	m_pDI = CSGD_DirectInput::GetInstance();
	m_pMM = CMessageManager::GetInstance();

	m_nScreenWidth = nScreenWidth;
	m_nScreenHeight = nScreenHeight;
	m_bIsWindowed = bIsWindowed;

	std::ifstream input("resource/data/options.txt");

	if(!input.is_open())
	{
		CLogger::GetInstance()->LogError("Failed to obtain options.");
	}
	else
	{
		input >> m_nBGMVolume;
		input >> m_nSFXVolume;
		input >> m_nLeftPan;
		input >> m_nRightPan;
	}

	// Initialize SGD singletons
	m_pD3D->InitDirect3D(hWnd, nScreenWidth, nScreenHeight, bIsWindowed, false);
	m_pTM->InitTextureManager(m_pD3D->GetDirect3DDevice(), m_pD3D->GetSprite());
	m_pDS->InitDirectSound(hWnd);
	m_pWM->InitWaveManager(hWnd, m_pDS->GetDSObject());
	m_pDI->InitDirectInput(hWnd, hInstance, DI_KEYBOARD | DI_MOUSE | DI_JOYSTICKS);
	m_pMM->InitMessageSystem(MessageProc);

	PushState(CMainMenuState::GetInstance());

	m_dwPreviousTime = GetTickCount();
	timer.Reset();
}

//  3. Clean up
void CGame::Shutdown(void)
{
	ClearStates();

	std::fstream output;

	output.open("resource/data/options.txt");

	if(!output.is_open())
	{
		CLogger::GetInstance()->LogError("Failed to save game options.");
	}
	else
	{
		output << m_nBGMVolume << ' ';
		output << m_nSFXVolume << ' ';
		output << m_nLeftPan << ' ';
		output << m_nRightPan << ' ';
	}
	output.close();

	// Shutdown in the opposite order we acquired

	if(m_pMM)
	{
		m_pMM->ShutdownMessageSystem();
		m_pMM = NULL;
	}
	if(m_pDI)
	{
		m_pDI->ShutdownDirectInput();
		m_pDI = NULL;
	}

	if(m_pWM)
	{
		m_pWM->ShutdownWaveManager();
		m_pWM = NULL;
	}

	if(m_pDS)
	{
		m_pDS->ShutdownDirectSound();
		m_pDS = NULL;
	}

	if(m_pTM)
	{
		m_pTM->ShutdownTextureManager();
		m_pTM = NULL;
	}

	if(m_pD3D)
	{
		m_pD3D->ShutdownDirect3D();
		m_pD3D = NULL;
	}
}

//  2. Execution
bool CGame::Main(void)
{
	DWORD dwCurrentTick = GetTickCount();
	m_fElapsedTime = (float)(dwCurrentTick - m_dwPreviousTime)/1000.0f;
	m_dwPreviousTime = dwCurrentTick;

	// 3 Steps a game goes through during execution
	// 1. Input
	if(!Input())
		return false;

	// 2. Update
	Update();

	// 3. Render
	Render();

	return true;
}

bool CGame::Input(void)
{
	m_pDI->ReadDevices();
	// Let the user toggle the window mode
	if ((m_pDI->KeyDown(DIK_LMENU) || m_pDI->KeyDown(DIK_RMENU)) && m_pDI->KeyPressed(DIK_RETURN))
	{
		m_bIsWindowed = !m_bIsWindowed;
		m_pD3D->ChangeDisplayParam(m_nScreenWidth, m_nScreenHeight, m_bIsWindowed);
		return true;
	}
	return gameStates.back()->Input();
}

void CGame::Update(void)
{
	gameStates.back()->Update(m_fElapsedTime);

	if(gameStates.back()->GetStateType() == HACKING)
		gameStates[gameStates.size()-2]->Update(m_fElapsedTime);

	m_pWM->Update();
	timer.Update();
}

void CGame::Render(void)
{
	m_pD3D->Clear(0, 0, 128);
	m_pD3D->DeviceBegin();  // Set up for 3D rendering
	m_pD3D->SpriteBegin();  // Need for 2D rendering
	
	for(int i = 0; i < gameStates.size(); ++i)
		gameStates[i]->Render();

	m_pD3D->SpriteEnd();
	m_pD3D->DeviceEnd();
	m_pD3D->Present();			
}

void CGame::PushState(IGameState *currentState)
{
	gameStates.push_back(currentState);
	currentState->Enter();
}

void CGame::PopState()
{
	gameStates.back()->Exit();
	gameStates.pop_back();
}

void CGame::ClearStates()
{
	for(int i = 0; i < gameStates.size(); ++i)
	{
		gameStates.back()->Exit();
		gameStates.pop_back();
	}
}

void MessageProc(CBaseMessage* message)
{
	switch(message->GetMsgID())
	{
	case MSG_CREATE_STUNSHOT:
		{
			CCreateStunShotMessage *msg = (CCreateStunShotMessage*)message;

			CStunShot* pStunShot = (CStunShot*)CSGD_ObjectFactory<string, CBase>::GetInstance()->CreateObject("CStunShot");

			pStunShot->SetOwner((CBase*)msg->GetPlayer());

			pStunShot->SetPosX(pStunShot->GetOwner()->GetPosX());
			pStunShot->SetPosY(pStunShot->GetOwner()->GetPosY());

			if (msg->GetPlayer()->GetDirection() == 0)
				pStunShot->SetVelX(-200.0f - pStunShot->GetOwner()->GetVelX());
			else
				pStunShot->SetVelX(200.0f + pStunShot->GetOwner()->GetVelX());

			CObjectManager::GetInstance()->AddObject(pStunShot);
			SAFE_RELEASE(pStunShot);

			break;
		}
	case MSG_DESTROY_STUNSHOT:
		{
			CDestroyStunShotMessage *msg = (CDestroyStunShotMessage*)message;
			CObjectManager::GetInstance()->RemoveObject(msg->GetStunShotToDestroy());

			break;
		}
	case MSG_DESTROY_HACKORB:
		{
			CDestroyHackOrbMessage *msg = (CDestroyHackOrbMessage*)message;

			// TODO: Figure out why I had to cast the HackOrb into CBase*
			CObjectManager::GetInstance()->RemoveObject((CBase*)msg->GetHackOrbToDestroy());
			break;
		}
	default:
		break;
	}
}