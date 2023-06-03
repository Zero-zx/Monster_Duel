#include "PSMDefense.h"

PSMDefense::PSMDefense(IPMonster* monster)
{
	m_Monster = monster;
}

void PSMDefense::Init(string name)
{
	isSet = false;
	m_Animation = new Animation(*DATA->getTexture(name), sf::Vector2i(1, 1), 0.1f);
	m_Animation->setScale(1 / 5.f, 1 / 5.f);
	m_Animation->setPosition(750.f, 400.f);
}

void PSMDefense::Update(float deltaTime, HitBox* hitBox)
{
	m_Animation->Update(deltaTime);

	//if(!m_Monster->getHitBox()->isDefend()) m_Animation->rotate(90.f);
	m_Monster->getHitBox()->setDefend(true);
	m_Monster->changeNextState(PICK);
	cout << 1 << endl;

	m_Animation->setPosition(m_Monster->getHitBox()->getPosition());

}

void PSMDefense::Render(sf::RenderWindow* window)
{
	if (m_Monster->getHitBox()->isAlive()) window->draw(*m_Animation);
}

void PSMDefense::Reset()
{
	delete m_Sprite;
}