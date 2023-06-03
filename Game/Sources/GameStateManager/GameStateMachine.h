#pragma once
#include "../GameManager/Singleton.h"
#include <list>
#include "../GameObjects/ScoreManager.h"
#include "../GameObjects/GameButton.h"

#define GSM GameStateMachine::GetInstance()

class GameStateBase;

enum StateTypes
{
	INVALID = 0,
	INTRO,
	MENU,
	PLAY,
	SETTING,
	ABOUT,
	HIGHSCORE,
	W_END,
	L_END,
};

class GameStateMachine :public CSingleton<GameStateMachine> {
public:
	GameStateMachine();
	~GameStateMachine();

	void ChangeState(GameStateBase* state);
	void ChangeState(StateTypes st);
	void PushState(StateTypes st);
	void PopState();

	void PerformStateChange();

	GameStateBase* currentState() const;
	GameStateBase* nextState() const;
	bool NeedToChangeState();
	bool HasState();


private:
	std::list<GameStateBase*> m_StateStack;
	GameStateBase* m_ActivesState;
	GameStateBase* m_NextState;
};