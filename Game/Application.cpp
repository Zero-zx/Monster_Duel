#include "Application.h"

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
	m_Window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), titleGame, sf::Style::Close);

}

void Application::Update(float deltaTime)
{
	
	//Do sth
	
}

void Application::Render()
{
	m_Window->clear(sf::Color::White);
	//Draw sth
	m_Window->display();
}
