#include "Magikarp.h"
#include "PSUpb1.h"
#include "PSBDown.h"
#include "PSBMAttack.h"
#include "PSBMMove.h"
#include "PSBMPick.h"

Magikarp::Magikarp()
{
	m_Pick = false;
	m_nextState = IPMState::SNULL;
	m_downState = new PSBDown(this);
	m_attackState = new PSBMAttack(this);
	m_moveState = new PSBMMove(this);
	m_pickState = new PSBMPick(this);
	m_upState = new PSUpb1(this);
	m_deathState = new PSDeath(this);
	m_currentState = m_downState;

}

void Magikarp::Init()
{
	string name = "Bot/Magikarp";
	m_upState->Init(name);
	m_downState->Init(name);
	m_pickState->Init(name);
	m_attackState->Init(name);
	m_deathState->Init(name);
	m_moveState->Init(name);

	m_HitBox = new HitBox(sf::Vector2i(421 / 5, 614 / 5));
	m_HitBox->setPosition(502.f, 148.f);
	m_HitBox->setAtk(0);
	m_HitBox->setDef(500);
	m_HitBox->setType(TYPE::WATER);
	m_HitBox->setTag(E_MON);
	m_HitBox->setAlive(true);
	m_HitBox->setTurn(false);
	//m_HitBox->setLP(8000);
}
