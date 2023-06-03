#include "PSBMAttack.h"

PSBMAttack::PSBMAttack(IPMonster* monster)
{
	m_Monster = monster;
}

void PSBMAttack::Init(string name)
{
	m_Index.setFont(*DATA->getFont("FORTZ"));
	m_Index.setFillColor(sf::Color::Yellow);
	m_Index.setOutlineThickness(3.f);
	m_Index.setOutlineColor(sf::Color::Black);
	m_Index.setScale(0.5f, 0.5f);


	isSet = false;
	m_Animation = new Animation(*DATA->getTexture(name), sf::Vector2i(1, 1), 0.1f);
	m_Animation->setScale(1 / 6.f, 1 / 6.f);
}

void PSBMAttack::Update(float deltaTime, HitBox* hitBox)
{

	m_Animation->Update(deltaTime);

	m_Index.setPosition(m_Animation->getPosition().x - 40, m_Animation->getPosition().y - 80.f);
	m_Index.setString(to_string(m_Monster->getHitBox()->getAtk()) + " / " + to_string(m_Monster->getHitBox()->getDef()));

	if (hitBox->isTurn() == 3 && m_Monster->getHitBox()->hadAttack()) {
		m_Monster->getHitBox()->setAttack(true);
	}
	else {
		m_Monster->getHitBox()->setAttack(false);
		m_Monster->changeNextState(PICK);
	}
	
	
	m_Animation->setPosition(m_Monster->getHitBox()->getPosition());

}

void PSBMAttack::Render(sf::RenderWindow* window)
{
	if(m_Monster->getHitBox()->isAlive()) window->draw(*m_Animation);
	window->draw(m_Index);
}

void PSBMAttack::Reset()
{
	delete m_Sprite;
}