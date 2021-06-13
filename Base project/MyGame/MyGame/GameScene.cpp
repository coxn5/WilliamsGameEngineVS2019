#include "GameScene.h"
#include "Ship.h"
#include "MeteorSpawner.h"
#include "Score.h"
#include "GameOverScene.h"
#include "GameStartScene.h"
#include "PowerUpSpawner.h"
#include "livesDisplayed.h"

GameScene::GameScene() 
{

	LivesPtr lives = std::make_shared<Lives>(sf::Vector2f(10.0f, 35.0f));
	addGameObject(lives);

	ShipPtr ship = std::make_shared<Ship>();
	addGameObject(ship);

	MeteorSpawnerPtr meteorSpawner = std::make_shared<MeteorSpawner>();
	addGameObject(meteorSpawner);

	ScorePtr score = std::make_shared<Score>(sf::Vector2f(10.0f, 10.0f));
	addGameObject(score);

	PowerUpSpawnerPtr powerUpSpawner = std::make_shared<PowerUpSpawner>();
	addGameObject(powerUpSpawner);
}

int GameScene::getScore()
{
	return score_;
}

void GameScene::increasesScore()
{
	++score_; 
}

int GameScene::getPowerUp()
{
	return powerUp_;
}

void GameScene::increasePowerUp()
{
	++powerUp_;
	if (powerUp_ == 1)
	{
		++lives_;
		--powerUp_;
	}
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