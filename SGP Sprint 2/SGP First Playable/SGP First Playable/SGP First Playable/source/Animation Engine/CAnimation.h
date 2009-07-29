#pragma once
#include "CAnimationManager.h"
#include <string>
using namespace std;
#define MAX_FRAMES

struct CAnimation
{
	string m_szAnimName;
	bool m_bIsLooping;
	CFrame m_Frames[30];
};
