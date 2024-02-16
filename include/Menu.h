#pragma once

#include "Button.h"
#include "Settings.h"
#include <vector>
#include <memory>
#include "TextureManager.h"

class Menu {
public:
	Menu(const TextureManager & textures);
	virtual ~Menu();

	Button * getButton(Button_t btn) const;

private:
	std::vector<Button *> m_buttons;
};