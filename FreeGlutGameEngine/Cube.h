#pragma once
#include <gl/freeglut.h>
#include "Cube.h"

class Cube
{
private:
	float x = 0, y = 0, z = 0;
	float width = 0;

	float *vertex = NULL;
	float *normalization = NULL;
	float *colors = NULL;
	unsigned char *cube_ind = NULL;

public:
	Cube(float x, float y, float z, float width);
	~Cube();
	void draw();
};

