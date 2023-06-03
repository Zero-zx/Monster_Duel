#include "DeckZone.h"

void DeckZone::Init()
{
	m_hitBox = new HitBox(sf::Vector2i(421 / 6, 614 / 6));
	m_hitBox->setPosition(1189.f, 823.f);
}
