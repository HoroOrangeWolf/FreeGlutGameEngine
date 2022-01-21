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

	
	

	this->cube_ind = new unsigned char[6]{
		0, 1, 2,
		0, 2, 3
	};

	for (int i = 0; i < 12; i += 12) {
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

void Square::moveBy(float x, float y, float z)
{
	for (int i = 0; i < 12; i += 3) {
		vertex[i] += x;
		vertex[i + 1] += y;
		vertex[i + 2] += z;
	}
}

void Square::rotate(int x, int y, int z, float degree)
{
	degree = degree * angle;

	if (x == 1) {
		glm::mat4 mX(glm::f32(1.f), glm::f32(0.f), glm::f32(0.f), glm::f32(0.f),
			glm::f32(0.f), glm::f32(cos(degree)), glm::f32(-sin(degree)), glm::f32(0.f),
			glm::f32(0.f), glm::f32(sin(degree)), glm::f32(cos(degree)), glm::f32(0.f),
			glm::f32(0.f), glm::f32(0.f), glm::f32(0.f), glm::f32(1.f)
		);

		for (int i = 0; i < 12; i += 12) {
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

		for (int i = 0; i < 12; i += 12) {
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

		for (int i = 0; i < 12; i += 12) {
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

	for (int i = 0; i < 12; i += 12) {
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

void Square::scale(float k)
{
	for (int i = 0; i < 12; i += 3) {
		vertex[i] *= k;
		vertex[i + 1] *= k;
		vertex[i + 2] *= k;
	}
}


