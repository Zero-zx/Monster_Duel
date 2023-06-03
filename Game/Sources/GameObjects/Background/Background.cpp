#include "Background.h"

//1700, 970
//1024,820

void Background::Init()
{
	sf::Texture* texture = DATA->getTexture("Field");
	m_image.setTexture(*texture);
	m_SizeImage = (sf::Vector2i) texture->getSize();
	m_image.setOrigin(-338,-75);

	m_hitBox = new HitBox(sf::Vector2i(m_SizeImage));
	m_hitBox->setOrigin(-338, -75);
	m_hitBox->setTag(ZONE);

	texture = DATA->getTexture("Back2");
	m_back.setTexture(*texture);
	m_back.setPosition(10, 0);
	m_back.setScale(1.4, 1.4);
}

void Background::Update(float deltaTime)
{

}

void Background::Render(sf::RenderWindow* window)
{
	window->draw(m_back);
	window->draw(m_image);
	//window->draw(*m_hitBox);
}
