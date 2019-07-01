#ifndef DYNAMICSFML_H
#define DYNAMICSFML_H

#include "../../includes/IDynamic.h"

#include <SFML/Window.hpp>

// #include "SfmlGui.h"
// #include "SfmlInput.h"

class DynamicSfml : public IDynamic
{
public:
	DynamicSfml();
	~DynamicSfml();

	void drawObject(const int, const int, const unsigned int);
	void render();
	void playSound(const int);
	void playMusic(const int);

	void inputRefresh();
	int getMouseY() const;
	int getMouseX() const;
	unsigned int getKeys() const;

private:
	int m_mousey;
	int m_mousex;
	unsigned int m_keys;

	sf::Window m_window;
	
};

#endif