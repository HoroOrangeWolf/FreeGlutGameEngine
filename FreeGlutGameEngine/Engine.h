#pragma once
#include <gl/freeglut.h>
#include "Cube.h"
#include "Square.h"
#include "Triangle.h"
#include "RandomLetter.h"
#include "Player.h"

class Engine
{
private:
	static char *title;
	static float r,g,b;
	static unsigned int modes, width, height, fps;
	static void onDraw();
	static void onTimer(int val);
	static void mouse(int x, int y);
	static void keyboard(unsigned char key, int x, int y);
	static Cube square;
	static Square sq1;
	static Triangle tr1;
	static RandomLetter random;
	static Player player;

public:
	Engine(char* title, float r, float g, float b);
	void setModes(unsigned int e);
	void setUp();
	void run();
	void setSize(unsigned int width,unsigned int height);
	void setFps(unsigned int fps);
};

