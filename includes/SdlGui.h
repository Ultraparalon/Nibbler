#ifndef SDLGUI_H
#define SDLGUI_H

#include <SDL.h>
#include <iostream>
#include <list>

#include "Drawable.h"

class SdlGui
{
public:
	SdlGui();
	~SdlGui();

	void drawObjects(std::list<Drawable const * const> &);
	void render();

private:
	int request;
	SDL_DisplayMode displayMode;
	SDL_Window * win;
	SDL_Renderer * ren;
	
};

#endif