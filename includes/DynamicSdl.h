#ifndef DYNAMICSDL_H
#define DYNAMICSDL_H

#include "IDynamic.h"
#include "SdlGui.h"
#include "SdlInput.h"

class DynamicSdl : public IDynamic
{
public:
	DynamicSdl();
	~DynamicSdl();

	void drawObject(const int, const int, const unsigned int);
	void render();
	void playSound(const int);
	void playMusic(const int);

	void inputRefresh();
	int getMouseY() const;
	int getMouseX() const;
	unsigned int getKeys() const;

private:
	SdlGui gui;
	SdlInput input;
	
};

#endif