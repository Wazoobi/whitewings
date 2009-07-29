////////////////////////////////////////////////////////////////////
//	File Name	:	"CAnimationManager.h"
//
//	Author		:	Ryan Snow (RS)
//
//	Purpose		:	To encapsulate all animation related code
////////////////////////////////////////////////////////////////////

#pragma once

#include "../../source/SGD Wrappers/CSGD_TextureManager.h"
#include <string>
using std::string;

#include "CTrigger.h"
#include "CFrame.h"
#include "CAnimation.h"
#include "CSheet.h"
#include "CAnimationInstance.h"
#define MAX_SHEETS 50
class CAnimationManager
{
public:
	
	

private:
	CSheet m_Sheets[MAX_SHEETS];
	int m_nNumSheets;
	~CAnimationManager(void);
	CAnimationManager(const CAnimationManager&);
	CAnimationManager& operator=(const CAnimationManager&);

public:

	CAnimationManager(void);
	static CAnimationManager* GetInstance(void);
	void LoadSheet(string szFilename);
	CAnimationInstance& Animate(CAnimationInstance key);
	CAnimationInstance& ChangeAnimation(CAnimationInstance key, string szAnimationName);
	CAnimationInstance& SetAnimationInstance(string szSheetFileName, string szAnimationName); 

	CSheet& GetSheet(int index)				{return m_Sheets[index];}
	void SetSheet(int index, CSheet& sheet)	{m_Sheets[index] = sheet;}
};