#pragma once
#include "../../GameManager/ResourceManager.h"
#include "../HitBox.h"

class Background {
public:
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	sf::Sprite m_image;
	sf::Vector2i m_SizeImage;
	sf::Sprite m_back;
	HitBox* m_hitBox;
};