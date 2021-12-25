#include "Player.h"

void Player::onKeyboardClick(unsigned char key)
{
	switch (key)
	{
	case 'a':
	{
		glTranslatef(0.1f, 0.f, 0.f);
		x += 0.1f;
	}
	break;
	case 'd':
	{
		glTranslatef(-0.1f, 0.f, 0.f);
		x += -0.1f;
	}
	break;
	case 'w':
	{
		glTranslatef(0.f, 0.f, 0.1f);
		z += 0.1f;
	}
	break;
	case 's':
	{
		glTranslatef(0.f, 0.f, -0.1f);
		z += -0.1f;
	}
	break;
	default:
		break;
	}
}

void Player::onMouseMove(int x, int y)
{
	int buffX = mouseX - x;
	int buffY = mouseY - y;

	mouseX = x;
	mouseY = y;

	if (buffX < 0)
		glRotatef(-1.f, 0, y, 0);
	else if(buffX > 0)
		glRotatef(1.f, 0, y, 0);
}

void Player::setStartCords(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
