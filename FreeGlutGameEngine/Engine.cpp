#include "Engine.h"
#include <iostream>
#include <glm/fwd.hpp>
#include <glm/glm.hpp>

GLfloat lightAmb[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat lightDif[] = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat lightSpc[] = { 0.2f, 0.2f, 0.2f, 0.2f };
GLfloat lightPos[] = { 0.f, 0.f, -5.0f, 1.0f };

void Engine::onDraw()
{


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Switch to model-view matrix:
	glMatrixMode(GL_MODELVIEW);
	glClearColor(r, g, b, 1.0);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif);

	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpc);

	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glMaterialfv(GL_FRONT, GL_SPECULAR, lightSpc);
	glMateriali(GL_FRONT, GL_SHININESS, 8);


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
	//player.onMouseMove(x, y);
}

void Engine::keyboard(unsigned char key, int x, int y)
{
	//player.onKeyboardClick(key);
	std::cout << key;
	switch (key) {
	case '1':
		square.rotate(1, 0, 0, 3.f);
		lightPos[0] -= 0.1f;
		glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpc);
		break;
	case '2':
		square.rotate(0, 1, 0, 3.f);
		//lightPos[0] += 0.1f;
		glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpc);
		break;
	case '3':
		square.rotate(0, 0, 1, 3.f);
		break;
	case '4':
		lightPos[0] -= 0.1f;
		break;
	case '5':
		lightPos[0] += 0.1f;
		break;
	}
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

void Engine::setShading(int shade)
{
	shading = shade;
}

void Engine::setModes(unsigned int e)
{
	Engine::modes = e;
}

void Engine::setUp()
{

	//square.rotate(1, 0, 0, 50.f);
	//square.rotate(0, 1, 0, 30.f);
	//square.rotate(0, 0, 1, 70.f);
	glutInitDisplayMode(modes);
	glutInitWindowSize(width, height);

	glutCreateWindow(title);

	glEnable(GL_DEPTH_TEST);
	// Lighting ON:
	glEnable(GL_LIGHTING);

	glEnable(GL_TEXTURE_2D);


	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif);

	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpc);

	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);


	glEnable(GL_LIGHT0);

	glMaterialfv(GL_FRONT, GL_SPECULAR, lightSpc);
	glMateriali(GL_FRONT, GL_SHININESS, 64);
	
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	
	glShadeModel(shading);

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

	glutKeyboardFunc(&Engine::keyboard);
	glutPassiveMotionFunc(&Engine::mouse);

	glutDisplayFunc(&Engine::onDraw);

	glutTimerFunc(1000 / fps, onTimer, 0);

	

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

Cube Engine::square = Cube(-0.5f, -0.5f, -0.5f, 1.f, "jozga.png");
Square Engine::sq1 = Square(-2.5f, 0.f, 0.f, 1.f);
Triangle Engine::tr1 = Triangle(0.f, 0.f, 0.f, 1.f, 1.f);
RandomLetter Engine::random = RandomLetter(-2.f, 2.f);
Player Engine::player = Player();

int Engine::shading = GL_SMOOTH;

char* Engine::title = NULL;

