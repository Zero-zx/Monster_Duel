#pragma once
#include "../IPMonster.h"

class PSUpS : public IPMState {
public:
	PSUpS(IPMonster* monster);
	void Init(string name);
	void Update(float deltaTime, HitBox* HitBox);
	void Render(sf::RenderWindow* window);
	void Reset();
private:
	IPMonster* m_Monster;
	Animation* m_Animation;
	sf::Sprite* m_Sprite;
	bool isSet;
};