#pragma once

#include "Engine/GameEngine.h"

class GameScene : public Scene {
public:
	
	// Creates our Scene.
	GameScene();

	// Get the current score.
	int getScore();

	// Increase the score.
	void increasesScore();

	//Get the number of lives
	int getLives();

	//Decrease the number of lives
	void decreaseLives();

	int getPowerUp();

	void increasePowerUp();

private:
	int score_ = 0;
	int lives_ = 5;
	int powerUp_ = 0;
};

typedef std::shared_ptr<GameScene> GameScenePtr;
