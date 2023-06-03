#include "Player.h"


Player::Player()
{


}

Player::~Player()
{

}


void Player::Init()
{
	m_Turn.setFont(*DATA->getFont("FORTZ"));
	m_Turn.setFillColor(sf::Color::Yellow);
	m_Turn.setOutlineThickness(3.f);
	m_Turn.setOutlineColor(sf::Color::Black);
	m_Turn.setString("Your Turn");
	m_Turn.setScale(1.6f, 1.6f);
	sf::FloatRect textRect = m_Turn.getLocalBounds();
	m_Turn.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	m_Turn.setPosition(screenWidth / 2, screenHeight / 2);

	m_HitBox = new HitBox(sf::Vector2i(210 * 0.4, 240 * 0.4));
	m_HitBox->setTag(M_TURN);
	m_HitBox->setTurn(1);
}

void Player::Update(float deltaTime)
{
	if (m_HitBox->isTurn() == 1) m_Turn.setString("Your Turn");
	else if (m_HitBox->isTurn() == 3) m_Turn.setString("Enemy Turn");
	sf::FloatRect textRect = m_Turn.getLocalBounds();
	m_Turn.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	m_Turn.setPosition(screenWidth / 2, screenHeight / 2);

}

void Player::Render(sf::RenderWindow* window)
{
	window->draw(m_Turn);
	
}

HitBox* Player::getHitBox()
{
	return m_HitBox;
}