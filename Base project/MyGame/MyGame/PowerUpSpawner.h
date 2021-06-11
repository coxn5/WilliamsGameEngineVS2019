#pragma once

#include "Engine/GameEngine.h"
#include "PowerUp.h"

class PowerUpSpawner : public GameObject
{
public:
	void update(sf::Time& elapsed);
private:
	int timer_ = 0;
};

typedef std::shared_ptr<PowerUpSpawner> PowerUpSpawnerPtr;