#pragma once

#include "CFontManager.h"

class IGameState
{
public:
	virtual ~IGameState(void) = 0 {}
	virtual void Enter(void) = 0;
	virtual void Exit(void) = 0;
	// split up Execute() into the 3 main steps of a game
	virtual bool Input(void) = 0;
	virtual void Update(float fElapsedTime) = 0;
	virtual void Render(void) = 0;
};