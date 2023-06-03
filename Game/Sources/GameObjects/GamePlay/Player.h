#pragma once
#include "../HitBox.h"

class Player {
public:
	Player();
	~Player();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

	HitBox* getHitBox();
private:
	HitBox* m_HitBox;
	sf::Text m_Turn;

};