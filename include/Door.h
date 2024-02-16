#pragma once

#include "StaticObject.h"

class Door : public StaticObject {
public:
	using StaticObject::StaticObject;
	virtual ~Door() = default;

private:
};