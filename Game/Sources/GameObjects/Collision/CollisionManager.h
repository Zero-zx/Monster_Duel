#pragma once
#include "../HitBox.h"

class CollisionManager {
public:
	void addObj(HitBox* hitzBox);
	bool checkCollision(HitBox* a, HitBox* b);
	bool checkMouse();
	void Update();
private:
	list<HitBox*> m_listObj;
};