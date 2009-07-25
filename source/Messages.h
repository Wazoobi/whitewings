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

enum eMsgTypes { MSG_NULL = 0, MSG_MAX };

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