#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "dogeAnimation.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// class dogeAnimation ���J�ʵe���禡�w�q
	/////////////////////////////////////////////////////////////////////////////

	dogeAnimation::dogeAnimation() {
		x = y = 0;
	}

	void dogeAnimation::LoadBitmap() {
		image.AddBitmap(IDB_doge0, RGB(255, 0, 0));				//���J���J�ʵe�Ϥ�0
		image.AddBitmap(IDB_doge1, RGB(255, 0, 0));				//���J���J�ʵe�Ϥ�1
		image.AddBitmap(IDB_doge2, RGB(255, 0, 0));				//���J���J�ʵe�Ϥ�2
		image.AddBitmap(IDB_doge3, RGB(255, 0, 0));				//���J���J�ʵe�Ϥ�3
		image.SetDelayCount(5);									//���J�ʵe�ഫ����t��
	}

	void dogeAnimation::OnMove() {
		image.OnMove();											//���J�ʵe�}�l�ܴ�
	}

	void dogeAnimation::OnShow() {
		image.SetTopLeft(x, y);									// �]�w���J�y��
		image.OnShow();											//�K�W���J
	}

	int dogeAnimation::GetX()									//���oX�y��
	{
		return x;
	}

	int dogeAnimation::GetY()									//���oY�y��
	{
		return y;
	}

	void dogeAnimation::SetCoordinate(int NewX, int NewY)		//�]�w�y��
	{
		x = NewX;
		y = NewY;
	}

	void dogeAnimation::MoveForward()
	{
		if (x < 1522) {
			x += 5;
		}
	}
}