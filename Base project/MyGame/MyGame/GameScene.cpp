#include "GameScene.h"
#include "Ship.h"
#include "MeteorSpawner.h"
#include "Score.h"
#include "GameOverScene.h"
#include "GameStartScene.h"

int GameScene::getStart()
{
	return start_;
}

void GameScene::decreaseStart()
{
	--start_;

	if (start_ == 0)
	{
		GameStartScenePtr gameStartScene = std::make_shared<GameStartScene>(start_);
		GAME.setScene(gameStartScene);
	}
}

GameScene::GameScene() 
{
	ShipPtr ship = std::make_shared<Ship>();
	addGameObject(ship);

	MeteorSpawnerPtr meteorSpawner = std::make_shared<MeteorSpawner>();
	addGameObject(meteorSpawner);

	ScorePtr score = std::make_shared<Score>(sf::Vector2f(10.0f, 10.0f));
	addGameObject(score);
}

int GameScene::getScore()
{
	return score_;
}

void GameScene::increasesScore()
{
	++score_; 
}



int GameScene::getLives()
{
	return lives_;
}

void GameScene::decreaseLives()
{
	--lives_;

	if (lives_ == 0)
	{
		GameOverScenePtr gameOverScene = std::make_shared<GameOverScene>(score_);
		GAME.setScene(gameOverScene);
	}
}