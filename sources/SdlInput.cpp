#include "SdlInput.h"

SdlInput::SdlInput() {}
SdlInput::~SdlInput() {}

static void keyaction(EventKeep & ek, const SDL_Keycode key,
	const bool state)
{
	switch (key)
	{
		case SDLK_ESCAPE: ek.setEsc(state); break;
	}
}

static void mouseaction(EventKeep & ek, const unsigned int button,
	const bool state)
{
	switch (button)
	{
		case SDL_BUTTON_LEFT: ek.setLmb(state); break;
		case SDL_BUTTON_RIGHT: ek.setRmb(state); break;
	}
}

void SdlInput::refresh(EventKeep & ek)
{
	while (SDL_PollEvent(&event))
	{
		SDL_PumpEvents();

		switch (event.type)
		{
			case SDL_MOUSEMOTION:
				ek.setMouseY(event.motion.y);
				ek.setMouseX(event.motion.x);
				break;
			case SDL_MOUSEBUTTONDOWN:
				mouseaction(ek, event.button.button, ON);
				break;
			case SDL_MOUSEBUTTONUP:
				mouseaction(ek, event.button.button, OFF);
				break;
			case SDL_KEYDOWN:
				keyaction(ek, event.key.keysym.sym, ON);
				break;
			case SDL_KEYUP:
				keyaction(ek, event.key.keysym.sym, OFF);
				break;
			case SDL_QUIT:
				ek.setExit(ON);
				break;
		}
	}

}
