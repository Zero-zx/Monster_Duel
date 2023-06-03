#pragma once
#include <string>
#include "GameStateBase.h"
#include "../GameObjects/Background/Background.h"
#include "../GameObjects/GamePlay/GamePlay.h"

#include "../GameObjects/Zone/BattleZone/BattleZone.h"
#include "../GameObjects/Zone/EnemyZone/EnemyZone.h"
#include "../GameObjects/Zone/DeckZone.h"
#include "../GameObjects/Collision/CollisionManager.h"
#include "../GameObjects/Deck/Deck.h"


class GSPlay : public GameStateBase {
public:
	GSPlay();
	virtual ~GSPlay();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	Background m_Background;
	End m_End;
	Start m_Start;
	Player m_Player;
	//Enemy m_Enemy;
	CollisionManager m_CollisionManager;
	list<Zone*> m_listZone;
	list<GameButton*> m_listBtn;
	list<Card*> m_listCard;

	float m_currentTime;

	int m_CurrentScore;
	int e_CurrentScore;
	sf::Text m_Score;
	sf::Text e_Score;

	HitBox* m_HitBox;
	HitBox* e_HitBox;
};