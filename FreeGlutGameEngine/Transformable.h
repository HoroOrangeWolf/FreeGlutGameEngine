#pragma once
class Transformable
{
public:
	virtual void rotate(int x, int y, int z, float degree) = 0;
	virtual void moveBy(float x, float y, float z) = 0;
	virtual void scale(float k) = 0;;
};

