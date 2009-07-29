#include "CLogger.h"
#include <fstream>
#include "CGame.h"
#include <time.h>
using std::ofstream;

CLogger::CLogger(string szFunctionName)
{
	m_dTimestamp = 0.0;
	m_dAverageTime = 0.0;
	m_nNumberOfTimesFunctionCalled = 0;
	m_szFunctionName = szFunctionName;
}

CLogger::~CLogger(void)
{

	tm when;
	char buffer[80];
	__time64_t now;

	time( &now );
	_localtime64_s( &when, &now );
	asctime_s( buffer, sizeof(buffer), &when );

	ofstream output("resource/data/ww_performance.csv", std::ios_base::app);

	if(!output.is_open())
		return ;

	output << buffer << ',' << m_szFunctionName << "\n\n";

	double dTotalTime = 0.0;

	for(int i = 0; i < m_nNumberOfTimesFunctionCalled; ++i)
	{
		dTotalTime += m_vTimes[0];
		output << i + 1 << ",- time in seconds:," << m_vTimes[i] << '\n';
	}

	output << "\nTotal Time:," << dTotalTime << ",Total function calls:," << m_nNumberOfTimesFunctionCalled << 
		",Average Time Per Call:," << dTotalTime/(double)m_nNumberOfTimesFunctionCalled << "\n\n";

	output.clear();
	output.close();

// 	tm when;
// 	char buffer[80];
// 	__time64_t now;
// 
// 	time( &now );
// 	_localtime64_s( &when, &now );
// 	asctime_s( buffer, sizeof(buffer), &when );
// 
// 	ofstream output("resource/data/ww_performance.txt", std::ios_base::app);
// 
// 	if(!output.is_open())
// 		return ;
// 
// 	output << buffer << m_szFunctionName << "\n\n";
// 	
// 	double dTotalTime = 0.0;
// 
// 	for(int i = 0; i < m_nNumberOfTimesFunctionCalled; ++i)
// 	{
// 		dTotalTime += m_vTimes[0];
// 		output << i + 1 << " - time in seconds: " << m_vTimes[i] << '\n';
// 	}
// 
// 	output << "\nTotal Time:  " << dTotalTime << "    Total function calls:  " << m_nNumberOfTimesFunctionCalled << 
// 		"    Average Time Per Call:  " << dTotalTime/(double)m_nNumberOfTimesFunctionCalled << "\n\n";
// 
// 	output.clear();
// 	output.close();
}

// void CLogger::LogError(const string _data)
// {
// 	tm when;
// 	char buffer[80];
// 	__time64_t now;
// 
// 	time( &now );
// 	_localtime64_s( &when, &now );
// 	asctime_s( buffer, sizeof(buffer), &when );
// 
// 	ofstream output("resource/data/log.txt", std::ios_base::app);
// 
// 	if(!output.is_open())
// 		return ;
// 
// 	output << buffer << _data << '\n' << '\n';
// 
// 	output.clear();
// 	output.close();
// }

void CLogger::BeginPerformance(void)
{
	m_dTimestamp = CGame::GetInstance()->GetTimer()->GetTime();
	m_nNumberOfTimesFunctionCalled++;
}

void CLogger::EndPerformance()
{
	m_dTimestamp = CGame::GetInstance()->GetTimer()->GetTime() - m_dTimestamp;
	m_vTimes.push_back(m_dTimestamp);
}