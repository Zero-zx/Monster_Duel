#include "End.h"


End::End()
{


}

End::~End()
{

}


void End::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Icon/Hex/End"), sf::Vector2i(1, 1), 0.1f);
	m_Animation->setScale(0.4f, 0.4f);
	m_Turn.setFont(*DATA->getFont("FORTZ"));
	m_Turn.setFillColor(sf::Color::Yellow);
	m_Turn.setOutlineThickness(3.f);
	m_Turn.setOutlineColor(sf::Color::Black);
	m_Turn.setString("Your Turn");
	m_Turn.setScale(2.f, 2.f);
	sf::FloatRect textRect = m_Turn.getLocalBounds();
	m_Turn.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	m_Turn.setPosition(screenWidth / 2, screenHeight / 2);

	m_HitBox = new HitBox(sf::Vector2i(210 * 0.4, 240 * 0.4));
	m_HitBox->setPosition(screenWidth / 2 + 200, screenHeight / 2);
	m_HitBox->setTag(NEXT);
}

void End::Update(float deltaTime)
{
	m_Animation->setPosition(m_HitBox->getPosition());

	if (m_Animation->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow()))) {
		m_Animation->setScale(0.5f, 0.5f);
	}
	else m_Animation->setScale(0.4f, 0.4f);
}

void End::Render(sf::RenderWindow* window)
{
	//window->draw(*m_HitBox);
	window->draw(*m_Animation);
}

HitBox* End::getHitBox()
{
	return m_HitBox;
}