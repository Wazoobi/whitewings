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

enum eMsgTypes { MSG_NULL = 0, MSG_CREATE_STUNSHOT, MSG_DESTROY_STUNSHOT, MSG_MAX };

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