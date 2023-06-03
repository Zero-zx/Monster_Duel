#include "Chansey.h"
#include "PSUpS.h"
#include "PSSDown.h"
#include "PSSMAttack.h"
#include "PSSMMove.h"
#include "PSSMPick.h"

Chansey::Chansey()
{
	m_Pick = false;
	m_nextState = IPMState::SNULL;
	m_downState = new PSSDown(this);
	m_attackState = new PSSMAttack(this);
	m_moveState = new PSSMMove(this);
	m_pickState = new PSSMPick(this);
	m_upState = new PSUpS(this);
	m_currentState = m_downState;

}

void Chansey::Init()
{
	string name = "Spell/Heal";
	m_upState->Init(name);
	m_downState->Init(name);
	m_pickState->Init(name);
	m_attackState->Init(name);
	m_moveState->Init(name);

	m_HitBox = new HitBox(sf::Vector2i(421 / 5, 614 / 5));
	m_HitBox->setPosition(1189.f, 400.f);
	m_HitBox->setAtk(1200);
	m_HitBox->setDef(1000);
	m_HitBox->setType(TYPE::NORMAL);
	m_HitBox->setTag(E_MON);
	m_HitBox->setAlive(true);
	m_HitBox->setTurn(false);
	//m_HitBox->setLP(8000);
}
