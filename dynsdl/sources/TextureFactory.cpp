#include "TextureFactory.h"

TextureFactory::TextureFactory() {}
TextureFactory::~TextureFactory()
{
	for (std::vector<SDL_Texture *>::iterator it = m_textures.begin();
			it != m_textures.end(); it++)
	{
		SDL_DestroyTexture(*it);
	}
}

static SDL_Texture * loadtxr(SDL_Renderer * ren, std::string path)
{
	SDL_Texture * ret = IMG_LoadTexture(ren, path.c_str());
	if (ret == nullptr)
	{
		std::cout << "Couldn't load texture from: " <<
			path << std::endl;
		exit(1);
	}
	return ret;
}

void TextureFactory::initialize(SDL_Renderer * ren)
{
	m_ren = ren;

	m_textures.push_back(loadtxr(ren, "dynsdl/resources/textures/snake_head.png"));
	m_textures.push_back(loadtxr(ren, "dynsdl/resources/textures/snake_body.png"));
	m_textures.push_back(loadtxr(ren, "dynsdl/resources/textures/food.png"));
	m_textures.push_back(loadtxr(ren, "dynsdl/resources/textures/bonus.png"));
	m_textures.push_back(loadtxr(ren, "dynsdl/resources/textures/obstacle.png"));
	m_textures.push_back(loadtxr(ren, "dynsdl/resources/textures/new_game.png"));
	m_textures.push_back(loadtxr(ren, "dynsdl/resources/textures/exit.png"));
}

Texture * TextureFactory::createTexture(const int y, const int x,
	const unsigned int type)
{
	SDL_Texture * texture = m_textures[type];
	SDL_Rect rect;

	SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);

	rect.y = y; // + (rect.h >> 1);
	rect.x = x; // + (rect.w >> 1);

	return new Texture(texture, rect);
}
