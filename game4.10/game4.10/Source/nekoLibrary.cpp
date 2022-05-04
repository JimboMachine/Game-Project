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

	nekoLibrary::nekoLibrary(string name)	//��J�߫}�����]�w�ƭ�
	{
		if (name == "Cat") {				//�߫}���
			range = 3;
			health = 1;
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
			moveSpeed = 5;
		}
		
		
	}
		
}