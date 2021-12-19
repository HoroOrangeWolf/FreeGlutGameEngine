#pragma once
#include "Primitive2D.h"
#include <gl/freeglut.h>

class Triangle :
    public Primitive2D
{
private:
    float a = 0, height = 0;
public:
    Triangle(float x, float y, float z, float a, float height);
    void draw() override;
};

