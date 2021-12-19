#include "Cube.h"

Cube::Cube(float x, float y, float z, float width)
{
	this->x = x;
	this->y = y;
	this->z = z;


	this->width = width;

	this->vertex = new float[72]{
	x, y,  z+width,	 x+width, y,  z+width,	x,  y+width,  z+width,	 x+width,  y+width,  z+width,
	x, y, z,	x,  y+width, z,	 x+width, y, z,	 x+width,  y+width, z,
	x,  y+width, z,	x,  y+width,  z+width,	 x+width,  y+width, z,	 x+width,  y+width,  z+width,
	x, y, z,	 x+width, y, z,	x, y,  z+width,	 x+width, y,  z+width,
	 x+width, y, z,	 x+width,  y+width, z,	 x+width, y,  z+width,	 x+width,  y+width,  z+width,
	x, y, z,	x, y,  z+width,	x,  y+width, z,	x,  y+width,  z+width,
	};

	
	this->cube_ind = new unsigned char[36]{
	0, 1, 2,    // strona 1
	2, 1, 3,
	4, 5, 6,    // strona 2
	6, 5, 7,
	8, 9, 10,    // strona 3
	10, 9, 11,
	12, 13, 14,    // strona 4
	14, 13, 15,
	16, 17, 18,    // strona 5
	18, 17, 19,
	20, 21, 22,    // strona 6
	22, 21, 23,
	};
	
	/*
	
	this->cube_ind = new unsigned char[36]{
		//str1
		0, 1, 2,
		2, 1, 3,
		//str2
		4, 5, 6,
		6, 5, 7,
		//str3
		8, 9 , 10,
		10, 9, 11,
		//str4
		12, 13, 14,
		14, 13, 15,
		//str5
		16, 17, 18,
		18, 17, 19,
		//str6
		20, 21, 22,
		22, 21, 23
	};
	*/
	

	this->normalization = new float[72]{
	 0.0f, 0.0f, 1.0f,	 0.0f, 0.0f, 1.0f,	 0.0f, 0.0f, 1.0f,	 0.0f, 0.0f, 1.0f,
	 0.0f, 0.0f,-1.0f,	 0.0f, 0.0f,-1.0f,	 0.0f, 0.0f,-1.0f,	 0.0f, 0.0f,-1.0f,
	 0.0f, 1.0f, 0.0f,	 0.0f, 1.0f, 0.0f,	 0.0f, 1.0f, 0.0f,	 0.0f, 1.0f, 0.0f,
	 0.0f,-1.0f, 0.0f,	 0.0f,-1.0f, 0.0f,	 0.0f,-1.0f, 0.0f,	 0.0f,-1.0f, 0.0f,
	 1.0f, 0.0f, 0.0f,	 1.0f, 0.0f, 0.0f,	 1.0f, 0.0f, 0.0f,	 1.0f, 0.0f, 0.0f,
	-1.0f, 0.0f, 0.0f,	-1.0f, 0.0f, 0.0f,	-1.0f, 0.0f, 0.0f,	-1.0f, 0.0f, 0.0f
		
	};

	this->colors = new float[72]{
		//sciana1
		1.0f, 0.7f, 0.7f,
		.2f, 0.1f, 0.7f,
		0.5f, 0.1f, 0.3f,
		.0f, .5f, 1.f,
		//sciana2
		
		1.0f, 0.7f, 0.7f,
		1.0f, 0.7f, 0.7f,
		1.0f, 0.7f, 0.7f,
		1.0f, 0.7f, 0.7f,
		//sciana3
		0.5f, 0.1f, 0.3f,
		0.5f, 0.1f, 0.3f,
		0.5f, 0.1f, 0.3f,
		0.5f, 0.1f, 0.3f,
		//sciana4
		.2f, 0.4f, 0.7f,
		.2f, 0.4f, 0.7f,
		.2f, 0.4f, 0.7f,
		.2f, 0.4f, 0.7f,
		//sciana5
		1.0f, 1.f, 0.1f,
		1.0f, 1.f, 0.1f,
		1.0f, 1.f, 0.1f,
		1.0f, 1.f, 0.1f,
		//sciana6
		0.1f, 0.9f, 0.3f,
		0.1f, 0.9f, 0.3f,
		0.1f, 0.9f, 0.3f,
		0.1f, 0.9f, 0.3f,
		
	};
}

void Cube::draw()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertex);

	glEnableClientState(GL_NORMAL_ARRAY);
	glNormalPointer(GL_FLOAT, 0, normalization);

	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, colors);

	glDrawElements(GL_TRIANGLES, sizeof(unsigned char) * 36, GL_UNSIGNED_BYTE, cube_ind);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

Cube::~Cube()
{
	if (vertex != NULL)
		delete vertex;

	if (normalization != NULL)
		delete normalization;

	if (colors != NULL)
		delete colors;

	if (cube_ind != NULL)
		delete cube_ind;
}

