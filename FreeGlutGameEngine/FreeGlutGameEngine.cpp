/*	OpenGL - example program with FreeGLUT / GLUT
 *	(C) 2009, 2020 Grzegorz �ukawski, Politechnika �wi�tokrzyska w Kielcach
 */

#include <gl/freeglut.h>
#include "Engine.h"

int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	char title[] = "Nice title";
	Engine engine(title, 0.5f, 0.5f, 0.5f);

	engine.setFps(60);
	engine.setModes(GLUT_RGB | GLUT_DOUBLE);
	engine.setSize(800, 600);
	engine.setShading(GL_SMOOTH);
	engine.setUp();
	engine.run();

	return(0);
}