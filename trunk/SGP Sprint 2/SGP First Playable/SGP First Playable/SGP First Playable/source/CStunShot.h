#pragma once

#include "CProjectile.h"

class CStunShot : public CProjectile
{

	float m_fLife;
	float m_fLifeTimer;

	int m_nImageID;

public:
	CStunShot();
	~CStunShot();

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