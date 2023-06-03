#include "BattleZone_5.h"

void BattleZone_5::Init()
{
	m_hitBox = new HitBox(sf::Vector2i(421 / 10, 614 / 10));
	m_hitBox->setPosition(1070.f, 626.f);
	m_hitBox->setTag(B_ZONE);

}
