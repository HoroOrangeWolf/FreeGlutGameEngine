#pragma once
#include "Primitive2D.h"
#include <gl/freeglut.h>
#include "Transformable.h"

class RandomLetter :
    public Primitive2D,
    public Transformable
{
public:
    RandomLetter(float x, float y);
    void draw() override;
    void moveBy(float x, float y, float z) override;
    void rotate(int x, int y, int z, float degree) override;
    void scale(float k) override;
};

