#include "GameStartScene.h"
#include "GameStartMessage.h"

GameStartScene::GameStartScene(int start)
{
	GameStartMessagePtr gameStartMessage = std::make_shared<GameStartMessage>(start);
	addGameObject(gameStartMessage);
}