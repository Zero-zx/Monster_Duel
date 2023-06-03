#pragma once
#include "IPMonster.h"
#include "PSDown.h"
#include "PSMAttack.h"
#include "PSMMove.h"
#include "Death.h"
#include "PSMPick.h"

class Card : public IPMonster {
public:
	Card();
	~Card();
	virtual void changeNextState(IPMState::STATE nextState);

	virtual void Init();
	virtual void Update(float deltaTime, HitBox* HitBox);
	void Render(sf::RenderWindow* window);

	void setPick(bool pick) { m_Pick = pick; };
	bool isPick() { return m_Pick; };



	HitBox* getHitBox();
protected:
	void performStateChange();
	HitBox* m_HitBox;
	bool m_Pick;
	TYPE m_Type;

	int m_Atk;
	int m_Def;

	IPMState::STATE m_nextState;

	IPMState* m_currentState;
	IPMState* m_downState;
	IPMState* m_upState;
	IPMState* m_pickState;
	IPMState* m_moveState;
	IPMState* m_attackState;
	IPMState* m_deathState;


};