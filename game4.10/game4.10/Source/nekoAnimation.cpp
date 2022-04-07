#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "nekoAnimation.h"


namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// class nekoAnimation �߫}�ʵe���禡�w�q
	/////////////////////////////////////////////////////////////////////////////
	
	nekoAnimation::nekoAnimation()
	{
		x = y = 0;
	}

	void nekoAnimation::LoadBitmap()
	{
		image.AddBitmap(IDB_neko0, RGB(255, 0, 0));				//���J�߫}�ʵe�Ϥ�0
		//image.AddBitmap(IDB_neko1, RGB(255, 0, 0));				//���J�߫}�ʵe�Ϥ�1
		image.AddBitmap(IDB_neko2, RGB(255, 0, 0));				//���J�߫}�ʵe�Ϥ�2
		image.AddBitmap(IDB_neko3, RGB(255, 0, 0));				//���J�߫}�ʵe�Ϥ�3
		image.AddBitmap(IDB_neko4, RGB(255, 0, 0));				//���J�߫}�ʵe�Ϥ�4
		image.SetDelayCount(3);									//�߫}�ʵe�ഫ����t��
	}

	void nekoAnimation::OnMove()
	{
		image.OnMove();											//�߫}�ʵe�}�l�ܴ�
	}

	void nekoAnimation::OnShow()
	{
		image.SetTopLeft(x, y);								// �]�w�߫}�y��
		image.OnShow();											//�K�W�߫}
	}

	int nekoAnimation::GetX()								//���oX�y��
	{
		return x;
	}

	int nekoAnimation::GetY()								//���oY�y��
	{
		return y;
	}

	void nekoAnimation::SetCoordinate(int NewX, int NewY)		//�]�w�y��
	{
		x = NewX;
		y = NewY;
	}

	void nekoAnimation::MoveForward()
	{
		if (x > 285) {
			x -= 3;
		}
	}



}