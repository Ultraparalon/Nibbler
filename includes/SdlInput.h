#ifndef SDLINPUT_H
#define SDLINPUT_H

#include <SDL.h>

#include "EventKeep.h"

enum eState
{
	OFF,
	ON	
};

class SdlInput
{
public:
	SdlInput();
	~SdlInput();

	void refresh(EventKeep &);

private:
	SDL_Event event;
	
};

#endif