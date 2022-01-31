#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <gl/freeglut.h>
#include "Engine.h"
/**
 * .
 * \brief Funkcja main
 * \param argc
 * \param argv
 * \return 
 */
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