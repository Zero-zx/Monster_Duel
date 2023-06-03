#include "Bulbasaur.h"
#include "PSUp1.h"
#include "PSMDefense.h"


Bulbasaur::Bulbasaur()
{
	m_Pick = false;
	m_nextState = IPMState::SNULL;
	m_downState = new PSDown(this);
	m_attackState = new PSMAttack(this);
	m_moveState = new PSMMove(this);
	m_pickState = new PSMPick(this);
	m_deathState = new PSMDefense(this);
	m_upState = new PSUp1(this);
	m_currentState = m_downState;

}

void Bulbasaur::Init()
{
	string name = "Stater/Bulbasaur";
	m_upState->Init(name);
	m_downState->Init(name);
	m_pickState->Init(name);
	m_attackState->Init(name);
	m_moveState->Init(name);
	m_deathState->Init(name);

	m_HitBox = new HitBox(sf::Vector2i(421 / 5, 614 / 5));
	m_HitBox->setPosition(502.f, 690.f);
	m_HitBox->setAtk(1300);
	m_HitBox->setDef(1300);
	m_HitBox->setType(TYPE::GRASS);
	m_HitBox->setTag(M_MON);
	//m_HitBox->setLP(8000);
}
