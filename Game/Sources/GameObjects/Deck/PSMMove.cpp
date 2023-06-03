#include "PSMMove.h"

PSMMove::PSMMove(IPMonster* player)
{
	m_Monster = player;
}

void PSMMove::Init(string name)
{
	isSet = false;
	m_Animation = new Animation(*DATA->getTexture(name), sf::Vector2i(1, 1), 0.1f);
	m_Animation->setScale(1 / 5.f, 1 / 5.f);
	m_Animation->setPosition(750.f, 400.f);
}

void PSMMove::Update(float deltaTime, HitBox* hitBox)
{
	m_Animation->Update(deltaTime);
	m_Animation->setPosition(m_Monster->getHitBox()->getPosition());
	if ((m_Monster->getHitBox()->getTag() != B_ZONE && m_Monster->getHitBox()->getTag() != E_ZONE) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		m_Animation->setPosition(sf::Mouse::getPosition(*WConnect->getWindow()).x, sf::Mouse::getPosition(*WConnect->getWindow()).y);
		m_Monster->getHitBox()->setPosition(sf::Mouse::getPosition(*WConnect->getWindow()).x, sf::Mouse::getPosition(*WConnect->getWindow()).y);
	}
	else {
		m_Monster->changeNextState(PICK);
	}
}

void PSMMove::Render(sf::RenderWindow* window)
{
	if (m_Monster->getHitBox()->isAlive()) window->draw(*m_Animation);
}

void PSMMove::Reset()
{
	delete m_Sprite;
}