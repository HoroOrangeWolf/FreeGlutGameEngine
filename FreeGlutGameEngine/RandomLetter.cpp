#include "RandomLetter.h"

#include <gl/freeglut.h>
#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define PI 3.14159265

#define angle PI/180.f

RandomLetter::RandomLetter(float x, float y)
{
	this->vertex = new float[] {
		x,y, 0.f,	x, y-1.f, 0.f,	x+5.f, y-1.f, 0.f,	x +5.f, y, 0.f,

		x,y - 2.f, 0.f,	x, y-1.f - 2.f, 0.f,	x+5.f, y-1.f - 2.f, 0.f,	x +5.f, y - 2.f, 0.f,

		x,y - 4.f, 0.f,	x, y-1.f - 4.f, 0.f,	x+5.f, y-1.f - 4.f, 0.f,	x +5.f, y - 4.f, 0.f,

		x,y, 0.f,	x, y - 5.f, 0.f,	x+1.f, y-5.f, 0.f,	x+1.f, y, 0.f
	};

	this->colors = new float[] {
		0.40f, 0.86f, 0.75f, 0.53f, 0.07f, 0.85f, 0.47f, 0.77f, 0.94f, 0.55f, 0.12f, 0.32f,

		0.72f, 0.61f, 0.58f, 0.64f, 0.18f, 0.08f, 0.23f, 0.89f, 0.27f, 0.26f, 0.58f, 0.16f,

		0.36f, 0.43f, 0.11f, 0.76f, 0.28f, 0.05f, 0.13f, 0.64f, 0.47f, 0.53f, 0.42f, 0.76f,

		0.74f, 0.90f, 0.58f, 0.57f, 0.76f, 0.81f, 0.11f, 0.26f, 0.40f, 0.51f, 0.87f, 0.41f
	};

	this->normalization = new float[] {
		0.f, 0.f, 1.f, 0.f, 0.f, 1.f, 0.f, 0.f, 1.f, 0.f, 0.f, 1.f,

		0.f, 0.f, 1.f, 0.f, 0.f, 1.f, 0.f, 0.f, 1.f, 0.f, 0.f, 1.f,

		0.f, 0.f, 1.f, 0.f, 0.f, 1.f, 0.f, 0.f, 1.f, 0.f, 0.f, 1.f,

		0.f, 0.f, 1.f, 0.f, 0.f, 1.f, 0.f, 0.f, 1.f, 0.f, 0.f, 1.f
	};

	this->cube_ind = new unsigned char[] {
		0, 1, 2,
		0, 2, 3,

		4, 5, 6,
		4, 6, 7,

		8, 9, 10,
		8, 10, 11,

		12, 13, 14,
		12, 14, 15
	};

	for (int i = 0; i < 48; i += 12) {
		float b[] = { vertex[i + 6] - vertex[i + 3], vertex[i + 7] - vertex[i + 4], vertex[i + 8] - vertex[i + 5] };
		float a[] = { vertex[i] - vertex[i + 3], vertex[i + 1] - vertex[i + 4], vertex[i + 2] - vertex[i + 5] };
		float p[]{ 0.f, 0.f, 0.f };
		crossProduct(a, b, p);

		for (int u = i; u < i + 12; u += 3) {
			normalization[u] = p[0];
			normalization[u + 1] = p[1];
			normalization[u + 2] = p[2];
		}
	}

}

void RandomLetter::draw()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertex);

	glEnableClientState(GL_NORMAL_ARRAY);
	glNormalPointer(GL_FLOAT, 0, normalization);

	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, colors);

	glDrawElements(GL_TRIANGLES, sizeof(unsigned char) * 24, GL_UNSIGNED_BYTE, cube_ind);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}


void RandomLetter::moveBy(float x, float y, float z)
{
	for (int i = 0; i < 24; i += 3) {
		vertex[i] += x;
		vertex[i + 1] += y;
		vertex[i + 2] += z;
	}
}

void RandomLetter::rotate(int x, int y, int z, float degree)
{
	degree = degree * angle;

	if (x == 1) {
		glm::mat4 mX(glm::f32(1.f), glm::f32(0.f), glm::f32(0.f), glm::f32(0.f),
			glm::f32(0.f), glm::f32(cos(degree)), glm::f32(-sin(degree)), glm::f32(0.f),
			glm::f32(0.f), glm::f32(sin(degree)), glm::f32(cos(degree)), glm::f32(0.f),
			glm::f32(0.f), glm::f32(0.f), glm::f32(0.f), glm::f32(1.f)
		);

		for (int i = 0; i < 48; i += 12) {
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
	else if (y == 1) {
		glm::mat4 mX(glm::f32(cos(degree)), glm::f32(0.f), glm::f32(-sin(degree)), glm::f32(0.f),
			glm::f32(0.f), glm::f32(1.f), glm::f32(0.f), glm::f32(0.f),
			glm::f32(sin(degree)), glm::f32(0.f), glm::f32(cos(degree)), glm::f32(0.f),
			glm::f32(0.f), glm::f32(0.f), glm::f32(0.f), glm::f32(1.f)
		);

		for (int i = 0; i < 48; i += 12) {
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

		for (int i = 0; i < 48; i += 12) {
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

	for (int i = 0; i < 48; i += 12) {
		float b[] = { vertex[i + 6] - vertex[i + 3], vertex[i + 7] - vertex[i + 4], vertex[i + 8] - vertex[i + 5] };
		float a[] = { vertex[i] - vertex[i + 3], vertex[i + 1] - vertex[i + 4], vertex[i + 2] - vertex[i + 5] };
		float p[]{ 0.f, 0.f, 0.f };
		crossProduct(a, b, p);

		for (int u = i; u < i + 12; u += 3) {
			normalization[u] = p[0];
			normalization[u + 1] = p[1];
			normalization[u + 2] = p[2];
		}
	}
}

void RandomLetter::scale(float k)
{
	for (int i = 0; i < 48; i += 3) {
		vertex[i] *= k;
		vertex[i + 1] *= k;
		vertex[i + 2] *= k;
	}
}
