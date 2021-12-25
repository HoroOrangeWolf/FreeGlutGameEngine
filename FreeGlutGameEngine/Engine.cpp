#include "Engine.h"
#include <iostream>
#include <glm/fwd.hpp>
#include <glm/glm.hpp>

void Engine::onDraw()
{

	glClearColor(r, g, b, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	square.draw();
	sq1.draw();
	//sq1.draw();
	glutSwapBuffers();
}


void Engine::onTimer(int val)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / fps, &Engine::onTimer, 0);
}

void Engine::mouse(int x, int y)
{
	player.onMouseMove(x, y);
}

void Engine::keyboard(unsigned char key, int x, int y)
{
	player.onKeyboardClick(key);
	//glRotatef(1.f, 0, 0, 1);
	//glRotatef(1.f, 0, 0, 1);
	//glRotatef(1.f, 0, 1, 0);
	//glRotatef(1.f, 1, 0, 0);
}

Engine::Engine(char* title, float r, float g, float b)
{
	Engine::title = title;
	Engine::r = r;
	Engine::g = g;
	Engine::b = b;


}

void Engine::setModes(unsigned int e)
{
	Engine::modes = e;
}

void Engine::setUp()
{

	glutInitDisplayMode(modes);
	glutInitWindowSize(width, height);

	glutCreateWindow(title);

	//glViewport(0, 0, width, height);
	//glEnable(GL_DEPTH_TEST);
	//glEnable(GL_LIGHTING);

	glViewport(0, 0, width, height);

	glClearColor(0.1, 0.5, 0.5, 1.0);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-2, 2, -1.5, 1.5, 1, 40);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, -3);
	player.setStartCords(0, 0, -3);
	//glRotatef(20, 1, 0, 0);
	//glRotatef(50, 0, 1, 0);

	glutDisplayFunc(&Engine::onDraw);

	glutTimerFunc(1000 / fps, onTimer, 0);

	glutKeyboardFunc(&Engine::keyboard);
	glutPassiveMotionFunc(&Engine::mouse);

}

void Engine::run()
{
	glutMainLoop();
}

void Engine::setSize(unsigned int width, unsigned int height)
{
	Engine::width = width;
	Engine::height = height;
}

void Engine::setFps(unsigned int fps)
{
	Engine::fps = fps;
}

float Engine::r = 0.0f;
float Engine::g = 0.0f;
float Engine::b = 0.0f;

unsigned int Engine::width = 800;
unsigned int Engine::height = 600;
unsigned int Engine::modes = GLUT_RGB;
unsigned int Engine::fps = 60;

Cube Engine::square = Cube(-0.5f, -0.5f, -0.5f, 1.f);
Square Engine::sq1 = Square(-2.5f, 0.f, 0.f, 1.f);
Triangle Engine::tr1 = Triangle(0.f, 0.f, 0.f, 1.f, 1.f);
RandomLetter Engine::random = RandomLetter(-2.f, 2.f);
Player Engine::player = Player();

char* Engine::title = NULL;

