#include "Zone.h"

Zone::Zone()
{

}

Zone::~Zone()
{
	if (m_hitBox != nullptr) {
		delete m_hitBox;
	}
}

void Zone::Init()
{
	m_hitBox = new HitBox(sf::Vector2i(421 / 6, 614 / 6));
	m_hitBox->setPosition(0,0);
	m_hitBox->setTag(ZONE);
}

void Zone::Update(float delataTime)
{
	//m_currentAni->Update(delataTime);

}

void Zone::Render(sf::RenderWindow* window)
{
	//window->draw(*m_currentAni);
	//window->draw(*m_hitBox);
}
