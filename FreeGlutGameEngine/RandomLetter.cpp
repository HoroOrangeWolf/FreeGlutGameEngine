#include "RandomLetter.h"

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
