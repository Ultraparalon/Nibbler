#ifndef SDLGUI_H
#define SDLGUI_H

#include <iostream>
#include <list>

#include <SDL.h>

#include "TextureFactory.h"

class SdlGui
{
public:
	SdlGui();
	~SdlGui();

	void drawObject(const int, const int, const unsigned int);
	void render();

private:
	int request;
	SDL_DisplayMode displayMode;
	SDL_Window * win;
	SDL_Renderer * ren;

	TextureFactory tf;
	
};

#endif