#include "Cards.h"

Card::Card()
{
	//m_Pick = false;
	//m_nextState = IPMState::SNULL;
	/*m_downState = new PSDown(this);
	m_attackState = new PSMAttack(this);
	m_moveState = new PSMMove(this);
	m_pickState = new PSMPick(this);
	m_currentState = m_downState;*/
}

Card::~Card()
{
	
	if (m_downState != nullptr) {
		delete m_downState;
	}
	if (m_pickState != nullptr) {
		delete m_pickState;
	}
	if (m_moveState != nullptr) {
		delete m_moveState;
	}
	if (m_attackState != nullptr) {
		delete m_attackState;
	}
	m_currentState = nullptr;
}

void Card::changeNextState(IPMState::STATE nextState)
{
	m_nextState = nextState;
}

void Card::Init()
{
	
}

void Card::Update(float deltaTime, HitBox* HitBox)
{
	performStateChange();

	m_currentState->Update(deltaTime,  HitBox);
}

void Card::Render(sf::RenderWindow* window)
{
	m_currentState->Render(window);
	//window->draw(*m_HitBox);
}

HitBox* Card::getHitBox()
{
	return m_HitBox;
}

void Card::performStateChange()
{
	if (m_nextState != IPMState::SNULL) {
		switch (m_nextState)
		{
		case IPMState::UP:
			m_currentState = m_upState;
			break;
		case IPMState::DOWN:
			m_currentState = m_downState;
			break;
		case IPMState::PICK:
			m_currentState = m_pickState;
			break;
		case IPMState::ATTACK:
			m_currentState = m_attackState;
			break;
		case IPMState::MOVE:
			m_currentState = m_moveState;
			break;
		case IPMState::DEATH:
			m_currentState = m_deathState;
			break;
		case IPMState::SNULL:
			break;
		default:
			break;
		}
		m_nextState = IPMState::SNULL;
		m_currentState->Reset();
	}
}
