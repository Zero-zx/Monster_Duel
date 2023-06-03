#include "GSWEnd.h"

GSWEnd::GSWEnd()
{
}

GSWEnd::~GSWEnd()
{
}

void GSWEnd::Exit()
{
}

void GSWEnd::Pause()
{
}

void GSWEnd::Resume()
{
}

void GSWEnd::Init()
{
	cout << "END";
	GameButton* button;
	//menu Button
	button = new GameButton();
	button->Init("menu");
	button->setOrigin(button->getSize() / 2.f);
	//button->setSize(sf::Vector2f(50, 50));
	button->setPosition(screenWidth / 2 + screenWidth / 12, screenHeight - screenHeight / 8);
	button->setOnClick([]() {
		DATA->playMusic("menu");
		GSM->PopState();
		GSM->PopState();
		});
	m_ListBtn.push_back(button);

	//replay Button
	button = new GameButton();
	button->Init("restart");
	button->setOrigin(button->getSize() / 2.f);
	//button->setSize(sf::Vector2f(50, 50));
	button->setPosition(screenWidth / 2 - screenWidth / 12, screenHeight - screenHeight / 8);
	button->setOnClick([]() {
		DATA->playMusic("Play");
		DATA->getMusic("Play")->setLoop(true);;
		DATA->getMusic("Play")->setVolume(20);
		GSM->PopState();
		GSM->ChangeState(StateTypes::PLAY);
		});
	m_ListBtn.push_back(button);

	//Background
	sf::Texture* texture = DATA->getTexture("Win");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight / 2);
	m_Background.setScale(1.5f, 1.5f);

	//Tile Game
	m_Title.setString("You WIN!");
	m_Title.setFont(*DATA->getFont("Ethnocentric-rg"));
	m_Title.setScale(3.f, 3.f);
	m_Title.setPosition(screenWidth / 2- m_Title.getGlobalBounds().width/2, screenHeight / 5);
	
}

void GSWEnd::Update(float deltaTime)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSWEnd::Render(sf::RenderWindow* window)
{

	window->draw(m_Background);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
	window->draw(m_Title);
}