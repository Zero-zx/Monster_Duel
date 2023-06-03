#include "Death.h"

PSDeath::PSDeath(IPMonster* monster)
{
	m_Monster = monster;
	m_timeRemain = 2.f;

}

void PSDeath::Init(string name)
{
	m_Animation = new Animation(*DATA->getTexture("Explosion"), sf::Vector2i(4, 4), 0.1f);
	m_Animation->setModeEndFrame(true);
}

void PSDeath::Update(float deltaTime, HitBox* hitBox)
{
	m_currentTime += deltaTime;
	if (m_currentTime >= m_timeRemain) {
		delete m_Animation;
	}
	m_Animation->Update(deltaTime);
	m_Animation->setPosition(m_Monster->getHitBox()->getPosition());
}

void PSDeath::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSDeath::Reset()
{
	m_currentTime = 0;
	m_Animation->Reset();
}
