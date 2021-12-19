#include "Triangle.h"

Triangle::Triangle(float x, float y, float z, float a, float height)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->height = height;
	this->a = a;


	this->vertex = new float[9]{
		//p1
		x,y,z,
		//p2
		x + a, y, z,
		x + a, y + height, z
	};

	this->colors = new float[3]{
		1.f, 1.f, 1.f
	};

	this->normalization = new float[9]{
		0.0f, 0.0f, 1.0f,	 0.0f, 0.0f, 1.0f,	 0.0f, 0.0f, 1.0f,
	};




	this->cube_ind = new unsigned char[6]{
		0, 1, 2,
	};

}

void Triangle::draw()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertex);

	glEnableClientState(GL_NORMAL_ARRAY);
	glNormalPointer(GL_FLOAT, 0, normalization);

	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, colors);

	glDrawElements(GL_TRIANGLES, sizeof(unsigned char) * 3, GL_UNSIGNED_BYTE, cube_ind);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}
