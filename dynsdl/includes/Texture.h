#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL.h>

class Texture
{
public:
	Texture(SDL_Texture *, SDL_Rect);
	~Texture();

	SDL_Texture * getTexture() const;
	SDL_Rect * getRect() const;

private:
	Texture() {};

	SDL_Texture * m_texture;
	SDL_Rect m_rect;
	
};

#endif