#ifndef TEXTUREFACTORY_H
#define TEXTUREFACTORY_H

#include <vector>
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Texture.h"

class TextureFactory
{
public:
	TextureFactory();
	~TextureFactory();
	
	void initialize(SDL_Renderer *);

	Texture * createTexture(const int, const int, const unsigned int);

private:

	SDL_Renderer * m_ren;

	std::vector<SDL_Texture *> m_textures;

};

#endif