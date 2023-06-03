#pragma once
#include "IPMState.h"
#include "../HitBox.h"


class IPMonster {
public:
	virtual void changeNextState(IPMState::STATE nextState) = 0;
	virtual HitBox* getHitBox() = 0;

	virtual void setPick(bool pick) = 0;
	virtual bool isPick() = 0;

};