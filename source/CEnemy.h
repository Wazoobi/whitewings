#pragma once

#include "CBase.h"


enum {PATROL, CHASE, ATTACK, STUNNED, HACKED, ALERT};

#define ALERT_TIME 10.0f
#define STUN_DURATION 3.0f

class CEnemy : public CBase
{
protected:
	unsigned int m_uiState;			// Used for state driven AI
	unsigned int m_uiEnemyType;		// Used for Hacking powers on the player's side
	int m_nDetectionRange;				// The distance the player must be within to cause the enemy to go into CHASE state
	float m_fStunnedTimer;
	float m_fAlertTimer;

public:
	enum {WALKER, JUMPER, FLYER, TURRET};

	CEnemy();
	virtual ~CEnemy();

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Accessors
	//
	//	Purpose		:	To get the specified type
	//////////////////////////////////////////////////////////////////////////
	inline unsigned int GetState() const			{return m_uiState;}
	inline unsigned int GetEnemyType() const		{return m_uiEnemyType;}
	inline int GetDetectionRange() const			{return m_nDetectionRange;}

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Modifiers
	//
	//	Purpose		:	To set the specified type
	//////////////////////////////////////////////////////////////////////////
	void SetState(unsigned int uiState)				{m_uiState = uiState;}
	void SetEnemyType(unsigned int uiEnemyType)		{m_uiEnemyType = uiEnemyType;}
	void SetDetectionRange(int nDetectionRange)		{m_nDetectionRange = nDetectionRange;}

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Checks for collision
	//
	//	Purpose		:	Returns true if there is a collision
	//////////////////////////////////////////////////////////////////////////
	virtual bool CheckCollision(CBase* pBase);

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Updates
	//
	//	Purpose		:	Updates data members based on time.
	//////////////////////////////////////////////////////////////////////////
	virtual void Update(float fElapsedTime);

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Render
	//
	//	Purpose		:	Draws to the screen.
	//////////////////////////////////////////////////////////////////////////
	virtual void Render(void);
};