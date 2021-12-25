#include "Observer.h"

void Observer::rotate(int x, int y, int z, float degree)
{
	glRotatef(x, y, z, degree);
}

void Observer::moveBy(float x, float y, float z)
{
	glTranslatef(x, y, z);
}
