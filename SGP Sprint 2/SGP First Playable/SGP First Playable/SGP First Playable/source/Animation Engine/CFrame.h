#pragma once

#include "CAnimationManager.h"
#include <Windef.h>
#define MAX_TRIGGERS 10

struct CFrame
{
	RECT m_RImageRect, m_RCollisionRect, m_RAttackRect;
	short m_shAnchorX, m_shAnchorY, m_shWeaponX, m_shWeaponY;
	float m_fDuration;
	CTrigger m_Triggers[MAX_TRIGGERS];
};