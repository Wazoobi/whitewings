//////////////////////////////////////////////////////////////////////////
//	File Name	:	"CHowToPlayState.h"
//
//	Author		:	Juno Madden (JM)
//
//	Purpose		:	To encapsulate all code for the instruction screen.
//////////////////////////////////////////////////////////////////////////

#pragma once

#include "IGameState.h"
#include "CGame.h"
#include "SGD Wrappers/CSGD_Direct3D.h"
#include "SGD Wrappers/CSGD_TextureManager.h"
#include "SGD Wrappers/CSGD_DirectInput.h"
#include "CFontManager.h"

class CHowToPlayState : public IGameState
{
	CSGD_Direct3D			*m_pD3D;
	CSGD_TextureManager		*m_pTM;
	CSGD_DirectInput		*m_pDI;
	CFontManager			*m_pFM;

	CGame					*pGame;

	int m_nBackgroundID;
	int m_nPlayerID;
	int m_nWalkerID;
	int m_nHackOrbID;
	int m_nJumperID;
	int m_nFlyerID;
	int m_nTerminalID;
	int m_nDoorID;

	bool m_bFirstTime;
	float m_fFirstTimeTimer;

	CHowToPlayState(void);
	~CHowToPlayState(void);
	CHowToPlayState(const CHowToPlayState& );
	CHowToPlayState& operator=(const CHowToPlayState& );

public:

	inline bool GetFirstTime(void) const {return m_bFirstTime;}

	void SetFirstTime(bool bFirstTime) {m_bFirstTime = bFirstTime;}

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Get Instance
	//
	//	Purpose		:	Grants global access to the singleton.
	//////////////////////////////////////////////////////////////////////////
	static CHowToPlayState* GetInstance(void);

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