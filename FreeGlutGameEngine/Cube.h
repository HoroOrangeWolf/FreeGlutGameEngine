#pragma once
#include "Cube.h"
#include "Transformable.h"
#include "BitMapHandler.h"
#include <gl/freeglut.h>
#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

#define PI 3.14159265

#define angle PI/180.f

class Cube
	:public Transformable, public BitMapHandler
{
private:
	float x = 0, y = 0, z = 0;
	float width = 0;

	float *vertex = NULL;
	float *normalization = NULL;
	float *colors = NULL;
	unsigned char *cube_ind = NULL;

public:
	Cube(float x, float y, float z, float width, std::string name);
	~Cube();
	void draw();
	void moveBy(float x, float y, float z) override;
	void rotate(int x, int y, int z, float degree) override;
};

