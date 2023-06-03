#include "PSSMAttack.h"

PSSMAttack::PSSMAttack(IPMonster* monster)
{
	m_Monster = monster;
}

void PSSMAttack::Init(string name)
{
	isSet = false;
	m_Animation = new Animation(*DATA->getTexture(name), sf::Vector2i(1, 1), 0.1f);
	m_Animation->setScale(1 / 5.f, 1 / 5.f);
	m_Animation->setPosition(750.f, 400.f);
}

void PSSMAttack::Update(float deltaTime, HitBox* hitBox)
{
	m_Animation->Update(deltaTime);
	if (hitBox->isTurn() == 3) {
		m_Monster->getHitBox()->setAttack(true);
	}else m_Monster->getHitBox()->setAttack(false);
	
	
	m_Animation->setPosition(m_Monster->getHitBox()->getPosition());

}

void PSSMAttack::Render(sf::RenderWindow* window)
{
	if(m_Monster->getHitBox()->isAlive()) window->draw(*m_Animation);
}

void PSSMAttack::Reset()
{
	delete m_Sprite;
}