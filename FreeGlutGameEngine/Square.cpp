#include "Square.h"

Square::Square(float x, float y, float z, float width)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->width = width;


	this->vertex = new float[12]{
		//p1
		x,y,z,
		//p2
		x + width,y, z,
		//p3
		x + width, y + width, z,
		x, y + width, z
	};

	this->colors = new float[4]{
		1.f, 1.f, 1.f, 1.f
	};

	this->normalization = new float[12]{
		0.0f, 0.0f, 1.0f,	 0.0f, 0.0f, 1.0f,	 0.0f, 0.0f, 1.0f,	 0.0f, 0.0f, 1.0f,
	};


	

	this->cube_ind = new unsigned char[6]{
		0, 1, 2,
		0, 2, 3
	};

}

void Square::draw()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertex);

	glEnableClientState(GL_NORMAL_ARRAY);
	glNormalPointer(GL_FLOAT, 0, normalization);

	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, colors);

	glDrawElements(GL_TRIANGLES, sizeof(unsigned char) * 6, GL_UNSIGNED_BYTE, cube_ind);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}
