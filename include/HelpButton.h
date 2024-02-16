#pragma once

#include "Button.h"

class HelpButton : public Button {
public:
	using Button::Button;

	virtual void action() override;

private:
};