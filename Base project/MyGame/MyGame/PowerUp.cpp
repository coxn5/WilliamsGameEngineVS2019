#include "PowerUp.h"
#include "GameScene.h"
#include <memory>
const float SPEED = 0.25f;

PowerUp::PowerUp(sf::Vector2f pos)
{
	sprite_.setTexture(GAME.getTexture("Resources/explosion01.png"));
	sprite_.setPosition(pos);
	assignTag("powerup");
	setCollisionCheckEnabled(true);
}

void PowerUp::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void PowerUp::update(sf::Time& elapsed)
{
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();

	if (pos.x < sprite_.getGlobalBounds().width * -1)
	{
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		
		makeDead();
	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
	}

}

sf::FloatRect PowerUp::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}

void PowerUp::handleCollision(GameObject& otherGameObject)
{
	if (otherGameObject.hasTag("laser"))
	{
		sf::Vector2f pos = sprite_.getPosition();

		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.increasePowerUp();

		otherGameObject.makeDead();
	}

	makeDead();
}
