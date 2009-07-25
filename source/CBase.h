#pragma once
#include "IBaseInterface.h"

class CBase : public IBaseInterface
{
	float m_fPosX;
	float m_fPosY;
	float m_fVelX;
	float m_fVelY;

	// TODO: Set up animation stuffs

protected:
	int m_nDisplayDepth;
	unsigned int m_uiType;
	unsigned int m_uiRefCount;

public:
	enum { OBJ_BASE, OBJ_ENEMY, OBJ_BULLET, OBJ_STUNSHOT, OBJ_PLAYER, OBJ_HACKORB, OBJ_HACKSTATION };

	CBase(void);
	virtual ~CBase(void);

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Accessors
	//
	//	Purpose		:	To get the specified type
	//////////////////////////////////////////////////////////////////////////
	inline float GetPosX(void) const		{return m_fPosX;}
	inline float GetPosY(void) const		{return m_fPosY;}
	inline float GetVelX(void) const		{return m_fVelX;}
	inline float GetVelY(void) const		{return m_fVelY;}
	inline int GetDepth(void) const			{return m_nDisplayDepth;}
	// TODO: Accessor for Animation Instance

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Modifiers
	//
	//	Purpose		:	To set the specified type
	//////////////////////////////////////////////////////////////////////////
	void SetPosX(float fPosX)				{m_fPosX = fPosX;}
	void SetPosY(float fPosY)				{m_fPosY = fPosY;}
	void SetVelX(float fVelX)				{m_fVelX = fVelX;}
	void SetVelY(float fVelY)				{m_fVelY = fVelY;}
	// TODO: Mutator for Animation Instance

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

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Add Reference
	//
	//	Purpose		:	Increments the number of pointers pointing
	//					to this object.
	//////////////////////////////////////////////////////////////////////////
	void AddRef(void)
	{
		m_uiRefCount++;
	}

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Release Reference
	//	
	//	Purpose		:	Decrements the number of pointers pointing
	//					to this object. If there are no more references,
	//					the object is deleted.
	//////////////////////////////////////////////////////////////////////////
	void Release(void)
	{
		m_uiRefCount--;

		if(m_uiRefCount == 0)
			delete this;
	}
};
