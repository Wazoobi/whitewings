//////////////////////////////////////////////////////////////
//	File Name	:	"CAnimationManager.cpp"
//
//	Author		:	Ryan Snow (RS)
//
//	Purpose		:	To encapsulate all animation related code
///////////////////////////////////////////////////////////////

#include "CAnimationManager.h"
#include "CSheet.h"
#include <iostream>
#include <fstream>
using namespace std;

CAnimationManager::CAnimationManager()
{
	m_nNumSheets = 0;

	LoadSheet("resource/AnimationManagerStuff/PingAnimations2.anim");
	GetSheet(0).m_szFileName = "../Resource/AnimationManagerStuff/Ninja Mega.png";

	LoadSheet("resource/AnimationManagerStuff/WalkerWalk.anim");
	GetSheet(1).m_szFileName = "../Resource/AnimationManagerStuff/RobotSentinel.bmp";

	LoadSheet("resource/AnimationManagerStuff/BeeFlying.anim");
	GetSheet(2).m_szFileName = "../Resource/AnimationManagerStuff/sonicadvance2_enemies.bmp";
}
CAnimationManager::~CAnimationManager()
{
}
CAnimationManager* CAnimationManager::GetInstance()
{
	static CAnimationManager instance;
	return &instance;
}

void CAnimationManager::LoadSheet(string szFilename)
{
	int animCount, frameCount, trigCount;
	char sheetName, animName, triggerName;
	CSheet newSheet;
	ifstream in;
	in.open(szFilename.c_str(), ios::in | ios::binary);

	in.read((char*)&sheetName, sizeof(char));
	newSheet.m_szFileName.clear();
	char buff[200];
	for(int i = 0; i < (int)sheetName; i++)
	{
		in.read((char*)&buff[i],sizeof(char));
		newSheet.m_szFileName.push_back(buff[i]);
	}
	in.read((char*)&newSheet.m_nImageID, sizeof(int));

	in.read((char*)&animCount,sizeof(int));
	for(int i = 0; i < animCount; i++)
	{
		in.read((char*)&animName, sizeof(char));
		char animBuff[50];
		for(int animCount = 0; animCount < (int)animName; animCount++)
		{
			in.read((char*)&animBuff[animCount],sizeof(char));
			newSheet.m_Animations[i].m_szAnimName.push_back(animBuff[animCount]);
		}
		in.read((char*)&newSheet.m_Animations[i].m_bIsLooping, sizeof(bool));

		in.read((char*)&frameCount, sizeof(int));
		for(int j = 0; j < frameCount; j++)
		{

			in.read((char*)(int)&newSheet.m_Animations[i].m_Frames[j].m_fDuration, sizeof(float));
			in.read((char*)&newSheet.m_Animations[i].m_Frames[j].m_shAnchorX, sizeof(int));
			in.read((char*)&newSheet.m_Animations[i].m_Frames[j].m_shAnchorY, sizeof(int));
			in.read((char*)&newSheet.m_Animations[i].m_Frames[j].m_shWeaponX, sizeof(int));
			in.read((char*)&newSheet.m_Animations[i].m_Frames[j].m_shWeaponY, sizeof(int));

			in.read((char*)&newSheet.m_Animations[i].m_Frames[j].m_RImageRect.left, sizeof(int));
			in.read((char*)&newSheet.m_Animations[i].m_Frames[j].m_RImageRect.top, sizeof(int));
			in.read((char*)&newSheet.m_Animations[i].m_Frames[j].m_RImageRect.right, sizeof(int));
			newSheet.m_Animations[i].m_Frames[j].m_RImageRect.right += newSheet.m_Animations[i].m_Frames[j].m_RImageRect.left;
			in.read((char*)&newSheet.m_Animations[i].m_Frames[j].m_RImageRect.bottom, sizeof(int));
			newSheet.m_Animations[i].m_Frames[j].m_RImageRect.bottom += newSheet.m_Animations[i].m_Frames[j].m_RImageRect.top;

			in.read((char*)&newSheet.m_Animations[i].m_Frames[j].m_RCollisionRect.left, sizeof(int));
			in.read((char*)&newSheet.m_Animations[i].m_Frames[j].m_RCollisionRect.top, sizeof(int));
			in.read((char*)&newSheet.m_Animations[i].m_Frames[j].m_RCollisionRect.right, sizeof(int));
			newSheet.m_Animations[i].m_Frames[j].m_RCollisionRect.right += newSheet.m_Animations[i].m_Frames[j].m_RCollisionRect.left;
			in.read((char*)&newSheet.m_Animations[i].m_Frames[j].m_RCollisionRect.bottom, sizeof(int));
			newSheet.m_Animations[i].m_Frames[j].m_RCollisionRect.bottom += newSheet.m_Animations[i].m_Frames[j].m_RCollisionRect.top;

			in.read((char*)&newSheet.m_Animations[i].m_Frames[j].m_RAttackRect.left, sizeof(int));
			in.read((char*)&newSheet.m_Animations[i].m_Frames[j].m_RAttackRect.top, sizeof(int));
			in.read((char*)&newSheet.m_Animations[i].m_Frames[j].m_RAttackRect.right, sizeof(int));
			newSheet.m_Animations[i].m_Frames[j].m_RAttackRect.right += newSheet.m_Animations[i].m_Frames[j].m_RAttackRect.left;
			in.read((char*)&newSheet.m_Animations[i].m_Frames[j].m_RAttackRect.bottom, sizeof(int));
			newSheet.m_Animations[i].m_Frames[j].m_RAttackRect.bottom += newSheet.m_Animations[i].m_Frames[j].m_RAttackRect.top;

			in.read((char*)&trigCount, sizeof(int));
			for(int k = 0; k < trigCount; k++)
			{
				char trigBuff[20];
				in.read((char*)&triggerName, sizeof(char));
				for(int tri = 0; tri < (int)triggerName; tri++)
				{
					in.read((char*)&trigBuff[tri], sizeof(char));
					newSheet.m_Animations[i].m_Frames[j].m_Triggers[k].m_szEvent.push_back(trigBuff[tri]);
				}
				in.read((char*)&newSheet.m_Animations[i].m_Frames[j].m_Triggers[k].m_shXLoc, sizeof(int));
				in.read((char*)&newSheet.m_Animations[i].m_Frames[j].m_Triggers[k].m_shYLoc, sizeof(int));
			}

		}
	}

	in.close();
	in.clear();

	//CAnimationManager::m_Sheets[m_nNumSheets] = newSheet;
	memcpy(&m_Sheets[m_nNumSheets], &newSheet, sizeof(newSheet));
	m_nNumSheets++;

}


CAnimationInstance& CAnimationManager::Animate(CAnimationInstance key)
{
	if(key.m_fCurrTime > 80)
	{
		int i = 0;
		for(; !((key.m_CurrFrame->m_shAnchorX == key.m_CurrAnimation->m_Frames[i].m_shAnchorX) && 
			(key.m_CurrFrame->m_shAnchorY == key.m_CurrAnimation->m_Frames[i].m_shAnchorY)); i++)
		{

		}
		if(key.m_CurrAnimation->m_Frames[i+1].m_shAnchorX > 0 && key.m_CurrAnimation->m_Frames[i+1].m_shAnchorY > 0)
			key.m_CurrFrame = &key.m_CurrAnimation->m_Frames[i+1];
		else /*if(key.m_CurrAnimation->m_bIsLooping == true)*/
			key.m_CurrFrame = &key.m_CurrAnimation->m_Frames[0];
		for(int i = 0; i < 10; i++)
		{
			if(key.m_CurrFrame->m_Triggers[0].m_szEvent != "")
			{
				// Send the event
			}
		}
		key.m_fCurrTime = 0.0f;
		key.m_RCurrCollisionRect = key.m_CurrFrame->m_RCollisionRect;
	}
	key.m_fCurrTime++;
	return key;
}

CAnimationInstance& CAnimationManager::ChangeAnimation(CAnimationInstance key, string szAnimationName)
{
	int i = 0;
	for( ; key.m_CurrSheet->m_Animations[i].m_szAnimName != szAnimationName; i++)
	{

	}
	key.m_CurrAnimation = &key.m_CurrSheet->m_Animations[i];
	key.m_CurrFrame = &key.m_CurrAnimation->m_Frames[0];
	return key;
}

CAnimationInstance& CAnimationManager::SetAnimationInstance(std::string szSheetFileName, std::string szAnimationName)
{
	CAnimationInstance newInstance;
	bool GTFO = false;
	int i = 0;
	/*for( ;  i < 50; i++)
	{
	if( (string)m_Sheets[i].m_szFileName == (string)szSheetFileName )
	break;
	}
	newInstance.m_CurrSheet = &m_Sheets[i];*/

	for(int i = 0; i < 50; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			if(GetSheet(i).m_Animations[j].m_szAnimName == szAnimationName)
			{
				newInstance.m_CurrSheet = &GetSheet(i);
				newInstance.m_CurrAnimation = &GetSheet(i).m_Animations[j];
				newInstance.m_CurrFrame = &GetSheet(i).m_Animations[j].m_Frames[0];
				newInstance.m_fCurrTime = 0;
				newInstance.m_RCurrCollisionRect.left = newInstance.m_CurrFrame->m_RCollisionRect.left;
				newInstance.m_RCurrCollisionRect.top = newInstance.m_CurrFrame->m_RCollisionRect.top;
				newInstance.m_RCurrCollisionRect.right = newInstance.m_CurrFrame->m_RCollisionRect.right;
				newInstance.m_RCurrCollisionRect.bottom = newInstance.m_CurrFrame->m_RCollisionRect.bottom;
				GTFO = true;
				break;
			}

		}

		if(GTFO == true)
			break;

	}


	return newInstance;
}