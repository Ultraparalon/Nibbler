#ifndef SDLGUI_H
#define SDLGUI_H

#include <SDL.h>
#include <iostream>
#include <list>


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
	
};

#endif