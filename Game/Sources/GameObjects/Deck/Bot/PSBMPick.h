#pragma once
#include "../IPMonster.h"

class PSBMPick : public IPMState {
public:
	PSBMPick(IPMonster* monster);
	void Init(string name);
	void Update(float deltaTime, HitBox* hitBox);
	void Render(sf::RenderWindow* window);
	void Reset();
private:
	IPMonster* m_Monster;
	Animation* m_Animation;
	Animation* m_Button1;
	Animation* m_Button2;
	sf::Sprite* m_Sprite;
	bool click1, click2;

	sf::Text m_Atk;
	sf::Text m_Def;

};