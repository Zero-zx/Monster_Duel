#pragma once
#include<iostream>
#include <map>
#include <list>
#include <string>
#include "../GameObjects/GameButton.h"
#include "../GameObjects/Animation.h"
#include "../GameConfig.h"
#include "SFML/Audio.hpp"
#include <cstdlib>
#include <ctime>

using namespace std;

#define DATA ResourceManager::GetInstance()

class ResourceManager :public CSingleton<ResourceManager> {
public:
	ResourceManager();
	~ResourceManager();

	void addTexture(std::string name);
	void removeTexture(std::string name);
	sf::Texture* getTexture(std::string name);

	void addFont(std::string name);
	void removeFont(std::string name);
	sf::Font* getFont(std::string name);

	void addSound(std::string name);
	void removeSound(std::string name);
	sf::Sound* getSound(std::string name);

	void addMusic(std::string name);
	void removeMusic(std::string name);
	sf::Music* getMusic(std::string name);

	void playMusic(std::string name);
	void playSound(std::string name);
	void setAllowSound(bool allow);




private:
	map<std::string, sf::Texture*> m_MapTexture;
	map<std::string, sf::Font*> m_MapFont;
	map<std::string, sf::Sound*> m_MapSound;
	map<std::string, sf::Music*> m_MapMusic;

	string m_Path;
	string m_TexturePath;
	string m_FontPath;
	string m_SoundPath;

	bool m_allowSound;
};