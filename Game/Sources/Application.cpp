#include "Application.h"
#include "GameStateManager/GameStateBase.h"

void Application::Run()
{
	Init();
	
	sf::Clock clock;
	float deltaTime = 0.f;
	while (m_Window->isOpen()) {
		deltaTime = clock.restart().asSeconds();
		sf::Event event;
		while (m_Window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				m_Window->close();
			}
		}
		Update(deltaTime);
		Render();
	}
}

Application::~Application()
{
	if (m_Window != nullptr) delete m_Window;
	
}

void Application::Init()
{
	m_Window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), "Monster DUEL", sf::Style::Default);
	GameStateMachine::GetInstance()->ChangeState(StateTypes::INTRO);
	m_Window->setFramerateLimit(60);
	m_Window->setVerticalSyncEnabled(false);
	WConnect->setWindow(m_Window);
}

void Application::Update(float deltaTime)
{
	//Do sth
	if (GameStateMachine::GetInstance()->NeedToChangeState()) {
		GameStateMachine::GetInstance()->PerformStateChange();
	}
	GameStateMachine::GetInstance()->currentState()->Update(deltaTime);
	
}

void Application::Render()
{
	m_Window->clear(sf::Color::Black);
	//Draw sth
	GameStateMachine::GetInstance()->currentState()->Render(m_Window);
	//m_Window->draw(m_Sprite);
	m_Window->display();
}
