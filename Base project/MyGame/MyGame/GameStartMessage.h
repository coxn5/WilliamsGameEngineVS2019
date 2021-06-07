#pragma once

#include "Engine/GameEngine.h"

class GameStartMessage : public GameObject
{
public:
	//Creates the GameStartessage instance.
	GameStartMessage();

	//Functions overridden from GameObject:
	void draw();
	void update(sf::Time& elapsed);
private:
	sf::Text text_;
};

typedef std::shared_ptr<GameStartMessage> GameStartMessagePtr;
