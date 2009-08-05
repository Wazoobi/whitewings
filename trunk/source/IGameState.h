#pragma once

#include "CFontManager.h"


enum {MAINMENU, GAME, HACKING, OPTIONS, PAUSED, HOWTOPLAY, CREDITS, WIN, LOSE, OTHER};

class IGameState
{
	unsigned int m_uiStateType;

public:

	inline unsigned int GetStateType(void) const	{return m_uiStateType;}

	void SetStateType(unsigned int uiStateType)		{m_uiStateType = uiStateType;}

	virtual ~IGameState(void) = 0 {}
	virtual void Enter(void) = 0;
	virtual void Exit(void) = 0;
	// split up Execute() into the 3 main steps of a game
	virtual bool Input(void) = 0;
	virtual void Update(float fElapsedTime) = 0;
	virtual void Render(void) = 0;
};5