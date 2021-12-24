#pragma once
#include "Primitive2D.h"
#include <gl/freeglut.h>

class RandomLetter :
    public Primitive2D
{
public:
    RandomLetter(float x, float y);
    void draw() override;
};

