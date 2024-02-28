#include "HelpButton.h"
//======================================================
// function displayes the help screan ,
// returns to the menu if backspace is presses
void HelpButton::action(sf::RenderWindow* window, 
	const TextureManager& textures,
	const SoundManager& sounds)
{
	sf::Sprite instructionsImg;

	instructionsImg.setTexture(*textures.getTexture(instructionsTexture));
	instructionsImg.setScale(0.5f, 0.5f);

	while (window->isOpen())
	{

		window->clear();
		window->draw(instructionsImg);
		window->display();

		this->handleEvents(window);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
		{
			break;
		}
	}
}
//======================================================
void HelpButton::handleEvents(sf::RenderWindow* window)
{
	for (auto event = sf::Event{}; window->pollEvent(event); )
	{
		switch (event.type)
		{
		case sf::Event::Closed:

			window->close();
			break;
		}
	}
}

