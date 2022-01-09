#pragma once
#include "Observer.h"

#include <glm/fwd.hpp>
#include <glm/glm.hpp>

class Player :
    public Observer
{
private:
    float x=0, y=0, z=0;
    int mouseX = -1, mouseY = -1;
public:
    void onKeyboardClick(unsigned char key);
    void onMouseMove(int x, int y);
    void setStartCords(float x, float y, float z);
};

