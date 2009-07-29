#pragma once
#include "CBase.h"
#include "IListener.h"

class CDoor : public CBase, public IListener
{
	bool m_bIsLocked;

	int m_nImageID;

	int m_nDoorSignature;

public:

	CDoor(void);
	~CDoor(void);

	inline bool GetIsLocked() const		{return m_bIsLocked;}

	void SetIsLocked(bool bIsLocked)	{m_bIsLocked = bIsLocked;}


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

	void HandleEvent(CEvent* pEvent);
};
