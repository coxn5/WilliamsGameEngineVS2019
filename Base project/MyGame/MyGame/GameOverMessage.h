#pragma once

#include "Engine/GameEngine.h"

class GameOverMessage : public GameObject
{
public:
	//Creates the GameOverMessage instance.
	GameOverMessage(int score);

	//Functions overridden from GameObject:
	void draw();
	void update(sf::Time& elapsed);
private:
	sf::Text text_;

};

typedef std::shared_ptr<GameOverMessage> GameOverMessagePtr;