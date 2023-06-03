#include "GSMenu.h"

GSMenu::GSMenu()
{
}

GSMenu::~GSMenu()
{
}

void GSMenu::Exit()
{
}

void GSMenu::Pause()
{
}

void GSMenu::Resume()
{
}

void GSMenu::Init()
{

	GameButton* button;
	button = new GameButton();
	button->Init("play");
	button->setOnClick([]() {
		DATA->removeMusic("click");
		DATA->playMusic("click");
		DATA->getMusic("Menu")->stop();
		DATA->playMusic("Play");
		DATA->getMusic("Play")->setLoop(true);;
		DATA->getMusic("Play")->setVolume(20);
		GSM->ChangeState(StateTypes::PLAY); 
		
		});
	button->setPosition(screenWidth / 2 - screenWidth / 12, screenHeight - screenHeight / 8);
	button->setOrigin(button->getSize() / 2.f);
	m_ListBtn.push_back(button);

	button = new GameButton();
	button->Init("close");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 + screenWidth / 4, screenHeight - screenHeight / 8);
	button->setOnClick([]() {
		DATA->removeMusic("click");
		DATA->playMusic("click");
		WConnect->getWindow()->close(); 
		});
	m_ListBtn.push_back(button);

	button = new GameButton();
	button->Init("settings");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 - screenWidth / 4, screenHeight - screenHeight / 8);
	button->setOnClick([]() {
		DATA->removeMusic("click");
		DATA->playMusic("click");
		GSM->ChangeState(StateTypes::SETTING); DATA->getMusic("Menu")->stop();
		
		});
	m_ListBtn.push_back(button);

	button = new GameButton();
	button->Init("about");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 + screenWidth / 12, screenHeight - screenHeight / 8);
	button->setOnClick([]() {
		DATA->removeMusic("click");
		DATA->playMusic("click");
		GSM->ChangeState(StateTypes::ABOUT); 
		DATA->getMusic("Menu")->stop(); 
		});
	m_ListBtn.push_back(button);

	sf::Texture* texture = DATA->getTexture("MenuBack");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setScale(0.5f, 0.5f);
	m_Background.setPosition(screenWidth / 2, screenHeight/ 2);

	texture = DATA->getTexture("Title");
	m_Title.setTexture(*texture);
	m_Title.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Title.setScale(0.5f, 0.5f);
	m_Title.setPosition(screenWidth / 2, screenHeight / 2);

	DATA->playMusic("Menu");
	DATA->getMusic("Menu")->setLoop(true);;
	DATA->getMusic("Menu")->setVolume(20);
}

void GSMenu::Update(float deltaTime)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSMenu::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	window->draw(m_Title);

	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
}