#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "stageImformation.h"

namespace game_framework {

	/////////////////////////////////////////////////////////////////////////////
	// stageImformation:�o��class�������d��T����O
	// 
	// 
	/////////////////////////////////////////////////////////////////////////////
	CMovingBitmap stageImformation::BackGround[7];
	CMovingBitmap stageImformation::Name[7];
	stageImformation::stageImformation()
	{
		isBmpLoaded = false;
	}

	string stageImformation::getRivalBase(int stage)
	{
		return stageRivalBase[stage-1];
	}

	void stageImformation::LoadBitmap()
	{
		if (!isBmpLoaded) {
			char *background[7] = { ".\\bitmaps\\�I��\\��a.bmp",".\\bitmaps\\�I��\\��a.bmp",".\\bitmaps\\�I��\\��a.bmp",".\\bitmaps\\�I��\\��a.bmp",".\\bitmaps\\�I��\\����.bmp",".\\bitmaps\\�I��\\��a.bmp",".\\bitmaps\\�I��\\�]��.bmp"};
			char *name[7] = { ".\\bitmaps\\���d�W��\\�x�W.bmp", ".\\bitmaps\\���d�W��\\����.bmp", ".\\bitmaps\\���d�W��\\����.bmp", ".\\bitmaps\\���d�W��\\����.bmp", ".\\bitmaps\\���d�W��\\�X�j.bmp", ".\\bitmaps\\���d�W��\\����.bmp", ".\\bitmaps\\���d�W��\\�饻.bmp" };
			for (int i = 0; i < 7; i++) {
				BackGround[i].LoadBitmap(background[i],RGB(255,0,0));
				BackGround[i].SetTopLeft(0,0);
				Name[i].LoadBitmap(name[i],RGB(255, 0, 0));
				Name[i].SetTopLeft(110, 3);
			}
			isBmpLoaded = true;
		}
	}

	void stageImformation::ShowBitmapBackGround(int stage)
	{
		BackGround[stage - 1].ShowBitmap();
	}

	void stageImformation::ShowBitmapName(int stage)
	{
		Name[stage - 1].ShowBitmap();
	}
}