#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "stageImformation.h"

namespace game_framework {

	/////////////////////////////////////////////////////////////////////////////
	// stageImformation:�o��class�������d��T����O
	// 
	// 
	/////////////////////////////////////////////////////////////////////////////

	stageImformation::stageImformation()
	{
		
	}

	char* stageImformation::getStageBackground(int stage)
	{
		return stageBackGround[stage-1];
	}

	string stageImformation::getRivalBase(int stage)
	{
		return stageRivalBase[stage-1];
	}

	char * stageImformation::getMusic(int stage)
	{
		return stageMusic[stage-1];
	}

	char * stageImformation::getStageName(int stage)
	{
		return stageName[stage-1];
	}

}