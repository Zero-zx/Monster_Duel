#pragma once
#include "../HitBox.h"

class Start {
public:
	Start();
	~Start();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

	HitBox* getHitBox();
private:
	HitBox* m_HitBox;
	Animation* m_Animation;
	sf::Text m_Turn;

};