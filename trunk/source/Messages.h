//////////////////////////////////////////////////////////////////////////
//	File Name	:	"Messages.h"
//
//	Author		:	Juno Madden (JM)
//
//	Purpose		:	To encapsulate and define all messages used in the
//					message system.
//////////////////////////////////////////////////////////////////////////

#pragma once

typedef int MSGID;

class CPlayer;
class CStunShot;
class CHackOrb;
class CBase;
class CBullet;

enum eMsgTypes { MSG_NULL = 0, MSG_CREATE_STUNSHOT, MSG_DESTROY_STUNSHOT, MSG_DESTROY_HACKORB, MSG_CREATE_BULLET, MSG_DESTROY_BULLET, MSG_MAX };

class CBaseMessage
{
private:
	MSGID	m_msgID;

public:
	CBaseMessage(MSGID msgID)
	{
		m_msgID = msgID;
	}

	virtual ~CBaseMessage(void) {}

	MSGID GetMsgID(void)	{ return m_msgID; }
};

class CCreateStunShotMessage : public CBaseMessage
{

	// TODO: Change to compensate for singleton
	CPlayer*	m_pPlayer;

public:
	CCreateStunShotMessage(CPlayer* _pPlayer);
	~CCreateStunShotMessage();

	CPlayer* GetPlayer()	{return m_pPlayer;}
};

class CDestroyStunShotMessage : public CBaseMessage
{
private:
	CStunShot*	m_pStunShot;

public:
	CDestroyStunShotMessage(CStunShot* _pStunShot);
	~CDestroyStunShotMessage();

	CStunShot* GetStunShotToDestroy() {return m_pStunShot;}

};

class CDestroyHackOrbMessage : public CBaseMessage
{
private:
	CHackOrb*	m_pHackOrb;

public:
	CDestroyHackOrbMessage(CHackOrb* _pHackOrb);
	~CDestroyHackOrbMessage();

	CHackOrb* GetHackOrbToDestroy()	{return m_pHackOrb;}
};

class CCreateBulletMessage : public CBaseMessage
{

	// TODO: Change to compensate for singleton
	CBase*	m_pOwner;

public:
	CCreateBulletMessage(CBase* _pOwner);
	~CCreateBulletMessage();

	CBase* GetOwner()	{return m_pOwner;}
};

class CDestroyBulletMessage : public CBaseMessage
{
private:
	CBullet*	m_pBullet;

public:
	CDestroyBulletMessage(CBullet* _pBullet);
	~CDestroyBulletMessage();

	CBullet* GetBulletToDestroy() {return m_pBullet;}

};