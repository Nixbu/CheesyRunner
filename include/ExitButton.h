#pragma once

#include "Button.h"

class ExitButton : public Button {
public:
	using Button::Button;

	virtual void action() override;

private:
};