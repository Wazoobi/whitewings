#include "CLogger.h"
#include <fstream>
#include "CGame.h"
#include <time.h>
using std::ofstream;

CLogger::CLogger(void)
{
	m_dTimestamp = 0.0f;
}

CLogger::~CLogger(void)
{

}

CLogger* CLogger::GetInstance(void)
{
	static CLogger Instance;
	return &Instance;
}

void CLogger::LogError(const string _data)
{
	tm when;
	char buffer[80];
	__time64_t now;

	time( &now );
	_localtime64_s( &when, &now );
	asctime_s( buffer, sizeof(buffer), &when );

	ofstream output("resource/data/log.txt", std::ios_base::app);

	if(!output.is_open())
		return ;

	output << buffer << _data << '\n' << '\n';

	output.clear();
	output.close();
}

void CLogger::BeginPerformance(void)
{
	m_dTimestamp = CGame::GetInstance()->GetTimer()->GetTime();
}

void CLogger::EndPerformance(const string _data)
{
	m_dTimestamp = CGame::GetInstance()->GetTimer()->GetTime() - m_dTimestamp;

	tm when;
	char buffer[80];
	__time64_t now;

	time( &now );
	_localtime64_s( &when, &now );
	asctime_s( buffer, sizeof(buffer), &when );

	ofstream output("resource/data/performance.txt", std::ios_base::app);

	if(!output.is_open())
		return ;
	
	output << buffer << _data << " - time in seconds: " << m_dTimestamp << '\n' << '\n';

	output.clear();
	output.close();
}