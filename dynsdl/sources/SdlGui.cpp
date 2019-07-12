#include "SdlGui.h"

static void	error(std::string err)
{
	std::cout << err << SDL_GetError() << std::endl;
	exit(1);
}

SdlGui::SdlGui()
{
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		exit(1);
	}
	request = SDL_GetDesktopDisplayMode(0, &displayMode);
	
	// fullscreen window
	// win = SDL_CreateWindow("Test", 0, 0, displayMode.w, displayMode.h, SDL_WINDOW_SHOWN);
	
	win = SDL_CreateWindow("Test", 0, 0, 1024, 768, SDL_WINDOW_SHOWN);
	if (win == nullptr)
	{
		error("SDL_CreateWindow Error: ");
	}

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr)
	{
		error("SDL_CreateRenderer Error: ");
	}

	// SDL_SetWindowFullscreen(win, SDL_WINDOW_FULLSCREEN); //fullscreen mode

	tf.initialize(ren); //init texture factory
}

SdlGui::~SdlGui()
{
	SDL_DestroyRenderer(ren); // destroy renderer & window
	SDL_DestroyWindow(win);
}

void SdlGui::drawBackground(const unsigned int)
{
	SDL_RenderClear(ren);
}

void SdlGui::drawObject(const int y, const int x, const unsigned int type)
{
	Texture * texture = tf.createTexture(y, x, type);

	if (texture != nullptr)
	{
		SDL_RenderCopy(ren, texture->getTexture(),
			NULL, texture->getRect());

		delete texture;
	}
}

void SdlGui::render()
{
	// SDL_RenderClear(ren);
	SDL_RenderPresent(ren);

}
