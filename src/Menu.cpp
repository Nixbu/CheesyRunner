#include "Menu.h"

Menu::Menu(const TextureManager& textures)
{
	
	m_buttons.push_back(new PlayButton(PLAY_BTN_POS,
		textures.getTexture(playBtnTexture));
	m_buttons.push_back(new HelpButton(HELP_BTN_POS,
		textures.getTexture(helpBtnTexture)));
	m_buttons.push_back(new ExitButton(EXIT_BTN_POS,
		textures.getTexture(exitBtnTexture)));
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

