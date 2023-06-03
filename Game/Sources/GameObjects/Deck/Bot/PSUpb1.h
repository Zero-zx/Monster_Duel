#pragma once
#include "../IPMonster.h"

class PSUpb1 : public IPMState {
public:
	PSUpb1(IPMonster* monster);
	void Init(string name);
	void Update(float deltaTime, HitBox* hitBox);
	void Render(sf::RenderWindow* window);
	void Reset();
private:
	string m_Name;
	IPMonster* m_Monster;
	Animation* m_Animation;
	sf::Sprite* m_Sprite;
	bool isSet;
};