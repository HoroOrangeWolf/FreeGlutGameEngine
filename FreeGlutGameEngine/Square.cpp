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
		//p4
		x, y + width, z
	};

	this->colors = new float[4]{
		1.f, 1.f, 1.f, 1.f
	};

	this->normalization = new float[12]{
		0.0f, 0.0f, 1.0f,	 0.0f, 0.0f, 1.0f,	 0.0f, 0.0f, 1.0f,	 0.0f, 0.0f, 1.0f,
	};

	float an = 40.f * angle;

	glm::mat4 mX(glm::f32(1.f), glm::f32(0.f), glm::f32(0.f), glm::f32(0.f),
		glm::f32(0.f), glm::f32(cos(an)), glm::f32(-sin(an)), glm::f32(0.f),
		glm::f32(0.f), glm::f32(sin(an)), glm::f32(cos(an)), glm::f32(0.f),
		glm::f32(0.f), glm::f32(0.f), glm::f32(0.f), glm::f32(1.f)
	);

	glm::mat4 toRotate(
		glm::f32(vertex[0]), glm::f32(vertex[3]), glm::f32(vertex[6]), glm::f32(vertex[9]),
		glm::f32(vertex[1]), glm::f32(vertex[4]), glm::f32(vertex[7]), glm::f32(vertex[10]),
		glm::f32(vertex[2]), glm::f32(vertex[5]), glm::f32(vertex[8]), glm::f32(vertex[11]),
		glm::f32(1.f), glm::f32(1.f), glm::f32(1.f), glm::f32(1.f)
	);
	
	glm::mat4 result = toRotate*mX;
	
	vertex[0] = result[0][0];
	vertex[1] = result[1][0];
	vertex[2] = result[2][0];

	vertex[3] = result[0][1];
	vertex[4] = result[1][1];
	vertex[5] = result[2][1];

	vertex[6] = result[0][2];
	vertex[7] = result[1][2];
	vertex[8] = result[2][2];

	vertex[9] = result[0][3];
	vertex[10] = result[1][3];
	vertex[11] = result[2][3];
	

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
