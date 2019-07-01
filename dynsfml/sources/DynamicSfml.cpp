#include "DynamicSfml.h"

DynamicSfml::DynamicSfml() : m_mousey(0), m_mousex(0), m_keys(0)
{
	m_window.create(sf::VideoMode(800, 600), "sfml");
}
DynamicSfml::~DynamicSfml()
{
	m_window.close();
}

void DynamicSfml::drawObject(const int y, const int x,
	const unsigned int type)
{

}

void DynamicSfml::render()
{

}

void DynamicSfml::playSound(const int sound)
{

}

void DynamicSfml::playMusic(const int music)
{

}

static unsigned int keyaction(const sf::Keyboard::Key key)
{
	switch (key)
	{
		case sf::Keyboard::Escape: return (1 << 5);
		case sf::Keyboard::Num1: return (1 << 29);
		case sf::Keyboard::Num2: return (1 << 28);
		default: return 0;
	}
}

static unsigned int mouseaction(const sf::Mouse::Button button)
{
	switch (button)
	{
		case sf::Mouse::Left: return 1;
		case sf::Mouse::Right: return (1 << 1);
		default: return 0;
	}
}

void DynamicSfml::inputRefresh()
{
	sf::Event event;

	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::MouseMoved:
				m_mousey = event.mouseMove.y;
				m_mousex = event.mouseMove.x;
				break;
			case sf::Event::MouseButtonPressed:
				m_keys |= mouseaction(event.mouseButton.button);
				break;
			case sf::Event::MouseButtonReleased:
				m_keys &= ~mouseaction(event.mouseButton.button);
				break;
			case sf::Event::KeyPressed:
				m_keys |= keyaction(event.key.code);
				break;
			case sf::Event::KeyReleased:
				m_keys &= ~keyaction(event.key.code);
				break;
			case sf::Event::Closed:
				m_keys |= (1 << 30);
				break;
			default: ;
		}
	}

}

int DynamicSfml::getMouseY() const
{
	return m_mousey;
}

int DynamicSfml::getMouseX() const
{
	return m_mousex;
}

unsigned int DynamicSfml::getKeys() const
{
	return m_keys;
}

extern "C" IDynamic * create()
{
	return new DynamicSfml();
}
