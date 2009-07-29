#pragma once

#include "CBase.h"

class CHackStation : public CBase
{

	int m_nImageID;

	unsigned int m_uiHackType;

	int m_nTerminalSignature;

public:
	enum {DOOR, REPAIR, LEVEL};

	CHackStation();
	~CHackStation();

	inline int GetTerminalSignature() const	{return m_nTerminalSignature;}

	void SetTerminalSignature(int nTerminalSignature)	{m_nTerminalSignature = nTerminalSignature;}

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