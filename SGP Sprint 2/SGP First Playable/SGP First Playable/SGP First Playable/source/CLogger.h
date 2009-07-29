//////////////////////////////////////////////////////////////////////////
//	File Name	:	"CLogger.h"
//
//	Author		:	Juno Madden (JM)
//
//	Purpose		:	To encapsulate all for logging errors and 
//					using a high performance timer to track 
//					gameplay data.
//////////////////////////////////////////////////////////////////////////

#pragma once
#include <string>
using std::string;
#include <vector>
using std::vector;

class CLogger 
{
	double		m_dTimestamp;
	double		m_dAverageTime;
	int			m_nNumberOfTimesFunctionCalled;
	string		m_szFunctionName;
	vector<double>	m_vTimes;


	CLogger(const CLogger& );
	CLogger& operator=(const CLogger& );

public:

	CLogger(string szFunctionName);
	~CLogger(void);

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Log Error
	//
	//	Purpose		:	Writes errors to a log.
	//////////////////////////////////////////////////////////////////////////
	//void LogError(const string _data);

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Get Instance
	//
	//	Purpose		:	Starts the performance timer check.
	//////////////////////////////////////////////////////////////////////////
	void BeginPerformance(void);

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Get Instance
	//
	//	Purpose		:	Stops the performance timer and writes the 
	//					results to a file.
	//////////////////////////////////////////////////////////////////////////
	void EndPerformance();
};