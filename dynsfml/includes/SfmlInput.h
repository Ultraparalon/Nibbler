#ifndef SFMLINPUT_H
#define SFMLINPUT_H

#include <SFML/Graphics.hpp>
#include <iostream>

class SfmlInput
{
public:
	SfmlInput(sf::RenderWindow &);
	~SfmlInput();

	int getMouseY() const;
	int getMouseX() const;
	unsigned int getKeys() const;

	void refresh();

private:
	sf::RenderWindow & m_window;

	int m_mousey;
	int m_mousex;
	unsigned int m_keys;


	
};

#endif