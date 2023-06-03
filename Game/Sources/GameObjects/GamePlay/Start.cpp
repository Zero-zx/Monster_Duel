#include "Start.h"


Start::Start()
{


}

Start::~Start()
{

}


void Start::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Icon/Hex/Draw"), sf::Vector2i(1, 1), 0.1f);
	m_Animation->setScale(0.4f, 0.4f);

	m_HitBox = new HitBox(sf::Vector2i(210 * 0.4, 240 * 0.4));
	m_HitBox->setPosition(screenWidth / 2 - 205, screenHeight / 2);
	m_HitBox->setTag(DRAW);
}

void Start::Update(float deltaTime)
{
	m_Animation->setPosition(m_HitBox->getPosition());

	if (m_Animation->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow()))) {
		m_Animation->setScale(0.5f, 0.5f);
	}
	else m_Animation->setScale(0.4f, 0.4f);
}

void Start::Render(sf::RenderWindow* window)
{
	//window->draw(*m_HitBox);
	window->draw(*m_Animation);
}

HitBox* Start::getHitBox()
{
	return m_HitBox;
}