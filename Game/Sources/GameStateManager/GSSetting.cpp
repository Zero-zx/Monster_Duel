#include "GSSetting.h"

GSSetting::GSSetting()
{
}

GSSetting::~GSSetting()
{
}

void GSSetting::Exit()
{
}

void GSSetting::Pause()
{
}

void GSSetting::Resume()
{
}

void GSSetting::Init()
{
	GameButton* button;
	//close Button
	button = new GameButton();
	button->Init("close");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(50, 50));
	button->setPosition(screenWidth - screenWidth / 20, screenHeight / 8);
	button->setOnClick([]() {GSM->PopState(); DATA->playMusic("menu"); });
	m_ListBtn.push_back(button);
	//turn on music
	button = new GameButton();
	button->Init("music");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(200, 200));
	button->setPosition(screenWidth / 2 + screenWidth / 6, screenHeight - screenHeight / 4);
	button->setOnClick([]() {DATA->setAllowSound(true); });
	m_ListBtn.push_back(button);

	//turn off music
	button = new GameButton();
	button->Init("music_off");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(200, 200));
	button->setPosition(screenWidth / 2 - screenWidth / 6 - button->getSize().x , screenHeight - screenHeight / 4);
	button->setOnClick([]() {DATA->setAllowSound(false); });
	m_ListBtn.push_back(button);

	//Background
	sf::Texture* texture = DATA->getTexture("Back2");
	m_Background.setTexture(*texture);
	m_Background.setPosition(10, 0);
	m_Background.setScale(1.4, 1.4);

	//Tile Game
	m_Title.setString("SETTING");
	m_Title.setFont(*DATA->getFont("FORTZ"));
	m_Title.setScale(2, 2);
	m_Title.setFillColor(sf::Color::Yellow);
	m_Title.setOutlineThickness(3.f);
	m_Title.setFillColor(sf::Color::Blue);
	m_Title.setPosition(screenWidth / 2 - m_Title.getGlobalBounds().width / 2, screenHeight / 5);
}

void GSSetting::Update(float deltaTime)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSSetting::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	window->draw(m_Title);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
}