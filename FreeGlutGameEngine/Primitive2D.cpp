#include "Primitive2D.h"

Primitive2D::~Primitive2D()
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
