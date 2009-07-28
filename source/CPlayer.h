#pragma once

#include "CBase.h"

class CSGD_DirectInput;
class CEnemy;

#define SHOT_DELAY 3.0f

class CPlayer : public CBase
{
	float	m_fStunGunTimer;
	bool	m_bStunGunReady;
	bool	m_bEnemyHacked;
	float	m_fDashTimer;
	bool	m_bIsDashing;
	bool	m_bIsJumping;
	
	bool	m_bIsHackingTerminal;
	bool	m_bTouchingTerminal;

	bool	m_bIsHacking;
	CEnemy *m_pCurrentlyHackedEnemy;

	int		m_nHealth;
	int		m_nHackOrbs;
	int		m_nDirection;	// 0 is Left. 1 is Right.
	
	int		m_nImageID;
	int		m_nHackableImageID;
	bool	m_bDrawHackableImage;

	float	m_fGravity;
	float	m_fGravityTimer;

	int		m_nCollisionType;	// 0 = no collision, 1 = collision on right, 2 = collision on left, 3 = collision from above, 4 = collision from below

	float	m_fInvulnerableTimer;
	bool	m_bIsInvulnerable;


	CPlayer();
	~CPlayer();
	CPlayer(const CPlayer&);
	CPlayer& operator=(const CPlayer&);

public:

	static CPlayer* GetInstance();

	inline int GetDirection() const	{return m_nDirection;}
	inline int GetHackOrbs() const	{return m_nHackOrbs;}
	inline int GetHealth() const	{return m_nHealth;}
	inline bool GetInvulnerable() const	{return m_bIsInvulnerable;}
	inline bool GetIsJumping() const	{return m_bIsJumping;}

	void SetHackOrbs(int nHackOrbs)	{m_nHackOrbs = nHackOrbs;}
	void SetHealth(int nHealth)		{m_nHealth = nHealth;}
	void SetInvulnerable(bool bInvulnerable)	{m_bIsInvulnerable = bInvulnerable;}
	void SetIsJumping(bool bIsJumping)			{m_bIsJumping = bIsJumping;}


	void ResetPlayer();

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