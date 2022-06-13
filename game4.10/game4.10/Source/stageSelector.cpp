#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "stageSelector.h"

namespace game_framework {

/////////////////////////////////////////////////////////////////////////////
// stageSelector:�o��class���ѿ�����d����O
// 
// 
/////////////////////////////////////////////////////////////////////////////
	CMovingBitmap stageSelector::stageImage[30];

	stageSelector::stageSelector()
	{
		isBmpLoaded = false;
		targetStage = 1;
		finalStage = 7;
	}

	void stageSelector::LoadBitmap()
	{
		if (!isBmpLoaded) {
			char *L[7] = { ".\\bitmaps\\���d�Ϥ�\\�x�W.bmp",".\\bitmaps\\���d�Ϥ�\\����.bmp",".\\bitmaps\\���d�Ϥ�\\����.bmp",".\\bitmaps\\���d�Ϥ�\\����.bmp",".\\bitmaps\\���d�Ϥ�\\�X�j.bmp",".\\bitmaps\\���d�Ϥ�\\����.bmp",".\\bitmaps\\���d�Ϥ�\\�饻.bmp" };
			for (int i = 0; i < 7; i++) {
				stageImage[i].LoadBitmap(L[i]);
			}
			isBmpLoaded = true;
		}
	}

	void stageSelector::ShowBitmap()
	{
		stageImage[targetStage - 1].ShowBitmap();
	}

	void stageSelector::SetTopLeft()
	{
	}

	void stageSelector::clickRight()
	{
		if (targetStage < finalStage) {
			targetStage += 1;
		}
	}

	void stageSelector::clickLeft()
	{
		if (targetStage > 1) {
			targetStage -= 1;
		}
	}

	int stageSelector::getStage()
	{
		return targetStage;
	}

}