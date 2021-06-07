#pragma once

#include "Engine/GameEngine.h"

class GameScene : public Scene {
public:

	int getStart();
	void decreaseStart();
	
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

private:
	int score_ = 0;
	int lives_ = 5;
};

typedef std::shared_ptr<GameScene> GameScenePtr;
