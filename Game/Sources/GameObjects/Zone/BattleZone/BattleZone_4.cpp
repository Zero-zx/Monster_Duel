#include "BattleZone_4.h"

void BattleZone_4::Init()
{
	m_hitBox = new HitBox(sf::Vector2i(421 / 10, 614 / 10));
	m_hitBox->setPosition(958.5f, 626.f);
	m_hitBox->setTag(B_ZONE);

}
