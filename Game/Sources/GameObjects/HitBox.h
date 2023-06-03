#pragma once
#include "../GameManager/ResourceManager.h"

enum TAG {
	PLAYER,
	ENEMY,
	DRAW,
	ZONE,
	B_ZONE,
	E_ZONE,
	M_MON,
	E_MON,
	M_POINT,
	E_POINT,
	NEXT,
	M_TURN,
	E_TURN,
	MNULL,
};

enum TYPE {
	NORMAL,
	LIGHT,
	FIRE,
	WATER,
	GRASS,
	ROCK,
	TNULL,
};

class HitBox : public sf::RectangleShape {
public:
	HitBox(sf::Vector2i size);
	~HitBox();

	void setAlive(bool alive) { m_isAlive = alive; };
	bool isAlive() { return m_isAlive; };

	TAG getTag() { return m_Tag; };
	void setTag(TAG tag) { m_Tag = tag; };

	int isTurn() { return m_Turn; };
	void setTurn(int turn) { m_Turn = turn; };

	bool isAttack() { return m_isAttack; };
	void setAttack(bool attack) { m_isAttack = attack; };

	bool isSkip() { return m_isSkip; };
	void setSkip(bool attack) { m_isSkip = attack; };

	void setAtk(int point) { m_Atk = point; };
	void setDef(int point) { m_Def = point; };

	int getAtk() { return m_Atk; };
	int getDef() { return m_Def; };

	void setDefend(bool point) { m_isDef = point; };
	int isDefend() { return m_isDef; };

	void setType(TYPE type) { m_Type = type; };
	TYPE getType() { return m_Type; };

	void setLP(int point) { m_LP = point; };
	int getLP() { return m_LP; };

	int hadAttack() { return m_hadAttack; };
	void resetAttack(int times) { m_hadAttack = times; };

private:
	TAG m_Tag;
	TYPE m_Type;
	int m_Turn;
	int m_hadAttack;
	bool m_isAttack;
	bool m_isDef;
	bool m_isSkip;
	int m_Atk;
	int m_Def;
	bool m_isAlive;
	int m_LP;
};