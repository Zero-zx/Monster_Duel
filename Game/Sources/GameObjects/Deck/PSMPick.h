#pragma once
#include "IPMonster.h"

class PSMPick : public IPMState {
public:
	PSMPick(IPMonster* monster);
	void Init(string name);
	void Update(float deltaTime, HitBox* hitBox);
	void Render(sf::RenderWindow* window);
	void Reset();
private:
	IPMonster* m_Monster;
	Animation* m_Animation;
	Animation* m_Button1;
	Animation* m_Button2;
	Animation* m_Button3;
	sf::Text m_Atk;
	sf::Text m_Def;


	bool click1, click2, click3;
};