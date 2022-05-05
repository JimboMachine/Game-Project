#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "rivalLibrary.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѼĤ��Ų�����Ĥ誺�U�����
	// 
	/////////////////////////////////////////////////////////////////////////////
	
	/////////////////////////////////////////////////////////////////////////////
	//��J�Ĥ�����]�w�ƭ�
	//
	/////////////////////////////////////////////////////////////////////////////
	rivalLibrary::rivalLibrary(string name) {
		if (name == "Doge")
		{
			range = 4;
			health = 90;
			attack = 1;
			attackDelay = 20;
			walkAnimationStart = 0;
			walkAnimationEnd = 3;
			attackAnimationStart = 4;
			attackAnimationEnd = 8;
			deathAnimationStart = 9;
			deathAnimationEnd = 16;
			deathHeightChange = 101;
			moveSpeed = 3;
			imageQuantity = 9;
		}
		else {
			range = 4;
			health = 100;
			attack = 1;
			attackDelay = 20;
			walkAnimationStart = 0;
			walkAnimationEnd = 3;
			attackAnimationStart = 4;
			attackAnimationEnd = 8;
			deathAnimationStart = 9;
			deathAnimationEnd = 16;
			deathHeightChange = 101;
			moveSpeed = 3;
			imageQuantity = 17;
		}
	}

	/////////////////////////////////////////////////////////////////////////////
	//�Ĥ�Ϥ����J
	//
	/////////////////////////////////////////////////////////////////////////////
	char * rivalLibrary::imageList(string name, int imageNumber)
	{
		char *temp[9] = { ".\\bitmaps\\���J\\����0.bmp",".\\bitmaps\\���J\\����1.bmp",".\\bitmaps\\���J\\����2.bmp",".\\bitmaps\\���J\\����3.bmp",".\\bitmaps\\���J\\����0.bmp",".\\bitmaps\\���J\\����2.bmp",".\\bitmaps\\���J\\����3.bmp",".\\bitmaps\\���J\\����4.bmp",".\\bitmaps\\���J\\����5.bmp" };
		return temp[imageNumber];
	}



}