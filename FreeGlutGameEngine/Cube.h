#pragma once
#include <gl/freeglut.h>
#include "Cube.h"
#include "Transformable.h"
#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define PI 3.14159265

#define angle PI/180.f

class Cube
	:public Transformable
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
	void moveBy(float x, float y, float z) override;
	void rotate(int x, int y, int z, float degree) override;
};

