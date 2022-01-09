#include "Player.h"
#include <glm/ext/matrix_transform.hpp>
#include <iostream>
GLuint programID;
void Player::onKeyboardClick(unsigned char key)
{
	switch (key)
	{
	case 'a':
	{
		//glTranslatef(0.1f, 0.f, 0.f);
		x += 0.1f;
	}
	break;
	case 'd':
	{
		//glTranslatef(-0.1f, 0.f, 0.f);
		x += -0.1f;
	}
	break;
	case 'w':
	{
		//glTranslatef(0.f, 0.f, 0.1f);
		z += 0.1f;
	}
	break;
	case 's':
	{
		//glTranslatef(0.f, 0.f, -0.1f);
		z += -0.1f;
	}
	break;
	default:
		break;
	}
	
	glm::mat4 view = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	float radius = 10.0f;
	float camX = sin(std::rand()) * radius;
	float camZ = cos(std::rand()) * radius;
	view = glm::lookAt(glm::vec3(camX, 0.0f, camZ), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUseProgram(programID);
	//GLint eyePositionWorldUniformLocation = glGetUniformLocation(programID, "eyePositionWorld");
	
	
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
