#include "SfmlInput.h"

SfmlInput::SfmlInput(sf::RenderWindow & win) : m_window(win),
		m_mousey(0), m_mousex(0), m_keys(0)
{
}
SfmlInput::~SfmlInput() {}

int SfmlInput::getMouseY() const
{
	return m_mousey;
}

int SfmlInput::getMouseX() const
{
	return m_mousex;
}

unsigned int SfmlInput::getKeys() const
{
	return m_keys;
}

static unsigned int keyaction(const sf::Keyboard::Key key)
{
	switch (key)
	{
		case sf::Keyboard::Escape: return (1 << 5);
		case sf::Keyboard::Num1: return (1 << 29);
		case sf::Keyboard::Num2: return (1 << 28);
		case sf::Keyboard::Num3: return (1 << 27);
		case sf::Keyboard::W: return (1 << 6);
		case sf::Keyboard::S: return (1 << 7);
		case sf::Keyboard::A: return (1 << 8);
		case sf::Keyboard::D: return (1 << 9);
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

void SfmlInput::refresh()
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
			case sf::Event::KeyReleased:
				m_keys &= ~keyaction(event.key.code);
				break;
			case sf::Event::KeyPressed:
				m_keys |= keyaction(event.key.code);
				break;
			case sf::Event::Closed:
				m_keys |= (1 << 30);
				break;
			default: ;
		}
	}
}
