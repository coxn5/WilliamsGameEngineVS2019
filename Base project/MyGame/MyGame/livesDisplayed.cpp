#include "livesDisplayed.h"
#include "GameScene.h"
#include <sstream>

Lives::Lives(sf::Vector2f pos)
{
	text_.setFont(GAME.getFont("Resources/Courneuf-Regular.ttf"));
	text_.setPosition(pos);
	text_.setCharacterSize(24);
	text_.setFillColor(sf::Color::Red);
	assignTag("lives");
}

