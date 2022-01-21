#include "Observer.h"

/**
 * .
 * \brief Rotacja obserwatora
 * \param x Przesuniecie wzgledem wspolrzednych X
 * \param y Przesuniecie wzgledem wspolrzednych Y
 * \param z Przesuniecie wzgledem wspolrzednych Z
 * \param degree Stopien rotacji
 */
void Observer::rotate(int x, int y, int z, float degree)
{
	glRotatef(x, y, z, degree);
}

/**
 * .
 * \brief Przesuniecie obserwatora
 * \param x Przesuniecie wzgledem wspolrzednych X
 * \param y Przesuniecie wzgledem wspolrzednych Y
 * \param z Przesuniecie wzgledem wspolrzednych Z
 */
void Observer::moveBy(float x, float y, float z)
{
	glTranslatef(x, y, z);
}
