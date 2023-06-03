#include "PSUpS.h"

PSUpS::PSUpS(IPMonster* monster)
{
	m_Monster = monster;
}

void PSUpS::Init(string name)
{
	m_Animation = new Animation(*DATA->getTexture("CardDown/Back"), sf::Vector2i(1, 1), 0.1f);
	m_Animation->setScale(1 / 5.f, 1 / 5.f);
	//m_Animation->setPosition(900.f, 400.f);
}

void PSUpS::Update(float deltaTime, HitBox* HitBox)
{
	m_Animation->Update(deltaTime);
	

	if (m_Animation->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow()))) {
		m_Animation->setTexture(*DATA->getTexture("Bot/Rattata"));
		m_Animation->setScale(1 / 4.f, 1 / 4.f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			m_Monster->getHitBox()->setPosition(820.f, 200.f);
			m_Animation->setScale(1 / 6.f, 1 / 6.f);
			m_Monster->setPick(true);
			m_Monster->getHitBox()->setTag(ENEMY);
			m_Monster->changeNextState(PICK);
		}
	}
	else {
		m_Animation->setScale(1 / 6.f, 1 / 6.f);
		if(!m_Monster->isPick()) m_Monster->changeNextState(IPMState::DOWN);
	}
	m_Animation->setPosition(m_Monster->getHitBox()->getPosition());
}

void PSUpS::Render(sf::RenderWindow* window)
{
	if (m_Monster->getHitBox()->isAlive()) window->draw(*m_Animation);
}

void PSUpS::Reset()
{
	delete m_Sprite;
}
