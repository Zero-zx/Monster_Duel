#include "BattleZone.h"

void BattleZone::Init(float x, float y)
{
	m_hitBox = new HitBox(sf::Vector2i(421 / 6, 614 / 6));
	m_hitBox->setPosition(x, y);
	m_hitBox->setTag(ZONE);
}
