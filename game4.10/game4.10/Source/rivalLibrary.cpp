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
			range = 3;
			health = 1000;
			attack = 1;
			attackDelay = 20;
			walkAnimationStart = 0;
			walkAnimationEnd = 3;
			attackAnimationStart = 4;
			attackAnimationEnd = 8;
			deathAnimationStart = 9;
			deathAnimationEnd = 20;
			deathHeightChange = 101;
			moveSpeed = 3;
			imageQuantity = 21;
			headGap = 26;
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
			headGap = 26;
		}
	}

	/////////////////////////////////////////////////////////////////////////////
	//�Ĥ�Ϥ����J
	//
	/////////////////////////////////////////////////////////////////////////////
	char * rivalLibrary::imageList(string name, int imageNumber)
	{
		char *temp[21] = { ".\\bitmaps\\�Ĥ�\\���J\\����0.bmp",".\\bitmaps\\�Ĥ�\\���J\\����1.bmp",".\\bitmaps\\�Ĥ�\\���J\\����2.bmp",".\\bitmaps\\�Ĥ�\\���J\\����3.bmp",".\\bitmaps\\�Ĥ�\\���J\\����0.bmp",".\\bitmaps\\�Ĥ�\\���J\\����2.bmp",".\\bitmaps\\�Ĥ�\\���J\\����3.bmp",".\\bitmaps\\�Ĥ�\\���J\\����4.bmp",".\\bitmaps\\�Ĥ�\\���J\\����5.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h0.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h1.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h2.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h3.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h4.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h5.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h6.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h7.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h8.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h9.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h10.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h11.bmp" };
		return temp[imageNumber];
	}



}