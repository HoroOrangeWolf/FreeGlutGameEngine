#pragma once
#include "Observer.h"
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

