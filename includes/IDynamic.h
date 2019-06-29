#ifndef IDYNAMIC_H
#define IDYNAMIC_H

#include <list>

class IDynamic
{
public:
	virtual ~IDynamic() {};

	virtual void drawObject(const int, const int, const unsigned int) = 0;
	virtual void render() = 0;

	virtual void playSound(const int) = 0;
	virtual void playMusic(const int) = 0;

	virtual void inputRefresh() = 0;
	virtual int getMouseY() const = 0;
	virtual int getMouseX() const = 0;
	virtual unsigned int getKeys() const = 0;
	
};

#endif