#include "BitmapFontManager.h"

BitmapFontManager::BitmapFontManager(void)
{
	m_nNumFonts = 0;
}

BitmapFontManager::~BitmapFontManager(void)
{
}

BitmapFontManager* BitmapFontManager::GetInstance()
{
	static BitmapFontManager instance;
	return &instance;
}


bool BitmapFontManager::LoadBinary(int nFontImageID)
{
	for(int i = 0; i < m_vFonts.size(); i++)		//Check if info loaded
	{
		if (nFontImageID == m_vFonts[i].FontNumber)
			return true;							//Info loaded return success
	}



	FONT tempfont;																				//Create a temporary font
	string filename = CSGD_TextureManager::GetInstance()->GetTextureFilename(nFontImageID);
	
	if (filename.empty())
		return false;		//Cannot find file - return failure
	else
	{
		filename += ".bin";
		ifstream in(filename.c_str(), ios::in | ios::binary);
		//in.exceptions(ios_base::eofbit | ios_base::badbit | ios_base::failbit);
		if (in.is_open() && in.good())
		{
			while (!in.eof())
			{
				CHARRECT temp;
				in.read((char*)&temp.character,sizeof(char));
				in.read((char*)&temp.bounding.left,sizeof(unsigned int));
				in.read((char*)&temp.bounding.top,sizeof(unsigned int));
				in.read((char*)&temp.bounding.right,sizeof(unsigned int));
				temp.bounding.right += temp.bounding.left;
				in.read((char*)&temp.bounding.bottom,sizeof(unsigned int));
				temp.bounding.bottom += temp.bounding.top;
				in.read((char*)&temp.Offset,sizeof(unsigned int));
				tempfont.CharRects.push_back(temp);

			}
			
		}
		tempfont.FontNumber = nFontImageID;							//Set Font number to matching imageid
		m_nNumFonts++;
		m_vFonts.push_back(tempfont);
		return true;
	}
}

bool BitmapFontManager::DrawString(string szText, int nFontImageID, int nPosX, int nPosY, float fScaleX, float fScaleY, DWORD dwTransparencyColor)
{
	int nNetWidth = 0;
	int nMaxHeight = 0;
	int toadd = 0;
	int offset = 0;
	if ( LoadBinary(nFontImageID))			//Check for .bin file
	{
		for (int i = 0; i < szText.length();i++)
		{
			if (szText[i] == ' ')
				nNetWidth += (16 * fScaleX);
			else 
			{
				RECT section;
				for (int j = 0; j < m_vFonts.size(); j++)
				{
					if (m_vFonts[j].FontNumber == nFontImageID)
					{
						for (int k = 0; k < m_vFonts[j].CharRects.size(); k++)
						{
							if (m_vFonts[j].CharRects[k].character == szText[i])
							{
								section = m_vFonts[j].CharRects[k].bounding;
								toadd = (section.right - section.left) * fScaleX;
								offset = m_vFonts[j].CharRects[k].Offset * fScaleY;
							}
							

						}
					}
				}
			
			CSGD_TextureManager::GetInstance()->Draw(nFontImageID,nPosX + nNetWidth, nPosY + offset,fScaleX,fScaleY,&section,0,0,0,dwTransparencyColor);
			nNetWidth += (toadd + (8 * fScaleX)) ;
			}
		}

		return true;
	}
	else
		return false;						//Couldn't find .bin file - No Drawing
}
