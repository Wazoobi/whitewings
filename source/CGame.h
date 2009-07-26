//////////////////////////////////////////////////////////////////////////
//	File Name	:	"CGame.h"
//
//	Author		:	Juno Madden (JM)
//
//	Purpose		:	To encapsulate all game related code.
//////////////////////////////////////////////////////////////////////////

// Cross Compiler compatible (works on Borland, Codewarrior)
#ifndef _CGAME_H_
#define _CGAME_H_

// Define game class here
#include "SGD Wrappers/CSGD_Direct3D.h"
#include "SGD Wrappers/CSGD_TextureManager.h"
#include "SGD Wrappers/CSGD_DirectSound.h"
#include "SGD Wrappers/CSGD_WaveManager.h"
#include "SGD Wrappers/CSGD_DirectInput.h"
#include <vector>
using std::vector;

#include "IGameState.h"
#include "Timer.h"

class CBaseMessage;
class CMessageManager;

enum JoystickButtons{DIR_A,DIR_B,DIR_X,DIR_Y,DIR_LBUMP,DIR_RBUMP,DIR_BACK,DIR_START};

class CGame
{
	//	SGD singletons:
	CSGD_Direct3D			*m_pD3D;
	CSGD_TextureManager		*m_pTM;
	CSGD_DirectSound		*m_pDS;
	CSGD_WaveManager		*m_pWM;
	CSGD_DirectInput		*m_pDI;
	CMessageManager			*m_pMM;

	vector<IGameState*>		gameStates;

	Timer timer;


	int m_nBGMVolume;
	int m_nSFXVolume;
	int m_nLeftPan;
	int m_nRightPan;

	int m_nScreenWidth;
	int m_nScreenHeight;
	bool m_bIsWindowed;

	//	For game timing:
	DWORD					m_dwTimeStamp;
	float					m_fElapsedTime;
	DWORD					m_dwPreviousTime;
	float					m_fGameTime;		// Amount of Time game has been running for

	// Utility Functions : 
	bool Input(void);
	void Update(void);
	void Render(void);

	// Proper Singleton
	// Constructor
	CGame(void);

	// Trilogy of Evil :	
	//	Copy Constructor
	CGame(const CGame&);

	//	Assignment Operator
	CGame& operator=(const CGame&);

	//	Destructor
	~CGame(void);

public:

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Get Instance
	//
	//	Purpose		:	Grants global access to the singleton.
	//////////////////////////////////////////////////////////////////////////
	static CGame* GetInstance(void);

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Initialize
	//
	//	Purpose		:	Initializes the game components
	//////////////////////////////////////////////////////////////////////////
	void Initialize(HWND hWnd, HINSTANCE hInstance, int nScreenWidth, int nScreenHeight, bool bIsWindowed);

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Main
	//
	//	Purpose		:	Executes the game
	//////////////////////////////////////////////////////////////////////////
	bool Main(void);
	
	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Shutdown
	//
	//	Purpose		:	Clean up
	//////////////////////////////////////////////////////////////////////////
	void Shutdown(void);

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Accessors
	//
	//	Purpose		:	To get the specified type
	//////////////////////////////////////////////////////////////////////////
	int GetScreenWidth(){ return m_nScreenWidth; }
	int GetScreenHeight() { return m_nScreenHeight; }
	int GetBGMVolume(){ return m_nBGMVolume;}
	int GetSFXVolume(){ return m_nSFXVolume;}
	int GetLeftPan(){ return m_nLeftPan;}
	int GetRightPan(){ return m_nRightPan;}
	Timer* GetTimer() { return &timer;} 

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Modifiers
	//
	//	Purpose		:	To set the specified type
	//////////////////////////////////////////////////////////////////////////
	void SetBGMVolume(int nBGMVolume){ m_nBGMVolume = nBGMVolume;}
	void SetSFXVolume(int nSFXVolume){ m_nSFXVolume = nSFXVolume;}
	void SetLeftPan(int nLeftPan){ m_nLeftPan = nLeftPan;}
	void SetRightPan(int nRightPan){ m_nRightPan = nRightPan;}

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Message Process
	//
	//	Purpose		:	Handles messages
	//////////////////////////////////////////////////////////////////////////
	friend void MessageProc(CBaseMessage* message);

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Push State
	//
	//	Purpose		:	Adds the passed in state to the state stack
	//////////////////////////////////////////////////////////////////////////
	void PushState(IGameState *currentState);

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Pop State
	//
	//	Purpose		:	Removes the top state from the stack
	//////////////////////////////////////////////////////////////////////////
	void PopState();

	void ClearStates();

};


#endif