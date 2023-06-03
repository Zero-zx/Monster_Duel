#pragma once
#include<SFML/Graphics.hpp>
#include "GameConfig.h"
#include "GameManager/ResourceManager.h"
#include "GameStateManager/GameStateMachine.h"
#include "GameObjects/Animation.h"

class Application {
public:
	void Run();
	~Application();
private:
	void Init();
	void Update(float deltaTime);
	void Render();
private:
	sf::RenderWindow* m_Window;
	sf::Sprite m_Sprite;
	sf::Sprite sp;
};