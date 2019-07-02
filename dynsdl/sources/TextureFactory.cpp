#include "TextureFactory.h"

TextureFactory::TextureFactory() {}
TextureFactory::~TextureFactory() {}

void TextureFactory::initialize(SDL_Renderer * ren)
{
	m_ren = ren;
}

Texture * createTexture(const int y, const int x,
	const unsigned int type)
{
	
}
