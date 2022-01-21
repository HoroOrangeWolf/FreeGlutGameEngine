#pragma once
#include "Primitive2D.h"
#include "Transformable.h"
#include <gl/freeglut.h>
#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define PI 3.14159265

#define angle PI/180.f

class Triangle :
    public Primitive2D,
    public Transformable
{
private:
    float a = 0, height = 0;
public:
    Triangle(float x, float y, float z, float a, float height);
    void draw() override;
    void moveBy(float x, float y, float z) override;
    void rotate(int x, int y, int z, float degree) override;
    void scale(float k) override;
};

