#include "GameStartScene.h"
#include "GameStartMessage.h"

GameStartScene::GameStartScene()
{
	GameStartMessagePtr gameStartMessage = std::make_shared<GameStartMessage>();
	addGameObject(gameStartMessage);
}