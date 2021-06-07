#pragma once

#include "Engine/GameEngine.h"

class GameStartScene : public Scene
{
public:
	//Creates Start Scene.
	GameStartScene();
};

typedef std::shared_ptr<GameStartScene> GameStartScenePtr;

