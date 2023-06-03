#pragma once
#include "../../GameManager/ResourceManager.h"
#include "../../GameManager/WindowConnector.h"
#include "../Collision/CollisionManager.h"

class IPMState {
public:
	enum STATE {
		UP,
		DOWN,
		ATTACK,
		PICK,
		MOVE,
		DEATH,
		SNULL,
	};
	virtual void Init(string name) = 0;
	virtual void Update(float deltaTime, HitBox* HitBox) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
	virtual void Reset() = 0;

};