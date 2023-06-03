#pragma once
#include "../IPMonster.h"

class PSSMPick : public IPMState {
public:
	PSSMPick(IPMonster* monster);
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
	list<GameButton*> m_listBtn;
	bool click1, click2;
};