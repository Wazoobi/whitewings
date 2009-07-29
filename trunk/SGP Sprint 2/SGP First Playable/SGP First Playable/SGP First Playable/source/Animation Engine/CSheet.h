#pragma once

#include "CAnimationManager.h"
#define MAX_ANIMATIONS 50

struct CSheet
{
	CAnimation m_Animations[MAX_ANIMATIONS];
	string m_szFileName;
	int m_nImageID;
	~CSheet();
};