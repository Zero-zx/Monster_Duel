#include "PSDown.h"

PSDown::PSDown(IPMonster* monster)
{
	m_Monster = monster;
}

void PSDown::Init(string name)
{
	m_Animation = new Animation(*DATA->getTexture("CardDown/Back"), sf::Vector2i(1, 1), 0.1f);
	m_Animation->setScale(1 / 5.f, 1 / 5.f);
	m_Animation->setPosition(900.f, 400.f);
}

void PSDown::Update(float deltaTime, HitBox* hitBox)
{
	m_Animation->Update(deltaTime);
	
	if (hitBox->isTurn() == 1 && !m_Monster->isPick() && m_Animation->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow()))) {
		m_Monster->changeNextState(IPMState::UP);
	}
	else {
		m_Animation->setScale(1 / 5.f, 1 / 5.f);
	}
	m_Animation->setPosition(m_Monster->getHitBox()->getPosition());
}

void PSDown::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSDown::Reset()
{
	delete m_Sprite;
}
