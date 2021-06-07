#include "GameStartMessage.h"
#include "GameScene.h"
#include <sstream>

GameStartMessage::GameStartMessage()
{
	text_.setFont(GAME.getFont("Resources/Courneuf-Regular.ttf"));
	text_.setPosition(sf::Vector2f(50.0f, 50.0f));
	text_.setCharacterSize(35);
	text_.setFillColor(sf::Color::Blue);

	std::stringstream stream;
	stream << "Welcome to Space Protector!\n\nPress Space Bar to shoot\n\nAnd arrow keys to move\n\nPress Enter to Start";
	text_.setString(stream.str());
}

void GameStartMessage::draw()
{
	
	GAME.getRenderWindow().draw(text_);
}
void GameStartMessage::update(sf::Time& time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		
		GameScenePtr scene = std::make_shared<GameScene>();
		GAME.setScene(scene);
		return;
	}
}