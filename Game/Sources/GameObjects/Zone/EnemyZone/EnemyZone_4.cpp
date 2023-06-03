#include "EnemyZone_4.h"

void EnemyZone_4::Init()
{
	m_hitBox = new HitBox(sf::Vector2i(421 / 10, 614 / 10));
	m_hitBox->setPosition(958.5f, 344.f);
	m_hitBox->setTag(E_ZONE);

}
