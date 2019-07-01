#include "SdlInput.h"

SdlInput::SdlInput() : mousey(0), mousex(0), keys(0) {}
SdlInput::~SdlInput() {}

int SdlInput::getMouseY() const
{
	return mousey;
}

int SdlInput::getMouseX() const
{
	return mousex;
}

unsigned int SdlInput::getKeys() const
{
	return keys;
}

static unsigned int keyaction(const SDL_Keycode key)
{
	switch (key)
	{
		case SDLK_ESCAPE: return (1 << 5);
		case SDLK_1: return (1 << 29);
		case SDLK_2: return (1 << 28);
		default: return 0;
	}
}

static unsigned int mouseaction(const unsigned int button)
{
	switch (button)
	{
		case SDL_BUTTON_LEFT: return 1;
		case SDL_BUTTON_RIGHT: return (1 << 1);
		default: return 0;
	}
}

void SdlInput::refresh()
{
	while (SDL_PollEvent(&event))
	{
		SDL_PumpEvents();

		switch (event.type)
		{
			case SDL_MOUSEMOTION:
				mousey = (event.motion.y);
				mousex = (event.motion.x);
				break;
			case SDL_MOUSEBUTTONDOWN:
				keys |= mouseaction(event.button.button);
				break;
			case SDL_MOUSEBUTTONUP:
				keys &= ~mouseaction(event.button.button);
				break;
			case SDL_KEYDOWN:
				keys |= keyaction(event.key.keysym.sym);
				break;
			case SDL_KEYUP:
				keys &= ~keyaction(event.key.keysym.sym);
				break;
			case SDL_QUIT:
				keys |= (1 << 30);
				break;
		}
	}

}
