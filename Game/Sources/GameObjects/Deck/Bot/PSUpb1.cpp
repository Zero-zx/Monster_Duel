#include "PSUpb1.h"

PSUpb1::PSUpb1(IPMonster* monster)
{
	m_Monster = monster;
}

void PSUpb1::Init(string name)
{
	m_Animation = new Animation(*DATA->getTexture("CardDown/Back"), sf::Vector2i(1, 1), 0.1f);
	m_Animation->setScale(1 / 5.f, 1 / 5.f);
	m_Name = name;
	//m_Animation->setPosition(900.f, 400.f);
}

void PSUpb1::Update(float deltaTime, HitBox* hitBox)
{
	m_Animation->Update(deltaTime);
	m_Animation->setPosition(m_Monster->getHitBox()->getPosition());


	if (m_Animation->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow()))) {
		m_Animation->setTexture(*DATA->getTexture(m_Name));
		m_Animation->setScale(1 / 4.f, 1 / 4.f);
		if (!hitBox->isSkip() && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			DATA->removeMusic("click");
			DATA->playMusic("click");
			hitBox->setSkip(true);
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
	sf::Vector2f x = m_Animation->getPosition();
	if (m_Animation->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow())) && sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		DATA->removeMusic("click");
		DATA->playMusic("click");
		m_Animation->setScale(1, 1);
		m_Animation->setPosition(screenWidth / 2, screenHeight / 2);
	}
	else {
		if (hitBox->isTurn() == 3) m_Animation->setScale(1 / 6.f, 1 / 6.f);
		m_Animation->setPosition(x);
	}
}

void PSUpb1::Render(sf::RenderWindow* window)
{
	if (m_Monster->getHitBox()->isAlive()) window->draw(*m_Animation);
}

void PSUpb1::Reset()
{
	delete m_Sprite;
}
