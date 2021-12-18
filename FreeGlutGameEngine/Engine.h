#pragma once
#include <gl/freeglut.h>
#include "Square.h"
class Engine
{
private:
	static char *title;
	static float r,g,b;
	static unsigned int modes, width, height, fps;
	static void onDraw();
	static void onTimer(int val);
	static void mouse(int button, int state, int x, int y);
	static void keyboard(unsigned char key, int x, int y);
	static Square square;
public:
	Engine(char* title, float r, float g, float b);
	void setModes(unsigned int e);
	void setUp();
	void run();
	void setSize(unsigned int width,unsigned int height);
	void setFps(unsigned int fps);
};

