#pragma once

#include <gl/freeglut.h>

class Observer
{
public:
	static void rotate(int x, int y, int z, float degree);
	static void moveBy(float x, float y, float z);

};

