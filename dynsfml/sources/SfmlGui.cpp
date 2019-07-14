#include "SfmlGui.h"

static sf::Texture loadtxr(std::string path)
{
	sf::Texture texture;

	if (!texture.loadFromFile(path))
	{
		std::cout << "could't load texture from: " << path << std::endl;
		exit(1);
	}

	return texture;
}

SfmlGui::SfmlGui(sf::RenderWindow & win) : m_window(win)
{
	// m_window.create(sf::VideoMode(800, 600), "sfml");


	m_textures.push_back(loadtxr("dynsfml/resources/textures/snake_head.png"));
	m_textures.push_back(loadtxr("dynsfml/resources/textures/snake_body.png"));
	m_textures.push_back(loadtxr("dynsfml/resources/textures/food.png"));
	m_textures.push_back(loadtxr("dynsfml/resources/textures/bonus.png"));
}

SfmlGui::~SfmlGui()
{
}

void SfmlGui::drawBackground(const unsigned int type)
{
	m_window.clear(sf::Color::Black);
}

void SfmlGui::drawObject(const int y, const int x, const unsigned int type)
{
	sf::Sprite sprite;
	sprite.setTexture(m_textures[type]);
	sprite.setPosition(sf::Vector2f(x, y));
	m_window.draw(sprite);
}

void SfmlGui::render()
{
	m_window.display();
}
