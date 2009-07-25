#pragma once

#include "CBase.h"

class CSGD_DirectInput;

#define SHOT_DELAY 3.0f

class CPlayer : public CBase
{
	float	m_fStunGunTimer;
	bool	m_bStunGunReady;
	bool	m_bEnemyHacked;
	float	m_fDashTimer;
	bool	m_bIsDashing;
	bool	m_bIsJumping;
	int		m_nHealth;
	int		m_nHackOrbs;
	int		m_nDirection;	// 0 is Left. 1 is Right.
	int		m_nImageID;


	CPlayer();
	~CPlayer();
	CPlayer(const CPlayer&);
	CPlayer& operator=(const CPlayer&);

public:

	static CPlayer* GetInstance();

	inline int GetDirection() const	{return m_nDirection;}

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Checks for collision
	//
	//	Purpose		:	Returns true if there is a collision
	//////////////////////////////////////////////////////////////////////////
	bool CheckCollision(CBase* pBase);

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