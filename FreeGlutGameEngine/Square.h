#pragma once
#include <gl/freeglut.h>
#include "Square.h"

class Square
{
private:
	float x = 0, y = 0, z = 0;
	float width = 0;

	float *vertex;
	float *normalization;
	float *colors;
	unsigned char *cube_ind;

public:
	Square(float x, float y, float z, float width);
	void draw();
	


};

