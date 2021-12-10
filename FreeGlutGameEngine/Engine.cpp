#include "Engine.h"
#include <iostream>

void Engine::onDraw()
{
	glClearColor(r, g, b, 1.0f);
	// Clearing the colour buffer:
	glClear(GL_COLOR_BUFFER_BIT);
	// Flushing the rendering queue:
	glutSwapBuffers();
}


void Engine::onTimer(int val)
{
	Engine::r += 0.01f;
	if (Engine::r > 1.f)
		Engine::r = 0.f;
	glutPostRedisplay();
	glutTimerFunc(1000 / fps, &Engine::onTimer, 0);
}

void Engine::mouse(int button, int state, int x, int y)
{
	std::cout << "Mouse \n";
}

void Engine::keyboard(unsigned char key, int x, int y)
{
	std::cout << "keyboard \n";
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

	glutDisplayFunc(&Engine::onDraw);

	glutTimerFunc(1000 / fps, onTimer, 0);

	glutKeyboardFunc(&Engine::keyboard);
	glutMouseFunc(&Engine::mouse);

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

char* Engine::title = NULL;

