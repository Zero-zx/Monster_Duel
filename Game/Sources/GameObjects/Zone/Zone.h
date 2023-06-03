#pragma once
#include "../../GameManager/ResourceManager.h"
#include "../HitBox.h"

class Zone {
public:
	Zone();
	~Zone();
	virtual void Init();
	virtual void Update(float delataTime);
	virtual void Render(sf::RenderWindow* window);

	HitBox* getHitBox() { return m_hitBox; };
protected:
	HitBox* m_hitBox;
	
};