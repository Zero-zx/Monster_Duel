#include "HitBox.h"

HitBox::HitBox(sf::Vector2i size) : RectangleShape((sf::Vector2f)size)
{
	this->setOrigin((sf::Vector2f)size / 2.f);
	this->setFillColor(sf::Color(0, 0, 0, 0));
	this->setOutlineThickness(1.f);
	this->setOutlineColor(sf::Color::Red);
	m_Turn = 0;
	m_isSkip = false;
	m_isAttack = false;
	m_Atk = m_Def = 0;
	m_isAlive = true;
	m_isDef = false;
	m_Type = TYPE::TNULL;
	m_hadAttack = 1;
}

HitBox::~HitBox()
{

}
