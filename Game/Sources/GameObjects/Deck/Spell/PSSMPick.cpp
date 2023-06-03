#include "PSSMPick.h"

PSSMPick::PSSMPick(IPMonster* monster)
{
	m_Monster = monster;
}

void PSSMPick::Init(string name)
{
	click1 = false;
	click2 = false;
	m_Animation = new Animation(*DATA->getTexture(name), sf::Vector2i(1, 1), 0.1f);
	m_Animation->setScale(1 / 6.f, 1 / 6.f);
	m_Animation->setPosition(750.f, 400.f);
	m_Button2 = new Animation(*DATA->getTexture("Icon/Hex/Attack"), sf::Vector2i(1, 1), 0.1f);
	m_Button2->setScale(1 / 4.f, 1 / 4.f);
	m_Button1 = new Animation(*DATA->getTexture("Icon/Hex/Place"), sf::Vector2i(1, 1), 0.1f);
	m_Button1->setScale(1 / 4.f, 1 / 4.f);
}

void PSSMPick::Update(float deltaTime, HitBox* hitBox)
{
	//cout << 1;
	m_Animation->Update(deltaTime);
	m_Animation->setPosition(m_Monster->getHitBox()->getPosition());
	m_Button1->setPosition(m_Animation->getPosition().x, m_Animation->getPosition().y + 50.f);
	m_Button2->setPosition(m_Animation->getPosition().x + 50.f, m_Animation->getPosition().y - 50.f);

	if (hitBox->isTurn() == 3) {
		if (m_Animation->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow()))) {
			m_Animation->setScale(1 / 3.f, 1 / 3.f);

			if (m_Monster->getHitBox()->getTag() == PLAYER || m_Monster->getHitBox()->getTag() == ENEMY) {
				click1 = true;
				if (m_Button1->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow()))) {
					m_Button1->setScale(1 / 3.f, 1 / 3.f);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						m_Monster->changeNextState(IPMState::MOVE);
					}
				}
				else m_Button1->setScale(1 / 4.f, 1 / 4.f);

			}

			if (m_Monster->getHitBox()->getTag() == E_ZONE) {
				click2 = true;
				if (m_Button2->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow()))) {
					m_Button2->setScale(1 / 3.f, 1 / 3.f);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						m_Monster->changeNextState(IPMState::ATTACK);
					}
				}
				else if (!m_Monster->getHitBox()->isAttack()) m_Button2->setScale(1 / 4.f, 1 / 4.f);
			}


		}
		else {
			m_Animation->setScale(1 / 6.f, 1 / 6.f);
			click1 = false;
			click2 = false;
		}
	}
	sf::Vector2f x = m_Animation->getPosition();
	if (m_Animation->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow())) && sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		m_Animation->setScale(1, 1);
		m_Animation->setPosition(screenWidth / 2, screenHeight / 2);
	}
	else {
		m_Animation->setScale(1 / 6.f, 1 / 6.f);
		m_Animation->setPosition(x);
	}
}

void PSSMPick::Render(sf::RenderWindow* window)
{
	if (m_Monster->getHitBox()->isAlive()) window->draw(*m_Animation);
	if (click1) window->draw(*m_Button1);
	if (click2) window->draw(*m_Button2);
}

void PSSMPick::Reset()
{
	delete m_Sprite;
}