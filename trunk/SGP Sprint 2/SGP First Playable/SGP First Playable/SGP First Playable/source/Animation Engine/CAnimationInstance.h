#pragma once
#include "CAnimationManager.h"

struct CAnimationInstance
{
	CFrame* m_CurrFrame;
	CAnimation* m_CurrAnimation;
	CSheet* m_CurrSheet;
	RECT m_RCurrCollisionRect;
	float m_fCurrTime;
};