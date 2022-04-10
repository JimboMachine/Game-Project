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
		health = 5;
		attack = 1;
		attackDelay = 10;				//framework�@�����10������10���N����1�����@��
		delay = 1;				
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
		//if (IsAlive == true)
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

	void nekoAnimation::MoveForward(rivalAnimation *rival)
	{

		if (!IsAlive)				//�Y���`�N���b����H�U�{���X
			return;

		die();						//�P�_��O�p�󵥩�s�A���߫h���榹���	

		if ((rival->GetX2() < x1 - range) || (rival->GetIsAlive() == false)){	//�P�_���L�I���M�Ĥ�O�_����
			x1 -= 3;
			x2 -= 3;
			OnMove();
		}
		else {								//�p�G�I��}�l�i�����
			
			if (delay >= attackDelay)		//�Y����1���������
			{
				rival->SetHealth(rival->GetHealth() - attack);	//���o��誺��O�CX���������O***
				delay = 1;										//�N���𭫨�
			}
			else
			{
				delay += 1;					
			}
			
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

	void nekoAnimation::SetHealth(int NewHealth)
	{
		health = NewHealth;
	}

	void nekoAnimation::die()
	{
		if (health <= 0)					 //�P�_��O�p�󵥩�s�A���߫h���榹���
		{
			IsAlive = false;
			x1 += 15;
			x2 += 15;
			y = 0;
		}
	}


}