#include "GameStateBase.h"
#include "GSIntro.h"
#include "GSMenu.h"
#include "GSPlay.h"
#include "GSWEnd.h"
#include "GSLEnd.h"
#include "GSAbout.h"
#include "GSSetting.h"


GameStateBase* GameStateBase::CreateState(StateTypes st)
{
	GameStateBase* gs = nullptr;
	switch (st)
	{
	case INVALID:
		break;
	case INTRO:
		gs = new GSIntro();
		break;
	case MENU:
		gs = new GSMenu();
		break;
	case PLAY:
		gs = new GSPlay();
		break;
	case W_END:
		gs = new GSWEnd();
		break;
	case L_END:
		gs = new GSLEnd();
		break;
	case SETTING:
		gs = new GSSetting();
		break;
	case ABOUT:
		gs = new GSAbout();
		break;
	default:
		break;
	}
	return gs;
}
