#include "EnemyZone_5.h"

void EnemyZone_5::Init()
{
	m_hitBox = new HitBox(sf::Vector2i(421 / 10, 614 / 10));
	m_hitBox->setPosition(1070.f, 344.f);
	m_hitBox->setTag(E_ZONE);

}
