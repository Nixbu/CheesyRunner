#pragma once

#include "Button.h"
#include "Settings.h"
#include <vector>
#include <memory>

class Menu {
public:
	Menu(const TextureManager & textures);
	~Menu() = default;

	std::unique_ptr<Button> getButton() const;

private:
	std::vector<std::unique_ptr<Button>> m_buttons;
};