#include "Texture.h"

Texture::Texture(SDL_Texture * t, SDL_Rect r) : m_texture(t),
					m_rect(r) {}
Texture::~Texture() {}

SDL_Texture * Texture::getTexture() const
{
	return m_texture;
}

SDL_Rect * Texture::getRect() const
{
	return &m_rect;
}
