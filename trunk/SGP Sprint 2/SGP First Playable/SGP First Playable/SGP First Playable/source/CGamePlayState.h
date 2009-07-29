//////////////////////////////////////////////////////////////////////////
//	File Name	:	"CGamePlayState.h"
//
//	Author		:	Juno Madden (JM)
//
//	Purpose		:	To encapsulate all gameplay code.
//////////////////////////////////////////////////////////////////////////

#pragma once
#include "IGameState.h"
#include "CGame.h"
#include "SGD Wrappers/CSGD_Direct3D.h"
#include "SGD Wrappers/CSGD_TextureManager.h"
#include "SGD Wrappers/CSGD_DirectSound.h"
#include "SGD Wrappers/CSGD_WaveManager.h"
#include "SGD Wrappers/CSGD_DirectInput.h"
#include "CSGD_ObjectFactory.h"
#include "CObjectManager.h"

#include "CTileManager.h"

#include <string>
#include "CBase.h"
using std::string;

class CCity;
class CAimer;
class CTurret;

class CGamePlayState : public IGameState
{
	CSGD_Direct3D							*m_pD3D;
	CSGD_TextureManager						*m_pTM;
	CSGD_DirectSound						*m_pDS;
	CSGD_WaveManager						*m_pWM;
	CSGD_DirectInput						*m_pDI;
	CSGD_ObjectFactory<string, CBase>		*m_pOF;
	CObjectManager							*m_pOM;

	CTileManager							*m_pTileManager;

	CGame *pGame;

	string m_szCheatSequence;
	char* m_pLevelUp;
	char* m_pGodMode;
	char* m_pBigBang;

	int m_nBackgroundID;
	int m_nSoundID;

	CGamePlayState(void);
	~CGamePlayState(void);
	CGamePlayState(const CGamePlayState& );
	CGamePlayState& operator=(const CGamePlayState& );

public:

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Get Instance
	//
	//	Purpose		:	Grants global access to the singleton.
	//////////////////////////////////////////////////////////////////////////
	static CGamePlayState* GetInstance(void);

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Accessors
	//
	//	Purpose		:	To get the specified type
	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Enter
	//
	//	Purpose		:	Enters into the state.
	//////////////////////////////////////////////////////////////////////////
	void Enter(void);

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Exit
	//
	//	Purpose		:	Leaves the state.
	//////////////////////////////////////////////////////////////////////////
	void Exit(void);

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Input
	//
	//	Purpose		:	Takes in input.
	//////////////////////////////////////////////////////////////////////////
	bool Input(void);

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Updates
	//
	//	Purpose		:	Updates data members based on time.
	//////////////////////////////////////////////////////////////////////////
	void Update(float fElapsedTime);

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Render
	//
	//	Purpose		:	Draws to the screen.
	//////////////////////////////////////////////////////////////////////////
	void Render(void);
};