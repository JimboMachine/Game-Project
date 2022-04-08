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
		x = y = 0;
	}

	void rivalAnimation::LoadBitmap() {
		image.AddBitmap(IDB_doge0, RGB(255, 0, 0));				//���J���J�ʵe�Ϥ�0
		image.AddBitmap(IDB_doge1, RGB(255, 0, 0));				//���J���J�ʵe�Ϥ�1
		image.AddBitmap(IDB_doge2, RGB(255, 0, 0));				//���J���J�ʵe�Ϥ�2
		image.AddBitmap(IDB_doge3, RGB(255, 0, 0));				//���J���J�ʵe�Ϥ�3
		image.SetDelayCount(5);									//���J�ʵe�ഫ����t��
	}

	void rivalAnimation::OnMove() {
		image.OnMove();											//���J�ʵe�}�l�ܴ�
	}

	void rivalAnimation::OnShow() {
		image.SetTopLeft(x, y);									// �]�w���J�y��
		image.OnShow();											//�K�W���J
	}

	int rivalAnimation::GetX()									//���oX�y��
	{
		return x;
	}

	int rivalAnimation::GetY()									//���oY�y��
	{
		return y;
	}

	void rivalAnimation::SetCoordinate(int NewX, int NewY)		//�]�w�y��
	{
		x = NewX;
		y = NewY;
	}

	void rivalAnimation::MoveForward(nekoAnimation neko)
	{
		if (neko.GetX1() > x) {
			x += 5;
		}
	}

}