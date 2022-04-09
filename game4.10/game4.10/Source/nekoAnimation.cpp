#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "rivalAnimation.h"			//�ݥ��פJ�~��Ū��
#include "nekoAnimation.h"


namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// class nekoAnimation �߫}�ʵe���禡�w�q
	/////////////////////////////////////////////////////////////////////////////
	
	nekoAnimation::nekoAnimation()
	{
		//���ͦ����󪺪�l��
		x1 = x2 = y = 0;
		IsAlive = true;
		range = 3;							//��ڶZ����27+3=30
		health = 100;
		attack = 1;
	}

	void nekoAnimation::LoadBitmap()
	{
		image.AddBitmap(IDB_neko0, RGB(255, 0, 0));				//���J�߫}�ʵe�Ϥ�0
		//image.AddBitmap(IDB_neko1, RGB(255, 0, 0));			//���J�߫}�ʵe�Ϥ�1
		image.AddBitmap(IDB_neko2, RGB(255, 0, 0));				//���J�߫}�ʵe�Ϥ�2
		image.AddBitmap(IDB_neko3, RGB(255, 0, 0));				//���J�߫}�ʵe�Ϥ�3
		image.AddBitmap(IDB_neko4, RGB(255, 0, 0));				//���J�߫}�ʵe�Ϥ�4
		image.SetDelayCount(3);									//�߫}�ʵe�ഫ����t��
	}

	void nekoAnimation::OnMove()
	{
		x2 = x1 + image.Width();								//�NX2�]�w���Ϥ��̥k�䪺X�y��
		image.OnMove();											//�߫}�ʵe�}�l�ܴ�
	}

	void nekoAnimation::OnShow()
	{
		if (IsAlive == true)
		{
			image.SetTopLeft(x1, y);								// �]�w�߫}�y��
			image.OnShow();											//�K�W�߫}
		}
	}

	int nekoAnimation::GetX1()								//���oX(��)�y��
	{
		return x1;
	}

	int nekoAnimation::GetX2()								//���oX(�k)�y��
	{
		return x2;
	}

	int nekoAnimation::GetY()								//���oY�y��
	{
		return y;
	}

	void nekoAnimation::SetCoordinate(int NewX, int NewY)		//�]�w�y��
	{
		x1 = NewX;
		y = NewY;
	}

	void nekoAnimation::MoveForward(rivalAnimation rival)
	{
		
		if (rival.GetX2() < x1 - range) {			//�P�_���L�I��
			x1 -= 3;
			x2 -= 3;
			OnMove();
		}
		else {								//�p�G�I��N����
			health -= rival.GetAttack();
			//IsAlive = false;
		}
	}

	bool nekoAnimation::GetIsAlive()
	{
		return IsAlive;
	}

	int nekoAnimation::GetAttack()
	{
		return attack;
	}

	int nekoAnimation::GetHealth()
	{
		return health;
	}


}