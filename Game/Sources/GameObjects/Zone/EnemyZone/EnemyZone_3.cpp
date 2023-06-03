#include "EnemyZone_3.h"

void EnemyZone_3::Init()
{
	m_hitBox = new HitBox(sf::Vector2i(421 / 10, 614 / 10));
	m_hitBox->setPosition(845.f, 344.f);
	m_hitBox->setTag(E_ZONE);

}
