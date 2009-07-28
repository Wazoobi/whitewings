//////////////////////////////////////////////////////////////////////////
//	File Name	:	"CHackingState.h"
//
//	Author		:	Juno Madden (JM)
//
//	Purpose		:	To encapsulate all code for the hacking mini-games.
//////////////////////////////////////////////////////////////////////////

#pragma once

#include "IGameState.h"
#include "CGame.h"
#include "SGD Wrappers/CSGD_Direct3D.h"
#include "SGD Wrappers/CSGD_TextureManager.h"
#include "SGD Wrappers/CSGD_DirectInput.h"
#include "CFontManager.h"

class CPlayer;

class CHackingState : public IGameState
{
	CSGD_Direct3D			*m_pD3D;
	CSGD_TextureManager		*m_pTM;
	CSGD_DirectInput		*m_pDI;
	CFontManager			*m_pFM;

	CGame					*pGame;

	int						m_nBackgroundID;

	int						m_nTerminalSignature;
	
	// Avatar Members
	int		nAvatarImageID;
	float	fPosX;
	float	fPosY;
	float	fVelX;
	float	fVelY;
	int		nWidth;
	int		nHeight;

	CHackingState(void);
	~CHackingState(void);
	CHackingState(const CHackingState& );
	CHackingState& operator=(const CHackingState& );

public:

	inline int GetTerminalSignature() const	{return m_nTerminalSignature;}

	void SetTerminalSignature(int nTerminalSignature)	{m_nTerminalSignature = nTerminalSignature;}

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Get Instance
	//
	//	Purpose		:	Grants global access to the singleton.
	//////////////////////////////////////////////////////////////////////////
	static CHackingState* GetInstance(void);

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