#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "nekoLibrary.h"
#include "rivalAnimation.h"			//�ݥ��פJ�~��Ū��
#include "nekoAnimation.h"

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// class nekoAnimation �߫}�ʵe���禡�w�q
	/////////////////////////////////////////////////////////////////////////////
	
	nekoAnimation::nekoAnimation()
	{
		nekoLibrary data("Tank Cat");//���ͦ����󪺪�l��
		
		x1 = x2 = y = 0;
		IsAlive = true;
		range = data.range;					//��ڶZ����27+3=30
		health = data.health;
		attack = data.attack;
		attackDelay = data.attackDelay;		//framework�@�����10������12���N����1.2�����@��
		delay = 1;				
		walkAnimationStart = data.walkAnimationStart;
		walkAnimationEnd = data.walkAnimationEnd;
		attackAnimationStart = data.attackAnimationStart;
		attackAnimationEnd = data.attackAnimationEnd;
		deathAnimationStart = data.deathAnimationStart;
		deathAnimationEnd = data.deathAnimationEnd;
		deathDelay = 0;
		deathHeightChange = data.deathHeightChange;
		moveSpeed = data.moveSpeed;
		
	}

	void nekoAnimation::LoadBitmap()
	{
		char *temp[17] = {".\\bitmaps\\�߫}\\�߫}0.bmp",".\\bitmaps\\�߫}\\�߫}1.bmp",".\\bitmaps\\�߫}\\�߫}2.bmp",".\\bitmaps\\�߫}\\�߫}3.bmp",".\\bitmaps\\�߫}\\����0.bmp",".\\bitmaps\\�߫}\\����1.bmp",".\\bitmaps\\�߫}\\����3.bmp",".\\bitmaps\\�߫}\\����4.bmp",".\\bitmaps\\�߫}\\����5.bmp",".\\bitmaps\\�߫}\\���h0.bmp",".\\bitmaps\\�߫}\\���h1.bmp",".\\bitmaps\\�߫}\\���h2.bmp",".\\bitmaps\\�߫}\\���h3.bmp",".\\bitmaps\\�߫}\\���h4.bmp",".\\bitmaps\\�߫}\\���h5.bmp",".\\bitmaps\\�߫}\\���h6.bmp",".\\bitmaps\\�߫}\\���h7.bmp" };
		for (int i = 0; i < 17; i++)
			image.AddBitmap(temp[i], RGB(255, 0, 0));
		image.SetDelayCount(2);									//�߫}�ʵe�ഫ����t��
	}

	void nekoAnimation::OnMove()
	{
		x2 = x1 + image.Width();								//�NX2�]�w���Ϥ��̥k�䪺X�y��
		image.OnMove();											//�߫}�ʵe�}�l�ܴ�
	}

	void nekoAnimation::OnShow()
	{
		if (IsAlive == true)			//�Y�����٬��۷|��ܦb�e��
		{
			image.SetTopLeft(x1, y);								// �]�w�߫}�y��
			image.OnShow();											//�K�W�߫}
		}
		else if (IsAlive == false && deathDelay < (deathAnimationEnd - deathAnimationStart)) {	//���h�ɭn�N���⪺Y�y�а��վ�
			image.SetTopLeft(x1, y-deathHeightChange);
			image.OnShow();
		}
		//���`�N����ܦb�e��
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

		die();						//�P�_��O�p�󵥩�s�A���߫h���榹���
		if (!IsAlive)				//�Y���`�N���b����H�U�{���X
			return;

		if ((rival->GetX2() < x1 - range) || (rival->GetIsAlive() == false)){	//�P�_���L�I���M�Ĥ�O�_����
			x1 -= moveSpeed;
			x2 -= moveSpeed;
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
				rival->SetHealth(rival->GetHealth() - attack);	
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

	int nekoAnimation::GetAnimationNumber()
	{
		return image.GetCurrentBitmapNumber();
	}

	void nekoAnimation::SetCurrentBitmap(int x)
	{
		image.SetCurrentBitmap(x);
	}

	void nekoAnimation::die()
	{
		if (health <= 0)					 //�P�_��O�p�󵥩�s�A���߫h���榹���
		{
			IsAlive = false;
			if (deathDelay == 0) {			//��O�p�󵥩�s�����l�����ʵe�ܦ��Ĥ@�i���h�ʵe
				image.SetCurrentBitmap(deathAnimationStart);
				deathDelay++;
				image.OnMove();
			}		
			else if (deathDelay < (deathAnimationEnd - deathAnimationStart)) {	//���h�ʵe�}�l���񪽨켽��
				image.OnMove();
				deathDelay++;
			}
			
		}

	}


}