#pragma once
#include "IPMonster.h"

class PSMAttack : public IPMState {
public:
	PSMAttack(IPMonster* monster);
	void Init(string name);
	void Update(float deltaTime, HitBox* hitBox);
	void Render(sf::RenderWindow* window);
	void Reset();
private:
	IPMonster* m_Monster;
	Animation* m_Animation;
	sf::Sprite* m_Sprite;
	sf::Text m_Index;
\
	bool isSet;
};