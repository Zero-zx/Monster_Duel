#include "GSAbout.h"

GSAbout::GSAbout()
{
}

GSAbout::~GSAbout()
{
}

void GSAbout::Exit()
{
}

void GSAbout::Pause()
{
}

void GSAbout::Resume()
{
}

void GSAbout::Init()
{
	GameButton* button;
	//close Button
	button = new GameButton();
	button->Init("close");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth - screenWidth / 20, screenHeight / 8);
	button->setOnClick([]() {GSM->PopState(); });
	m_ListBtn.push_back(button);

	//Background
	sf::Texture* texture = DATA->getTexture("MenuBack");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setScale(0.5f, 0.5f);
	m_Background.setPosition(screenWidth / 2, screenHeight / 2);;

	texture = DATA->getTexture("Element");
	m_sprite.setTexture(*texture);
	m_sprite.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_sprite.setScale(0.5f, 0.5f);
	m_sprite.setPosition(screenWidth / 2, screenHeight / 2 + 160);

	//Tile Game
	m_Title.setString("The affection of diffirent elements:");
	m_Title.setFont(*DATA->getFont("FORTZ"));
	m_Title.setScale(2, 2);
	m_Title.setFillColor(sf::Color::Yellow);
	m_Title.setOutlineThickness(3.f);
	m_Title.setFillColor(sf::Color::Blue);
	m_Title.setPosition(screenWidth / 2 - m_Title.getGlobalBounds().width/2, screenHeight / 5);
}

void GSAbout::Update(float deltaTime)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSAbout::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
	window->draw(m_sprite);
	window->draw(m_Title);
}