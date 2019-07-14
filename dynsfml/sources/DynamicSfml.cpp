#include "DynamicSfml.h"

DynamicSfml::DynamicSfml() : gui(m_window), input(m_window)
{
	m_window.create(sf::VideoMode(800, 600), "sfml");
	m_window.setKeyRepeatEnabled(false);
}
DynamicSfml::~DynamicSfml()
{
	m_window.close();
}

void DynamicSfml::drawBackground(const unsigned int type)
{
	gui.drawBackground(type);
}

void DynamicSfml::drawObject(const int y, const int x,
	const unsigned int type)
{
	gui.drawObject(y, x, type);
}

void DynamicSfml::render()
{
	gui.render();
}

void DynamicSfml::playSound(const int sound)
{

}

void DynamicSfml::playMusic(const int music)
{

}

void DynamicSfml::inputRefresh()
{
	input.refresh();
}

int DynamicSfml::getMouseY() const
{
	return input.getMouseY();
}

int DynamicSfml::getMouseX() const
{
	return input.getMouseX();
}

unsigned int DynamicSfml::getKeys() const
{
	return input.getKeys();
}

extern "C" IDynamic * create()
{
	return new DynamicSfml();
}
