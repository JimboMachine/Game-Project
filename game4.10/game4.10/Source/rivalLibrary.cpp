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
		if (name == "Doge")				//���J���
		{
			range = 15;
			health = 1000;
			attack = 100;
			attackDelay = 20;
			walkAnimationStart = 0;
			walkAnimationEnd = 3;
			attackAnimationStart = 4;
			attackAnimationEnd = 8;
			deathAnimationStart = 9;
			deathAnimationEnd = 20;
			deathHeightChange = 95;
			deathXChange = 185;
			moveSpeed = 3;
			imageQuantity = 21;
			headGap = 26;
			originY = 640;
		}
		else if (name == "Snache") {	//���D���
			range = 20;
			health = 10;
			attack = 1;
			attackDelay = 20;
			walkAnimationStart = 0;
			walkAnimationEnd = 4;
			attackAnimationStart = 5;
			attackAnimationEnd = 11;
			deathAnimationStart = 12;
			deathAnimationEnd = 23;
			deathHeightChange = 85;
			deathXChange = 161;
			moveSpeed = 3;
			imageQuantity = 24;
			headGap = 13;
			originY = 640;
		}
		else if (name == "Those Guys") { //�ε��_�l�����
			range = 20;
			health = 100;
			attack = 1;
			attackDelay = 13;
			walkAnimationStart = 0;
			walkAnimationEnd = 3;
			attackAnimationStart = 4;
			attackAnimationEnd = 17;
			deathAnimationStart = 18;
			deathAnimationEnd = 29;
			deathHeightChange = 0;
			deathXChange = 103;
			moveSpeed = 3;
			imageQuantity = 30;
			headGap = 13;
			originY = 640;
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
		if (name == "Doge") {		//���J���
			char *temp[21] = { ".\\bitmaps\\�Ĥ�\\���J\\����0.bmp",".\\bitmaps\\�Ĥ�\\���J\\����1.bmp",".\\bitmaps\\�Ĥ�\\���J\\����2.bmp",".\\bitmaps\\�Ĥ�\\���J\\����3.bmp",".\\bitmaps\\�Ĥ�\\���J\\����0.bmp",".\\bitmaps\\�Ĥ�\\���J\\����2.bmp",".\\bitmaps\\�Ĥ�\\���J\\����3.bmp",".\\bitmaps\\�Ĥ�\\���J\\����4.bmp",".\\bitmaps\\�Ĥ�\\���J\\����5.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h0.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h1.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h2.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h3.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h4.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h5.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h6.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h7.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h8.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h9.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h10.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h11.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Snache") {	//���D���
			char *temp[24] = { ".\\bitmaps\\�Ĥ�\\���D\\�樫0.bmp",".\\bitmaps\\�Ĥ�\\���D\\�樫1.bmp",".\\bitmaps\\�Ĥ�\\���D\\�樫2.bmp",".\\bitmaps\\�Ĥ�\\���D\\�樫3.bmp",".\\bitmaps\\�Ĥ�\\���D\\�樫4.bmp",".\\bitmaps\\�Ĥ�\\���D\\����0.bmp",".\\bitmaps\\�Ĥ�\\���D\\����1.bmp",".\\bitmaps\\�Ĥ�\\���D\\����2.bmp",".\\bitmaps\\�Ĥ�\\���D\\����3.bmp",".\\bitmaps\\�Ĥ�\\���D\\����4.bmp",".\\bitmaps\\�Ĥ�\\���D\\����5.bmp",".\\bitmaps\\�Ĥ�\\���D\\����6.bmp",".\\bitmaps\\�Ĥ�\\���D\\���h0.bmp",".\\bitmaps\\�Ĥ�\\���D\\���h1.bmp",".\\bitmaps\\�Ĥ�\\���D\\���h2.bmp",".\\bitmaps\\�Ĥ�\\���D\\���h3.bmp",".\\bitmaps\\�Ĥ�\\���D\\���h4.bmp",".\\bitmaps\\�Ĥ�\\���D\\���h5.bmp",".\\bitmaps\\�Ĥ�\\���D\\���h6.bmp",".\\bitmaps\\�Ĥ�\\���D\\���h7.bmp",".\\bitmaps\\�Ĥ�\\���D\\���h8.bmp",".\\bitmaps\\�Ĥ�\\���D\\���h9.bmp",".\\bitmaps\\�Ĥ�\\���D\\���h10.bmp",".\\bitmaps\\�Ĥ�\\���D\\���h11.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Those Guys") {//�ε��_�l�����
			char *temp[30] = { ".\\bitmaps\\�Ĥ�\\�ε��_�l��\\�樫0.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\�樫1.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\�樫2.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\�樫3.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����0.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����1.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����2.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����3.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����4.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����5.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����6.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����7.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����8.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����9.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����10.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����11.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����12.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����13.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\���h0.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\���h1.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\���h2.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\���h3.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\���h4.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\���h5.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\���h6.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\���h7.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\���h8.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\���h9.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\���h10.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\���h11.bmp" };
			return temp[imageNumber];
		}
		else {
			char *temp[1] = { ".\\bitmaps\\�Ĥ�\\���J\\����0.bmp" };
			return temp[imageNumber];
		}
		
	}



}