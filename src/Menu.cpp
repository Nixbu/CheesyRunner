#include "Menu.h"

Menu::Menu(const TextureManager& textures)
{
	
	m_buttons.push_back(new PlayButton(PLAY_BTN_POS,
		textures.getTexture(playBtnTexture)));
	m_buttons.push_back(new HelpButton(HELP_BTN_POS,
		textures.getTexture(helpBtnTexture)));
	m_buttons.push_back(new ExitButton(EXIT_BTN_POS,
		textures.getTexture(exitBtnTexture)));

	m_backgroung_img.setTexture(*(textures.getTexture(backgroundTexture)));
	m_backgroung_img.scale(0.5f, 0.5f);
}

Menu::~Menu()
{
	for (int idx = 0; idx < m_buttons.size(); idx++)
	{
		delete m_buttons[idx];
	}
}

Button * Menu::getButton(Button_t btn) const
{
	return m_buttons[btn];
}

void Menu::draw(sf::RenderWindow* window) const
{
	window->draw(m_backgroung_img);
	for (int btn = 0; btn < m_buttons.size(); btn++)
	{
		m_buttons[btn]->draw(window);
	}

}

// Polymorphism
void Menu::handleClicks(sf::Vector2f mousePos, sf::RenderWindow * window,
	const TextureManager & textures)
{
	for (int btn = 0; btn < this->m_buttons.size(); btn++)
	{
		if (this->m_buttons[btn]->isClicked(mousePos))
		{
			this->m_buttons[btn]->action(window, textures);
		}
	}
}

void Menu::handleFloating(sf::Vector2f mousePos)
{
	for (int btn = 0; btn < this->m_buttons.size(); btn++)
	{
		if ((this->m_buttons[btn]->getSprite()->getGlobalBounds()).contains(mousePos))
		{
			this->m_buttons[btn]->scale(BUTTON_FLOATED_SIZE);
		}
		else
		{
			this->m_buttons[btn]->scale(BUTTON_DEFA_SIZE);
				 
		}
	}
}

