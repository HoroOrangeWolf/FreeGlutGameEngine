#include "Cube.h"
#include <iostream>

void cross_product(float *p1, float *p2, float *p3) {

	p3[0] = p1[1] * p2[2] - p1[2] * p2[1];
	p3[1] = -(p1[0] * p2[2] - p1[2] * p2[0]);
    p3[2] = p1[0] * p2[1] - p1[1] * p2[0];
}

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

	this->normalization = new float[72]{
	 1.0f, 0.0f, 0.0f,	 1.0f, 0.0f, 0.0f,	 1.0f, 0.0f, 0.0f,	 1.0f, 0.0f, 0.0f,
	 1.0f, 0.0f, 0.0f,	 1.0f, 0.0f, 0.0f,	 1.0f, 0.0f, 0.0f,	 1.0f, 0.0f, 0.0f,
	 1.0f, 0.0f, 0.0f,	 1.0f, 0.0f, 0.0f,	 1.0f, 0.0f, 0.0f,	 1.0f, 0.0f, 0.0f,
	 1.0f, 0.0f, 0.0f,	 1.0f, 0.0f, 0.0f,	 1.0f, 0.0f, 0.0f,	 1.0f, 0.0f, 0.0f,
	 1.0f, 0.0f, 0.0f,	 1.0f, 0.0f, 0.0f,	 1.0f, 0.0f, 0.0f,	 1.0f, 0.0f, 0.0f,
	 1.0f, 0.0f, 0.0f,	 1.0f, 0.0f, 0.0f,	 1.0f, 0.0f, 0.0f,	 1.0f, 0.0f, 0.0f,
	
	};

	for (int i = 0; i < 72; i += 12) {
		float b[] = { vertex[i + 6] - vertex[i + 3], vertex[i + 7] - vertex[i + 4], vertex[i + 8] - vertex[i + 5] };
		float a[] = { vertex[i] - vertex[i + 3], vertex[i + 1] - vertex[i + 4], vertex[i + 2] - vertex[i + 5] };
		float p[]{ 0.f, 0.f, 0.f };
		cross_product(a, b, p);

		for (int u = i; u < i + 12; u += 3) {
			normalization[u] = p[0];
			normalization[u + 1] = p[1];
			normalization[u + 2] = p[2];
		}
	}

	this->colors = new float[72]{
		0.02f, 0.11f, 0.55f, 0.97f, 0.43f, 0.15f, 0.53f, 0.58f, 0.20f, 0.60f, 0.10f, 0.97f,

		0.73f, 0.51f, 0.88f, 0.55f, 0.60f, 0.12f, 0.91f, 0.32f, 0.82f, 0.36f, 0.94f, 0.90f,

		0.49f, 0.74f, 0.45f, 0.97f, 0.18f, 0.97f, 0.29f, 0.11f, 0.50f, 0.53f, 0.37f, 0.97f,

		0.89f, 0.47f, 0.50f, 0.84f, 0.59f, 0.98f, 0.83f, 0.76f, 0.96f, 0.62f, 0.44f, 0.93f,

		0.0f, 0.0f, 1.0f,	 0.0f, 0.0f, 1.0f,	 0.0f, 0.0f, 1.0f,	 0.0f, 0.0f, 1.0f,

		0.99f, 0.62f, 0.30f, 0.01f, 0.52f, 0.62f, 0.89f, 0.79f, 0.63f, 0.10f, 0.64f, 0.74f,
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

void Cube::moveBy(float x, float y, float z)
{
	for (int i = 0; i < 72; i += 3) {
		vertex[i] += x;
		vertex[i+1] += y;
		vertex[i+2] += z;
	}

	for (int i = 0; i < 72; i += 12) {
		float b[] = { vertex[i + 6] - vertex[i + 3], vertex[i + 7] - vertex[i + 4], vertex[i + 8] - vertex[i + 5] };
		float a[] = { vertex[i] - vertex[i + 3], vertex[i + 1] - vertex[i + 4], vertex[i + 2] - vertex[i + 5] };
		float p[]{ 0.f, 0.f, 0.f };
		cross_product(a, b, p);

		for (int u = i; u < i + 12; u += 3) {
			normalization[u] = p[0];
			normalization[u + 1] = p[1];
			normalization[u + 2] = p[2];
		}
	}
		
}

void Cube::rotate(int x, int y, int z, float degree)
{
	degree = degree * angle;

	if (x == 1) {
		glm::mat4 mX(glm::f32(1.f), glm::f32(0.f), glm::f32(0.f), glm::f32(0.f),
			glm::f32(0.f), glm::f32(cos(degree)), glm::f32(-sin(degree)), glm::f32(0.f),
			glm::f32(0.f), glm::f32(sin(degree)), glm::f32(cos(degree)), glm::f32(0.f),
			glm::f32(0.f), glm::f32(0.f), glm::f32(0.f), glm::f32(1.f)
		);

		for (int i = 0; i < 72; i += 12) {
			glm::mat4 toRotate(
				glm::f32(vertex[i]), glm::f32(vertex[i + 3]), glm::f32(vertex[i + 6]), glm::f32(vertex[i + 9]),
				glm::f32(vertex[i + 1]), glm::f32(vertex[i + 4]), glm::f32(vertex[i + 7]), glm::f32(vertex[i + 10]),
				glm::f32(vertex[i + 2]), glm::f32(vertex[i + 5]), glm::f32(vertex[i + 8]), glm::f32(vertex[i + 11]),
				glm::f32(1.f), glm::f32(1.f), glm::f32(1.f), glm::f32(1.f)
			);

			glm::mat4 result = toRotate * mX;

			vertex[i] = result[0][0];
			vertex[i+1] = result[1][0];
			vertex[i+2] = result[2][0];

			vertex[i+3] = result[0][1];
			vertex[i+4] = result[1][1];
			vertex[i+5] = result[2][1];

			vertex[i+6] = result[0][2];
			vertex[i+7] = result[1][2];
			vertex[i+8] = result[2][2];

			vertex[i+9] = result[0][3];
			vertex[i+10] = result[1][3];
			vertex[i+11] = result[2][3];
		}

	}
	else if (y == 1) {
		glm::mat4 mX(glm::f32(cos(degree)), glm::f32(0.f), glm::f32(-sin(degree)), glm::f32(0.f),
			glm::f32(0.f), glm::f32(1.f), glm::f32(0.f), glm::f32(0.f),
			glm::f32(sin(degree)), glm::f32(0.f), glm::f32(cos(degree)), glm::f32(0.f),
			glm::f32(0.f), glm::f32(0.f), glm::f32(0.f), glm::f32(1.f)
		);

		for (int i = 0; i < 72; i += 12) {
			glm::mat4 toRotate(
				glm::f32(vertex[i]), glm::f32(vertex[i + 3]), glm::f32(vertex[i + 6]), glm::f32(vertex[i + 9]),
				glm::f32(vertex[i + 1]), glm::f32(vertex[i + 4]), glm::f32(vertex[i + 7]), glm::f32(vertex[i + 10]),
				glm::f32(vertex[i + 2]), glm::f32(vertex[i + 5]), glm::f32(vertex[i + 8]), glm::f32(vertex[i + 11]),
				glm::f32(1.f), glm::f32(1.f), glm::f32(1.f), glm::f32(1.f)
			);

			glm::mat4 result = toRotate * mX;

			vertex[i] = result[0][0];
			vertex[i + 1] = result[1][0];
			vertex[i + 2] = result[2][0];

			vertex[i + 3] = result[0][1];
			vertex[i + 4] = result[1][1];
			vertex[i + 5] = result[2][1];

			vertex[i + 6] = result[0][2];
			vertex[i + 7] = result[1][2];
			vertex[i + 8] = result[2][2];

			vertex[i + 9] = result[0][3];
			vertex[i + 10] = result[1][3];
			vertex[i + 11] = result[2][3];
		}
	}
	else if (z == 1) {
		glm::mat4 mX(glm::f32(cos(degree)), glm::f32(-sin(degree)), glm::f32(0.f), glm::f32(0.f),
			glm::f32(sin(degree)), glm::f32(cos(degree)), glm::f32(0.f), glm::f32(0.f),
			glm::f32(0.f), glm::f32(0.f), glm::f32(1.f), glm::f32(0.f),
			glm::f32(0.f), glm::f32(0.f), glm::f32(0.f), glm::f32(1.f)
		);

		for (int i = 0; i < 72; i += 12) {
			glm::mat4 toRotate(
				glm::f32(vertex[i]), glm::f32(vertex[i + 3]), glm::f32(vertex[i + 6]), glm::f32(vertex[i + 9]),
				glm::f32(vertex[i + 1]), glm::f32(vertex[i + 4]), glm::f32(vertex[i + 7]), glm::f32(vertex[i + 10]),
				glm::f32(vertex[i + 2]), glm::f32(vertex[i + 5]), glm::f32(vertex[i + 8]), glm::f32(vertex[i + 11]),
				glm::f32(1.f), glm::f32(1.f), glm::f32(1.f), glm::f32(1.f)
			);

			glm::mat4 result = toRotate * mX;

			vertex[i] = result[0][0];
			vertex[i + 1] = result[1][0];
			vertex[i + 2] = result[2][0];

			vertex[i + 3] = result[0][1];
			vertex[i + 4] = result[1][1];
			vertex[i + 5] = result[2][1];

			vertex[i + 6] = result[0][2];
			vertex[i + 7] = result[1][2];
			vertex[i + 8] = result[2][2];

			vertex[i + 9] = result[0][3];
			vertex[i + 10] = result[1][3];
			vertex[i + 11] = result[2][3];
		}
	}

	for (int i = 0; i < 72; i += 12) {
		float b[] = { vertex[i + 6] - vertex[i + 3], vertex[i + 7] - vertex[i + 4], vertex[i + 8] - vertex[i + 5] };
		float a[] = { vertex[i] - vertex[i + 3], vertex[i + 1] - vertex[i + 4], vertex[i + 2] - vertex[i + 5] };
		float p[]{ 0.f, 0.f, 0.f };
		cross_product(a, b, p);

		for (int u = i; u < i + 12; u += 3) {
			normalization[u] = p[0];
			normalization[u + 1] = p[1];
			normalization[u + 2] = p[2];
		}
	}
	
	for (int i = 0; i < 72; i += 12) {
		for (int q = i; q < i + 12; q += 3) {
			std::cout << normalization[q] << ' ' << normalization[q + 1] << ' ' << normalization[q + 3] << " | ";
		}
		std::cout << '\n';
	}
	
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

