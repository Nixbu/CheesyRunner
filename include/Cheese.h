#pragma once

#include "StaticObject.h"

class Cheese : public StaticObject {
public:
	using StaticObject::StaticObject;
	virtual ~Cheese() = default;
private:
};