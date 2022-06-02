#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "rivalLibrary.h"
#include "rivalAnimation.h"
#include "nekoAnimation.h"


namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// class dogeAnimation ���J�ʵe���禡�w�q
	/////////////////////////////////////////////////////////////////////////////

	rivalAnimation::rivalAnimation() {
		
		
	}

	rivalAnimation::rivalAnimation(string name)
	{
		rivalType = name;
		rivalLibrary data(rivalType);		//���ͦ����󪺪�l��

		x1 = x2 = data.originX;
		y = data.originY;
		IsAlive = true;
		range = data.range;
		health = data.health;
		attack = data.attack;
		attackDelay = data.attackDelay;	//framework�@�����10������10���N����1�����@��
		delay = 1;
		walkAnimationStart = data.walkAnimationStart;
		walkAnimationEnd = data.walkAnimationEnd;
		attackAnimationStart = data.attackAnimationStart;
		attackAnimationEnd = data.attackAnimationEnd;
		deathAnimationStart = data.deathAnimationStart;
		deathAnimationEnd = data.deathAnimationEnd;
		deathDelay = 0;
		deathHeightChange = data.deathHeightChange;
		deathXChange = data.deathXChange;
		moveSpeed = data.moveSpeed;
		headGap = data.headGap;
		walkAnimationSpeed = data.walkAnimationSpeed;	
		attackAnimationSpeed = data.attackAnimationSpeed;
	}

	void rivalAnimation::LoadBitmap() 
	{
		rivalLibrary data(rivalType);
		
		//char *temp[9] = { ".\\bitmaps\\���J\\����0.bmp",".\\bitmaps\\���J\\����1.bmp",".\\bitmaps\\���J\\����2.bmp",".\\bitmaps\\���J\\����3.bmp",".\\bitmaps\\���J\\����0.bmp",".\\bitmaps\\���J\\����2.bmp",".\\bitmaps\\���J\\����3.bmp",".\\bitmaps\\���J\\����4.bmp",".\\bitmaps\\���J\\����5.bmp"};
		for (int i = 0; i < data.imageQuantity; i++)
			image.AddBitmap(data.imageList(rivalType,i), RGB(255, 0, 0));
		image.SetDelayCount(walkAnimationSpeed);									//���J�ʵe�ഫ����t��
	}

	void rivalAnimation::OnMove() {
		x2 = x1 + image.Width();								//�NX2�]�w���Ϥ��̥k�䪺X�y��
		image.OnMove();											//���J�ʵe�}�l�ܴ�
	}

	void rivalAnimation::OnShow() {
		
		if (IsAlive == true)			//�Y�����٬��۷|��ܦb�e��
		{
			image.SetTopLeft(x1, y);								// �]�w�Ĥ�y��
			image.OnShow();											// �K�W�Ĥ�
		}
		else if (IsAlive == false && deathDelay < (deathAnimationEnd - deathAnimationStart)) {	//���h�ɭn�N���⪺Y�y�а��վ�
			image.SetTopLeft(x1 - deathXChange, y - deathHeightChange);
			image.OnShow();
		}
		//���`�N����ܦb�e��
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

		if (((neko->GetX1() + neko->GetHeadGap()) > x2 - headGap + range) || (neko->GetIsAlive() == false)){			//�P�_���L�I���M�Ĥ�O�_����
			x1 += moveSpeed;
			x2 += moveSpeed;
			OnMove();
			if (image.GetCurrentBitmapNumber() > walkAnimationEnd)		//�Y�樫�ʵe�����F�A���Y���@��
			{
				image.Reset();
				image.SetDelayCount(walkAnimationSpeed);				//�]�w����t��
			}
		}
		else {								//�p�G�I��}�l�i�����

			if (delay == 1) {			//�]�w������l�ʵe
				image.SetDelayCount(attackAnimationSpeed);		//�]�w����t��
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

	int rivalAnimation::GetHeadGap()
	{
		return headGap;
	}


	void rivalAnimation::die()
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