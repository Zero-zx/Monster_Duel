#include "GSPlay.h"

GSPlay::GSPlay()
{
	m_currentTime = 0.f;

}

GSPlay::~GSPlay()
{
}

void GSPlay::Exit()
{
}

void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}

//747.5f, 577.5f
void GSPlay::Init()
{
	printf("Play game");
	m_Background.Init();
	m_End.Init();
	m_CollisionManager.addObj(m_End.getHitBox());
	
	m_Start.Init();
	m_CollisionManager.addObj(m_Start.getHitBox());


	m_Player.Init();
	m_CollisionManager.addObj(m_Player.getHitBox());

	Zone* zone = new BattleZone_1();
	m_listZone.push_back(zone);
	zone = new BattleZone_2();
	m_listZone.push_back(zone);
	zone = new BattleZone_3();
	m_listZone.push_back(zone);
	zone = new BattleZone_4();
	m_listZone.push_back(zone);
	zone = new BattleZone_5();
	m_listZone.push_back(zone);
	//zone = new DeckZone();
	//m_listZone.push_back(zone);
	zone = new EnemyZone_1();
	m_listZone.push_back(zone);
	zone = new EnemyZone_2();
	m_listZone.push_back(zone);
	zone = new EnemyZone_3();
	m_listZone.push_back(zone);
	zone = new EnemyZone_4();
	m_listZone.push_back(zone);
	zone = new EnemyZone_5();
	m_listZone.push_back(zone);
	for (auto it : m_listZone) {
		if (it->getHitBox() == nullptr) it->Init();
		m_CollisionManager.addObj(it->getHitBox());
	}

	Card* card = new Pikachu();
	m_listCard.push_back(card);
	card = new Rattata();
	m_listCard.push_back(card);
	card = new Charmander();
	m_listCard.push_back(card);
	card = new Bulbasaur();
	m_listCard.push_back(card);
	card = new Froakie();
	m_listCard.push_back(card);
	card = new Geodude();
	m_listCard.push_back(card);
	card = new Turwig();
	m_listCard.push_back(card);
	card = new Magikarp();
	m_listCard.push_back(card);
	card = new Mareep();
	m_listCard.push_back(card);
	card = new Snorlax();
	m_listCard.push_back(card);
	
	for (auto it : m_listCard) {
		if (it->getHitBox() == nullptr) it->Init();
		m_CollisionManager.addObj(it->getHitBox());
	}
	
	m_Score.setFont(*DATA->getFont("FORTZ"));
	m_Score.setString("2000");
	m_Score.setScale(3,3);
	m_HitBox = new HitBox(sf::Vector2i(120, 70));
	//m_HitBox->setPosition(80, 800);
	m_HitBox->setTag(M_POINT);
	m_Score.setPosition(80,800);
	m_Score.setFillColor(sf::Color::Blue);
	m_HitBox->setLP(2000);

	e_Score.setFont(*DATA->getFont("FORTZ"));
	e_Score.setString("2000");
	e_Score.setScale(3, 3);
	e_HitBox = new HitBox(sf::Vector2i(100, 50));
	//e_HitBox->setPosition(1620, 170);
	e_Score.setPosition(1620 - e_Score.getGlobalBounds().width, 170 - e_Score.getGlobalBounds().height);
	e_Score.setFillColor(sf::Color::Blue);
	e_HitBox->setLP(2000);
	e_HitBox->setTag(E_POINT);
	

	m_CurrentScore = 2000;
	e_CurrentScore = 2000;

	m_Score.setOutlineThickness(3.f);
	e_Score.setOutlineThickness(3.f);

	m_Score.setOutlineColor(sf::Color::White);
	e_Score.setOutlineColor(sf::Color::White);


	m_CollisionManager.addObj(m_HitBox);
	m_CollisionManager.addObj(e_HitBox);

}

void GSPlay::Update(float deltaTime)
{
	m_End.Update(deltaTime);
	m_Start.Update(deltaTime);
	m_Player.Update(deltaTime);
	m_Background.Update(deltaTime);

	for (auto it : m_listZone) {
		it->Update(deltaTime);
	}
	for (auto it : m_listCard) {
		it->Update(deltaTime, m_Player.getHitBox());
	}

	m_CollisionManager.Update();
	int tmp = e_CurrentScore - e_HitBox->getLP();
	int sav = m_CurrentScore - m_HitBox->getLP();
	m_CurrentScore -= sav;
	e_CurrentScore -= tmp;

	if (m_CurrentScore <= 0) {
		DATA->getMusic("play")->stop();
		DATA->removeMusic("Lose");
		DATA->playMusic("Lose");
		GSM->ChangeState(StateTypes::L_END);
	}
	if (e_CurrentScore <= 0) {
		DATA->getMusic("play")->stop();
		DATA->removeMusic("Win");
		DATA->playMusic("Win");
		GSM->ChangeState(StateTypes::W_END);
	}

	m_Score.setString(to_string(m_CurrentScore));
	e_Score.setString(to_string(e_CurrentScore));


}

void GSPlay::Render(sf::RenderWindow* window)
{
	m_Background.Render(window);
	m_Player.Render(window);

	m_End.Render(window);
	m_Start.Render(window);

	for (auto it : m_listZone) {
		it->Render(window);
	}
	for (auto it : m_listCard) {
		if(it->getHitBox()->isAlive()) it->Render(window);
	}
	window->draw(m_Score);
	window->draw(e_Score);

}
