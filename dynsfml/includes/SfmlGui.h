#ifndef SFMLGUI_H
#define SFMLGUI_H

#include <vector>
#include <iostream>

#include <SFML/Graphics.hpp>

class SfmlGui
{
public:
	SfmlGui(sf::RenderWindow &);
	~SfmlGui();

	void drawBackground(const unsigned int);
	void drawObject(const int, const int, const unsigned int);
	void render();

private:
	// SfmlGui() {}
	sf::RenderWindow & m_window;

	std::vector<sf::Texture> m_textures;
	
};

#endif