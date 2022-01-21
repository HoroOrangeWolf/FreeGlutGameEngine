#include "Primitive2D.h"

/**
 * .
 * \brief Oblicza wektor normalny
 * \param p1 Wektor 1
 * \param p2 Wektor 2
 * \param p3 Wektor wyjsciowy
 */
void Primitive2D::crossProduct(float *p1, float *p2, float *p3)
{
	p3[0] = p1[1] * p2[2] - p1[2] * p2[1];
	p3[1] = -(p1[0] * p2[2] - p1[2] * p2[0]);
	p3[2] = p1[0] * p2[1] - p1[1] * p2[0];
}

/**
 * .
 * \brief Destruktor
 */
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
