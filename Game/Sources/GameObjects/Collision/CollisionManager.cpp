#include "CollisionManager.h"
#include<iostream>
void CollisionManager::addObj(HitBox* hitBox)
{
	m_listObj.push_back(hitBox);
}

bool CollisionManager::checkCollision(HitBox* a, HitBox* b)
{
	return a->getGlobalBounds().intersects(b->getGlobalBounds());
}

bool CollisionManager::checkMouse()
{
	for (auto a : m_listObj) {
		if (a->getTag() == E_ZONE) {
			return a->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow()));
		}
	}
}

void CollisionManager::Update()
{
	bool checkPlayer = false;
	bool checkEnemy = false;

 	for (auto a : m_listObj) {
		if ((a->getTag() == B_ZONE || a->getTag() == PLAYER || a->getTag() == M_MON) && a->getType() != TNULL && a->isAlive()) checkPlayer = true;
		if ((a->getTag() == E_ZONE || a->getTag() == ENEMY || a->getTag() == E_MON) && a->getType() != TNULL && a->isAlive()) checkEnemy = true;
		for (auto b : m_listObj) {
			if (a->getTag() == b->getTag()) continue;
			if (a->getTag() == PLAYER && b->getTag() == B_ZONE && b->getType() == TNULL && checkCollision(a, b) && !b->isSkip()) {
				a->setPosition(b->getPosition().x, b->getPosition().y);
				if (a->getPosition() == b->getPosition()) a->setTag(B_ZONE);
				b->setSkip(true);

			}

			if (a->getTag() == ENEMY && b->getTag() == E_ZONE && b->getType() == TNULL && checkCollision(a, b) && !b->isSkip()) {
				a->setPosition(b->getPosition().x, b->getPosition().y);
				if (a->getPosition() == b->getPosition()) a->setTag(E_ZONE);
				b->setSkip(true);

			}

			if (a->getTag() == B_ZONE && a->isAttack() && b->getTag() == E_ZONE && b->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow())) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				

				bool check = false;
				a->setAttack(false);

				for (auto c : m_listObj) {
					if (c->getTag() == E_ZONE && c->getType() != TNULL && c->isAlive()) {
						check = true;
						break;
					}
				}
				if (!check && a->hadAttack()) {

					for (auto c : m_listObj) {
						if (c->getTag() == E_POINT) {
							int point = c->getLP() - a->getAtk();
							c->setLP(point);
							break;
						}
					}
					a->resetAttack(0);
					DATA->removeMusic("Boom");
					DATA->playMusic("Boom");
				}
			}

			if (a->getTag() == E_ZONE && a->isAttack() && b->getTag() == B_ZONE && b->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow())) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				
				bool check = false;
				a->setAttack(false);

				for (auto c : m_listObj) {
					if (c->getTag() == B_ZONE && c->getType() != TNULL && c->isAlive()) {
						check = true;
						break;
					}
				}
				if (!check && a->hadAttack()) {

					for (auto c : m_listObj) {
						if (c->getTag() == M_POINT) {
							int point = c->getLP() - a->getAtk();
							c->setLP(point);
							break;
						}
					}
					a->resetAttack(0);
					DATA->removeMusic("Boom");
					DATA->playMusic("Boom");

				}
			}

			if (a->getTag() == B_ZONE && a->isAlive() && a->isAttack() && b->getTag() == E_ZONE && b->getType() != TNULL && b->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow()))) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) {
		

					if (b->isAlive() && a->hadAttack()) {
						DATA->removeMusic("Boom");
						DATA->playMusic("Boom");
						a->resetAttack(0);
						int atk = a->getAtk();
						int sav = atk;

						if (a->getType() == LIGHT) {
							if (b->getType() == WATER) {
								atk = atk + atk * 0.5;
								a->setAtk(atk);
							}
							else if (b->getType() == ROCK) {
								atk = atk - atk * 0.5;
								a->setAttack(atk);
							}
						}
						else if (a->getType() == FIRE) {
							if (b->getType() == GRASS) {
								atk = atk + atk * 0.5;
								a->setAtk(atk);
							}
						}
						else if (a->getType() == WATER) {
							if (b->getType() == ROCK || b->getType() == FIRE) {
								atk = atk + atk * 0.5;
								a->setAtk(atk);
							}
							else if (b->getType() == LIGHT) {
								atk = atk - atk * 0.5;
								a->setAtk(atk);
							}
						}
						else if (a->getType() == GRASS) {
							if (b->getType() == WATER || b->getType() == ROCK) {
								atk = atk + atk * 0.5;
								a->setAtk(atk);
							}
							else if (b->getType() == FIRE) {
								atk = atk - atk * 0.5;
								a->setAtk(atk);
							}
						}
						else if (a->getType() == ROCK) {
							if (b->getType() == LIGHT || b->getType() == FIRE) {
								atk = atk + atk * 0.5;
								a->setAtk(atk);
							}
							else if (b->getType() == WATER || b->getType() == GRASS) {
								atk = atk - atk * 0.5;
								a->setAtk(atk);
							}
						}

						if (a->getAtk() > b->getDef()) {
							int loss = a->getAtk() - b->getDef();

							for (auto c : m_listObj) {
								if (c->getTag() == E_POINT) {
									int point = c->getLP() - loss;
									c->setLP(point);
								}
								else if (c->getTag() == E_ZONE && c->getType() == TNULL && b->getPosition() == c->getPosition()) c->setSkip(false);

							}
							a->setAttack(false);
							b->setAlive(false);
						}
						else if (a->getAtk() == b->getDef()) {
							b->setAlive(false);
							a->setAlive(false);
						}
						else if(a->getAtk() < b->getDef()) {

							int loss = b->getDef() - a->getAtk();

							for (auto c : m_listObj) {
								if (c->getTag() == M_POINT) {
									int point = c->getLP() - loss;
									c->setLP(point);
								}
								else if (c->getTag() == B_ZONE && c->getType() == TNULL && a->getPosition() == c->getPosition()) c->setSkip(false);

							}

							a->setAttack(false);
							a->setAlive(false);
						}

						a->setAtk(sav);

					}
				}
			}


			if (a->getTag() == E_ZONE && a->isAttack() && b->getTag() == B_ZONE && b->getType() != TNULL && b->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow()))) {
				
				if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) {
			
					
					if (b->isAlive() && a->isAlive() && a->hadAttack()) {
						DATA->removeMusic("Boom");

						DATA->playMusic("Boom");

						a->resetAttack(0);
						int atk = a->getAtk();
						int sav = atk;
						if (a->getType() == LIGHT) {
							if (b->getType() == WATER) {
								atk = atk + atk * 0.5;
								a->setAtk(atk);
							}
							else if (b->getType() == ROCK) {
								atk = atk - atk * 0.5;
								a->setAttack(atk);
							}
						}
						else if (a->getType() == FIRE) {
							if (b->getType() == GRASS) {
								atk = atk + atk * 0.5;
								a->setAtk(atk);
							}
						}
						else if (a->getType() == WATER) {
							if (b->getType() == ROCK || b->getType() == FIRE) {
								atk = atk + atk * 0.5;
								a->setAtk(atk);
							}
							else if (b->getType() == LIGHT) {
								atk = atk - atk * 0.5;
								a->setAtk(atk);
							}
						}
						else if (a->getType() == GRASS) {
							if (b->getType() == WATER || b->getType() == ROCK) {
								atk = atk + atk * 0.5;
								a->setAtk(atk);
							}
							else if (b->getType() == FIRE) {
								atk = atk - atk * 0.5;
								a->setAtk(atk);
							}
						}
						else if (a->getType() == ROCK) {
							if (b->getType() == LIGHT || b->getType() == FIRE) {
								atk = atk + atk * 0.5;
								a->setAtk(atk);
							}
							else if (b->getType() == WATER || b->getType() == GRASS) {
								atk = atk - atk * 0.5;
								a->setAtk(atk);
							}
						}


						if (a->getAtk() > b->getDef()) {
							int loss = a->getAtk() - b->getDef();

							for (auto c : m_listObj) {
								if (c->getTag() == M_POINT) {
									int point = c->getLP() - loss;
									c->setLP(point);
								}
								else if (c->getTag() == B_ZONE && c->getType() == TNULL && b->getPosition() == c->getPosition()) c->setSkip(false);
							}
							a->setAttack(false);
							b->setAlive(false);
						}
						else if (a->getAtk() == b->getDef()) {

							b->setAlive(false);
							a->setAlive(false);
						}
						else {
							
							int loss = b->getDef() - a->getAtk();
							for (auto c : m_listObj) {
								if (c->getTag() == E_POINT) {
									int point = c->getLP() - loss;
									c->setLP(point);
								}
								else if (c->getTag() == E_ZONE && c->getType() == TNULL && a->getPosition() == c->getPosition()) c->setSkip(false);

							}
							a->setAlive(false);
						}
						a->setAttack(false);
						a->setAtk(sav);
					}
				}
			}

			if (a->getTag() == NEXT && b->getTag() == M_TURN) {
				if (b->isTurn() == 1) {

					if (a->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow())) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						DATA->removeMusic("click");
						DATA->playMusic("click");
						b->setTurn(2);
					}
				}

			}

			if (a->getTag() == NEXT && b->getTag() == M_TURN) {
				if (b->isTurn() == 3) {

					if (a->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow())) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						DATA->removeMusic("click");
						DATA->playMusic("click");
						b->setTurn(4);
					}
				}

			}


			if (a->getTag() == DRAW && b->getTag() == M_TURN) {

				if (b->isTurn() == 2) {

					if (a->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow())) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						DATA->removeMusic("click");
						DATA->playMusic("click");
						b->setTurn(3);
						b->setSkip(false);

						for (auto c : m_listObj) {
							if (c->getTag() == E_ZONE && c->getType() != TNULL) {
								c->resetAttack(1);
							}
						}
					}
				}

			}

			if (a->getTag() == DRAW && b->getTag() == M_TURN) {
				if (b->isTurn() == 4) {
					if (a->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow())) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						DATA->removeMusic("click");
						DATA->playMusic("click");
						b->setTurn(1);
						b->setSkip(false);

						for (auto c : m_listObj) {
							if (c->getTag() == B_ZONE && c->getType() != TNULL) {
								c->resetAttack(1);
							}
						}

					}
				}

			}
		

		}
	}

	if (!checkPlayer) for (auto a : m_listObj) if (a->getTag() == M_POINT) a->setLP(0);
	if (!checkEnemy) for (auto a : m_listObj) if (a->getTag() == E_POINT) a->setLP(0);

}
