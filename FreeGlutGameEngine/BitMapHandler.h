#pragma once
#include <string>
#include <gl/freeglut.h>

class BitMapHandler
{
private:
	unsigned char* text = NULL;
	int width, height, nchan;
	std::string name;
protected:
	float* cube_texc = NULL;
	void drawTexture();
public:
	BitMapHandler(std::string name);
	~BitMapHandler();
};

