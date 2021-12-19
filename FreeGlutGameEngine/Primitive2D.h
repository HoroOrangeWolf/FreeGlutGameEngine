#pragma once
#define NULL 0


class Primitive2D
{
protected:
	float* vertex = NULL;
	float* normalization = NULL;
	float* colors = NULL;
	unsigned char* cube_ind = NULL;
	float x = 0, y = 0, z = 0;
public:
	virtual void draw() = 0;
	~Primitive2D();
};

