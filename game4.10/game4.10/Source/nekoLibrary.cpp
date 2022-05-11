#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "nekoLibrary.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѿ߫}��Ų�����߫}���U�����
	// 
	/////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////
	//��J�߫}�����]�w�ƭ�
	//
	/////////////////////////////////////////////////////////////////////////////
	nekoLibrary::nekoLibrary(string name)	
	{
		if (name == "Cat") {				//�߫}���
			range = 4;
			health = 100;
			attack = 1;
			attackDelay = 10;
			walkAnimationStart = 0;
			walkAnimationEnd = 3;
			attackAnimationStart = 4;
			attackAnimationEnd = 8;
			deathAnimationStart = 9;
			deathAnimationEnd = 16;
			deathHeightChange = 101;
			moveSpeed = 3;
			imageQuantity = 17;
			headGap = 27;			
		}
		else if (name == "Tank Cat") {		//��߸��
			range = 3;
			health = 100;
			attack = 5;
			attackDelay = 20;
			walkAnimationStart = 0;
			walkAnimationEnd = 3;
			attackAnimationStart = 4;
			attackAnimationEnd = 8;
			deathAnimationStart = 9;
			deathAnimationEnd = 16;
			deathHeightChange = 101;
			moveSpeed = 3;
			imageQuantity = 10;
			headGap = 76;
		}
		
		
	}
	/////////////////////////////////////////////////////////////////////////////
	//�߫}�Ϥ����J
	//
	/////////////////////////////////////////////////////////////////////////////
	char * nekoLibrary::imageList(string name,int imageNumber)
	{
		if (name == "Cat") {				//�߫}���
			char *temp[17] = { ".\\bitmaps\\�߫}\\�߫}\\�߫}0.bmp",".\\bitmaps\\�߫}\\�߫}\\�߫}1.bmp",".\\bitmaps\\�߫}\\�߫}\\�߫}2.bmp",".\\bitmaps\\�߫}\\�߫}\\�߫}3.bmp",".\\bitmaps\\�߫}\\�߫}\\����0.bmp",".\\bitmaps\\�߫}\\�߫}\\����1.bmp",".\\bitmaps\\�߫}\\�߫}\\����3.bmp",".\\bitmaps\\�߫}\\�߫}\\����4.bmp",".\\bitmaps\\�߫}\\�߫}\\����5.bmp",".\\bitmaps\\�߫}\\�߫}\\���h0.bmp",".\\bitmaps\\�߫}\\�߫}\\���h1.bmp",".\\bitmaps\\�߫}\\�߫}\\���h2.bmp",".\\bitmaps\\�߫}\\�߫}\\���h3.bmp",".\\bitmaps\\�߫}\\�߫}\\���h4.bmp",".\\bitmaps\\�߫}\\�߫}\\���h5.bmp",".\\bitmaps\\�߫}\\�߫}\\���h6.bmp",".\\bitmaps\\�߫}\\�߫}\\���h7.bmp" };
			return temp[imageNumber];
		}
		else if(name == "Tank Cat") {		//��߸��
			char *temp[10] = { ".\\bitmaps\\�߫}\\���\\�樫0.bmp",".\\bitmaps\\�߫}\\���\\�樫1.bmp",".\\bitmaps\\�߫}\\���\\�樫2.bmp",".\\bitmaps\\�߫}\\���\\�樫3.bmp",".\\bitmaps\\�߫}\\���\\����0.bmp",".\\bitmaps\\�߫}\\���\\����1.bmp",".\\bitmaps\\�߫}\\���\\����2.bmp",".\\bitmaps\\�߫}\\���\\����3.bmp",".\\bitmaps\\�߫}\\���\\����4.bmp",".\\bitmaps\\�߫}\\���\\����5.bmp" };
			return temp[imageNumber];
		}
		else {
			char *temp[1] = {".\\bitmaps\\�߫}\\�߫}\\�߫}0.bmp"};
			return temp[imageNumber];
		}
	}

}