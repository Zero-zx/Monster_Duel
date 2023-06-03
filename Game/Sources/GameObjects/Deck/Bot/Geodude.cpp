#include "Geodude.h"
#include "PSUpb1.h"
#include "PSBDown.h"
#include "PSBMAttack.h"
#include "PSBMMove.h"
#include "PSBMPick.h"

Geodude::Geodude()
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

void Geodude::Init()
{
	string name = "Bot/Geodude";
	m_upState->Init(name);
	m_downState->Init(name);
	m_pickState->Init(name);
	m_attackState->Init(name);
	m_deathState->Init(name);
	m_moveState->Init(name);

	m_HitBox = new HitBox(sf::Vector2i(421 / 5, 614 / 5));
	m_HitBox->setPosition(1189.f, 280.f);
	m_HitBox->setAtk(700);
	m_HitBox->setDef(2000);
	m_HitBox->setType(TYPE::ROCK);
	m_HitBox->setTag(E_MON);
	m_HitBox->setAlive(true);
	m_HitBox->setTurn(false);
	//m_HitBox->setLP(8000);
}
