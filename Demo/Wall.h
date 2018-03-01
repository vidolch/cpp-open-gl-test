#pragma once

#include "Dot.h"
class Wall
{
public:
	Wall();
	virtual ~Wall();
	void drawWall(float width, float height, float thick, Dot coordinates, float angle);
};

