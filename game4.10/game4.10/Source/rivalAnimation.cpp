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
		attackDelay = 20;				//framework�@�����10������10���N����1�����@��
		delay = 1;
		walkAnimationStart = 0;
		walkAnimationEnd = 3;
		attackAnimationStart = 4;
		attackAnimationEnd = 8;
		deathAnimationStart = 9;
		deathAnimationEnd = 16;
		deathDelay = 0;
		deathHeightChange = 101;
		moveSpeed = 3;
	}

	void rivalAnimation::LoadBitmap() {
		char *temp[9] = { ".\\bitmaps\\���J\\����0.bmp",".\\bitmaps\\���J\\����1.bmp",".\\bitmaps\\���J\\����2.bmp",".\\bitmaps\\���J\\����3.bmp",".\\bitmaps\\���J\\����0.bmp",".\\bitmaps\\���J\\����2.bmp",".\\bitmaps\\���J\\����3.bmp",".\\bitmaps\\���J\\����4.bmp",".\\bitmaps\\���J\\����5.bmp"};
		for (int i = 0; i < 9; i++)
			image.AddBitmap(temp[i], RGB(255, 0, 0));
		image.SetDelayCount(2);									//���J�ʵe�ഫ����t��
	}

	void rivalAnimation::OnMove() {
		x2 = x1 + image.Width();								//�NX2�]�w���Ϥ��̥k�䪺X�y��
		image.OnMove();											//���J�ʵe�}�l�ܴ�
	}

	void rivalAnimation::OnShow() {
		//if (IsAlive == true)
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

	void rivalAnimation::MoveForward(nekoAnimation *neko)
	{
		die();						//�P�_��O�p�󵥩�s�A���߫h���榹���
		if (!IsAlive)				//�Y���`�N���b����H�U�{���X
			return;

		if ((neko->GetX1() > x2 + range) || (neko->GetIsAlive() == false)){			//�P�_���L�I���M�Ĥ�O�_����
			x1 += moveSpeed;
			x2 += moveSpeed;
			OnMove();
			if (image.GetCurrentBitmapNumber() > walkAnimationEnd)		//�Y�樫�ʵe�����F�A���Y���@��
			{
				image.Reset();
				image.SetDelayCount(2);				//�]�w����t��
			}
		}
		else {								//�p�G�I��}�l�i�����

			if (delay == 1) {			//�]�w������l�ʵe
				image.SetDelayCount(1);		//�]�w����t��
				image.SetCurrentBitmap(attackAnimationStart);
				delay += 1;
				OnMove();
			}
			else if (delay < (attackAnimationEnd - attackAnimationStart) + 1) {		//��������ʵe
				OnMove();
				delay += 1;
			}
			else if (delay == (attackAnimationEnd - attackAnimationStart) + 1) {		//���o��誺��O�CX���������O
				neko->SetHealth(neko->GetHealth() - attack);
				delay += 1;
			}
			else {						//�����N�o���A
				image.SetCurrentBitmap(attackAnimationStart);
				delay += 1;
				if (delay >= attackDelay) {	//�Y����N�o�ɶ��Ndelay����
					delay = 1;
				}
			}

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

	void rivalAnimation::SetHealth(int NewHealth)
	{
		health = NewHealth;
	}

	int rivalAnimation::GetAnimationNumber()
	{
		return image.GetCurrentBitmapNumber();
	}

	void rivalAnimation::SetCurrentBitmap(int x)
	{
		image.SetCurrentBitmap(x);
	}


	void rivalAnimation::die()
	{
		if (health <= 0)					 //�P�_��O�p�󵥩�s�A���߫h���榹���
		{
			IsAlive = false;
			x1 -= 15;
			x2 -= 15;
			y = 0;
		}
	}

}