#include "PSMPick.h"

PSMPick::PSMPick(IPMonster* monster)
{
	m_Monster = monster;
}

void PSMPick::Init(string name)
{
	click1 = false;
	click2 = false;
	click3 = false;

	m_Atk.setFont(*DATA->getFont("FORTZ"));
	m_Atk.setFillColor(sf::Color::Yellow);
	m_Atk.setOutlineThickness(3.f);
	m_Atk.setOutlineColor(sf::Color::Black);
	m_Atk.setScale(0.5f, 0.5f);
	m_Def.setFont(*DATA->getFont("FORTZ"));
	m_Def.setFillColor(sf::Color::Yellow);
	m_Def.setOutlineThickness(3.f);
	m_Def.setOutlineColor(sf::Color::Black);
	m_Def.setScale(0.5f, 0.5f);

	m_Animation = new Animation(*DATA->getTexture(name), sf::Vector2i(1, 1), 0.1f);
	m_Animation->setScale(1 / 6.f, 1 / 6.f);
	m_Animation->setPosition(750.f, 400.f);
	m_Button2 = new Animation(*DATA->getTexture("Icon/Hex/Attack"), sf::Vector2i(1, 1), 0.1f);
	m_Button2->setScale(1/4.f, 1/4.f);
	m_Button1 = new Animation(*DATA->getTexture("Icon/Hex/Place"), sf::Vector2i(1, 1), 0.1f);
	m_Button1->setScale(1 / 4.f, 1 / 4.f);
	m_Button3 = new Animation(*DATA->getTexture("Icon/Hex/Defense"), sf::Vector2i(1, 1), 0.1f);
	m_Button3->setScale(1 / 4.f, 1 / 4.f);
}

void PSMPick::Update(float deltaTime, HitBox* hitBox)
{
	m_Animation->Update(deltaTime);
	m_Animation->setPosition(m_Monster->getHitBox()->getPosition());
	m_Button1->setPosition(m_Animation->getPosition().x, m_Animation->getPosition().y + 50.f);
	m_Button2->setPosition(m_Animation->getPosition().x, m_Animation->getPosition().y - 50.f);
	m_Button3->setPosition(m_Animation->getPosition().x-30, m_Animation->getPosition().y - 50.f);
	m_Button2->setScale(1 / 6.f, 1 / 6.f);

	m_Atk.setPosition(m_Animation->getPosition().x-45, m_Animation->getPosition().y + 50.f);
	m_Atk.setString(to_string(m_Monster->getHitBox()->getAtk()) + " / ");
	m_Def.setPosition(m_Animation->getPosition().x + 6, m_Animation->getPosition().y + 50.f);
	m_Def.setString(to_string(m_Monster->getHitBox()->getDef()));

	click2 = false;

	if (hitBox->isTurn() == 1) {
		if (m_Animation->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow()))) {
			m_Animation->setScale(1 / 3.f, 1 / 3.f);

			if (m_Monster->getHitBox()->getTag() == PLAYER || m_Monster->getHitBox()->getTag() == ENEMY) {
				click1 = true;
				if (m_Button1->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow()))) {
					m_Button1->setScale(1 / 3.f, 1 / 3.f);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						DATA->removeMusic("click");
						DATA->playMusic("click");
						m_Monster->changeNextState(IPMState::MOVE);
					}
				}
				else m_Button1->setScale(1 / 4.f, 1 / 4.f);

			}

			if (m_Monster->getHitBox()->getTag() == B_ZONE && m_Monster->getHitBox()->hadAttack()) {
				click2 = true;
				if (m_Button2->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow()))) {
					m_Button2->setScale(1 / 3.f, 1 / 3.f);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						DATA->removeMusic("click");
						DATA->playMusic("click");
						m_Monster->changeNextState(IPMState::ATTACK);
					}
				}
				else if(!m_Monster->getHitBox()->isAttack()) m_Button2->setScale(1 / 4.f, 1 / 4.f);

				
			}
		}
		else {
			m_Animation->setScale(1 / 6.f, 1 / 6.f);
			click1 = false;
			click2 = false;
			click3 = false;
		}
	}

	

	sf::Vector2f x = m_Animation->getPosition();
	if (m_Animation->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow())) && sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		DATA->removeMusic("click");
		DATA->playMusic("click");
		m_Animation->setScale(1, 1);
		m_Animation->setPosition(screenWidth / 2, screenHeight / 2);
		click2 = false;
	}
	else {
		if(hitBox->isTurn() == 3) m_Animation->setScale(1 / 6.f, 1 / 6.f);
		m_Animation->setPosition(x);
	}
}

void PSMPick::Render(sf::RenderWindow* window)
{
	if(m_Monster->getHitBox()->isAlive()){
		if (m_Monster->getHitBox()->getTag() == B_ZONE) window->draw(m_Atk);
		if (m_Monster->getHitBox()->getTag() == B_ZONE) window->draw(m_Def);
	}


	if (m_Monster->getHitBox()->isAlive()) window->draw(*m_Animation);
	if(click1 && m_Monster->getHitBox()->getTag() != B_ZONE) window->draw(*m_Button1);
	if (click2) window->draw(*m_Button2);
}

void PSMPick::Reset()
{
}