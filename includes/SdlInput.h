#ifndef SDLINPUT_H
#define SDLINPUT_H

#include <SDL.h>

class SdlInput
{
public:
	SdlInput();
	~SdlInput();

	int getMouseY() const;
	int getMouseX() const;
	unsigned int getKeys() const;

	void refresh();

private:
	SDL_Event event;

	int mousey;
	int mousex;
	unsigned int keys;
	
};

#endif