#include "PowerUpSpawner.h"

//The number of milliseconds between powerups spawns.
const int SPAWN_DELAY = 10000;

void PowerUpSpawner::update(sf::Time& elapsed)
{
	//Determine how much time has passed and adjust our timer.
	int msElapsed = elapsed.asMilliseconds();
	timer_ -= msElapsed;
	//If our timer has elapsed, reset it and spawn a powerup.
	if (timer_ <= 0)
	{
		timer_ = SPAWN_DELAY;

		sf::Vector2u size = GAME.getRenderWindow().getSize();

		//Spawn the powerup off the right side of the screen.
		//We're assuming the powerup isn't more than 100 pixels wide.
		float powerupX = (float)(size.x + 100);

		//Spawn the powerup somewhere along the height of the window randomly.
		float powerupY = (float)(rand() % size.y);

		//Create a powerup and add it to the scene.
		PowerUpPtr powerUp = std::make_shared<PowerUp>(sf::Vector2f(powerupX, powerupY));
		GAME.getCurrentScene().addGameObject(powerUp);

	}
}