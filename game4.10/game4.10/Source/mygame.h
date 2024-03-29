/*
 * mygame.h: 本檔案儲遊戲本身的class的interface
 * Copyright (C) 2002-2008 Woei-Kae Chen <wkc@csie.ntut.edu.tw>
 *
 * This file is part of game, a free game development framework for windows.
 *
 * game is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * game is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *   2005-09-13
 *      Rewrite the codes for CBall and CEraser.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *   2006-02-08 V4.2
 *      1. Rename OnInitialUpdate() -> OnInit().
 *      2. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      3. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress.
*/

#include "CEraser.h"
#include "CBall.h"
#include "CBouncingBall.h"
#include "rivalAnimation.h"
#include "nekoAnimation.h"
#include "ImageNumber.h"
#include "nekoButton.h"
#include "maxNumber.h"
#include "levelUpButton.h"
#include "nekoDetector.h"
#include "rivalDetector.h"
#include "stageSelector.h"
#include "stageImformation.h" 

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// Constants
	/////////////////////////////////////////////////////////////////////////////

	enum AUDIO_ID {				// 定義各種音效的編號
		AUDIO_DING,				// 0
		AUDIO_LAKE,				// 1
		AUDIO_BackgroundMusic,	// 2   背景音樂
		AUDIO_Beginning,		// 3   開頭音樂
		AUDIO_Victory,			// 4   勝利音效
		AUDIO_Defeat,			// 5   失敗音效
		AUDIO_Stage				// 6   選擇關卡音樂
	};
	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲開頭畫面物件
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateInit : public CGameState {
	public:
		CGameStateInit(CGame *g);
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnKeyUp(UINT, UINT, UINT); 				// 處理鍵盤Up的動作
		void OnLButtonUp(UINT nFlags, CPoint point);  // 處理滑鼠的動作
	protected:
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		CMovingBitmap logo;								// csie的logo
		CMovingBitmap MainMenu;							// 主畫面圖片
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲說明
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateAbout : public CGameState {
	public:
		CGameStateAbout(CGame *g);
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
	protected:
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		CMovingBitmap about;							// 說明圖片
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲選擇關卡
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateStageSelect : public CGameState {
	public:
		CGameStateStageSelect(CGame *g);
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnKeyUp(UINT, UINT, UINT); 				// 處理鍵盤Up的動作
		void OnLButtonUp(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		stageSelector stageSelect;						// 選擇關卡的功能
	protected:
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		CMovingBitmap SelectStageMenu;					// 關卡選擇畫面圖片
		CMovingBitmap back;								// 返回圖片
		CMovingBitmap start;							// 開始戰鬥圖片
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateRun : public CGameState {
	public:
		CGameStateRun(CGame *g);
		~CGameStateRun();
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT);
		void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnLButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
		void OnMouseMove(UINT nFlags, CPoint point);	// 處理滑鼠的動作 
		void OnRButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnRButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		const int		NUMBALLS;	// 球的總數
		CMovingBitmap	background;	// 學校圖
		CMovingBitmap	help;		// 說明圖
		CBall			*ball;		// 球的陣列
		CMovingBitmap	corner;		// 角落圖
		CEraser			eraser;		// 拍子
		CInteger		hits_left;	// 剩下的撞擊數
		CBouncingBall   bball;		// 反覆彈跳的球
		CMovingBitmap	Mybase;		// 我方砲塔
		CMovingBitmap	Rivalbase;	// 敵方砲塔
		CMovingBitmap   giant;      // 巨神貓
		nekoAnimation   neko;		// 貓咪
		nekoAnimation	neko2;		// 第二隻貓咪
		rivalAnimation  doge;		// 狗仔
		nekoAnimation	*Neko;		// 貓咪陣列
		rivalAnimation  *Rival;		// 敵人陣列
		const int		maxNeko;	// 貓咪的最大數量
		const int		maxRival;	// 敵人的最大數量
		ImageNumber		currentMoney; //現有的錢
		nekoButton		Button;		//角色按鈕
		int	activateNeko;				//正在執行onShow，moveForward，loadBitmap的角色數量
		int	currentNekoQuantity;		//目前畫面上的貓咪數量
		int readyToFightNeko;			//即將出動的貓咪(此為Neko陣列中的第N個貓咪)
		int	activateRival;				//正在執行onShow，moveForward，loadBitmap的角色數量
		int	currentRivalQuantity;		//目前畫面上的敵人數量
		int readyToFightRival;			//即將出動的敵人(此為Rival陣列中的第N個敵人)
		CMovingBitmap	MaxNekoText;	//無法出擊文字
		maxNumber		maxMoney;	//最大金額
		levelUpButton	workCat;	//工作貓按鈕
		int moneyDelay;				//金錢增加速度延遲(可調整)
		nekoDetector	NekoDetector;//偵測哪隻貓咪要設為目標
		rivalDetector	RivalDetector;//偵測哪隻敵方要設為目標
		int rivalDelay;				//派出敵人的延遲時間
		stageImformation stageData;	//關卡資訊
		CMovingBitmap	stopButton;	//退出遊戲按鈕	
		CMovingBitmap	RivalWinButton;	//RivalWin按鈕	
		CMovingBitmap	CatWinButton;	//CatWin按鈕	
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的結束狀態(Game Over)
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateOver : public CGameState {
	public:
		CGameStateOver(CGame *g);
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		int counter;	// 倒數之計數器
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的結束狀態貓咪獲勝
	/////////////////////////////////////////////////////////////////////////////
	class CGameStateNekoWin : public CGameState {
	public:
		CGameStateNekoWin(CGame *g);
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
		void OnLButtonUp(UINT nFlags, CPoint point);  // 按鈕
	private:
		int counter;	// 倒數之計數器
		CMovingBitmap winPhoto;							// 勝利圖片
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的結束狀態敵人獲勝
	/////////////////////////////////////////////////////////////////////////////
	class CGameStateRivalWin : public CGameState {
	public:
		CGameStateRivalWin(CGame *g);
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
		void OnLButtonUp(UINT nFlags, CPoint point);  // 按鈕
	private:
		int counter;	// 倒數之計數器
		CMovingBitmap winPhoto;							// 勝利圖片
	};
}