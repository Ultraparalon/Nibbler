#ifndef DYNAMICSFML_H
#define DYNAMICSFML_H

#include "../../includes/IDynamic.h"

// #include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "SfmlGui.h"
#include "SfmlInput.h"

class DynamicSfml : public IDynamic
{
public:
	DynamicSfml();
	~DynamicSfml();

	void drawBackground(const unsigned int);
	void drawObject(const int, const int, const unsigned int);
	void render();
	void playSound(const int);
	void playMusic(const int);

	void inputRefresh();
	int getMouseY() const;
	int getMouseX() const;
	unsigned int getKeys() const;

private:
	SfmlGui gui;
	SfmlInput input;

	sf::RenderWindow m_window;
	sf::Event event;
	
};

#endif