#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "rivalAnimation.h"
#include "nekoAnimation.h"


namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// class dogeAnimation ���J�ʵe���禡�w�q
	/////////////////////////////////////////////////////////////////////////////

	rivalAnimation::rivalAnimation() {
		//���ͦ����󪺪�l��
		x1 = x2 = y = 0;
		IsAlive = true;			
		range = 4;						//��ڶZ����26+4=30
		health = 100;
		attack = 1;
	}

	void rivalAnimation::LoadBitmap() {
		image.AddBitmap(IDB_doge0, RGB(255, 0, 0));				//���J���J�ʵe�Ϥ�0
		image.AddBitmap(IDB_doge1, RGB(255, 0, 0));				//���J���J�ʵe�Ϥ�1
		image.AddBitmap(IDB_doge2, RGB(255, 0, 0));				//���J���J�ʵe�Ϥ�2
		image.AddBitmap(IDB_doge3, RGB(255, 0, 0));				//���J���J�ʵe�Ϥ�3
		image.SetDelayCount(5);									//���J�ʵe�ഫ����t��
	}

	void rivalAnimation::OnMove() {
		x2 = x1 + image.Width();								//�NX2�]�w���Ϥ��̥k�䪺X�y��
		image.OnMove();											//���J�ʵe�}�l�ܴ�
	}

	void rivalAnimation::OnShow() {
		if (IsAlive == true)
		{
			image.SetTopLeft(x1, y);								// �]�w���J�y��
			image.OnShow();											//�K�W���J
		}
	}

	int rivalAnimation::GetX1()									//���oX�y��
	{
		return x1;
	}

	int rivalAnimation::GetX2()
	{
		return x2;
	}

	int rivalAnimation::GetY()									//���oY�y��
	{
		return y;
	}

	void rivalAnimation::SetCoordinate(int NewX, int NewY)		//�]�w�y��
	{
		x1 = NewX;
		y = NewY;
	}

	void rivalAnimation::MoveForward(nekoAnimation neko)
	{
		if (neko.GetX1() > x2 + range) {			//�P�_���L�I��
			x1 += 5;
			x2 += 5;
		}
		else {								//�p�G�I��N����
			//IsAlive = false;
		}

	}

	bool rivalAnimation::GetIsAlive()
	{
		return IsAlive;
	}

	int rivalAnimation::GetAttack()
	{
		return attack;
	}

	int rivalAnimation::GetHealth()
	{
		return health;
	}

}