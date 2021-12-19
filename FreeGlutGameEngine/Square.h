#pragma once
#include "Primitive2D.h"
#include <gl/freeglut.h>

class Square :
    public Primitive2D
{
private:
    float width;
public:
    Square(float x, float y, float z, float width);
    void draw() override;
};

