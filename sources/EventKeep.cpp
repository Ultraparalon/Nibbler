#include "EventKeep.h"

EventKeep::EventKeep() : m_exit(false), m_esc(false),
  m_up(false), m_down(false), m_left(false), m_right(false),
  m_lmb(false), m_rmb(false),
  m_mouseY(0), m_mouseX(0), m_dynamicLib(SFML) {}
EventKeep::~EventKeep() {}

// void EventKeep::setExit(const bool val)
// {
// 	exit = val;
// }

// void EventKeep::setEsc(const bool val)
// {
// 	esc = val;
// }

// void EventKeep::setLmb(const bool val)
// {
// 	lmb = val;
// }

// void EventKeep::setRmb(const bool val)
// {
// 	rmb = val;
// }

// void EventKeep::setMouseY(const int val)
// {
// 	mouseY = val;
// }

// void EventKeep::setMouseX(const int val)
// {
// 	mouseX = val;
// }

bool EventKeep::getExit() const
{
	return m_exit;
}

bool EventKeep::getEsc() const
{
	return m_esc;
}

bool EventKeep::getUp() const
{
	return m_up;
}

bool EventKeep::getDown() const
{
	return m_down;
}

bool EventKeep::getLeft() const
{
	return m_left;
}

bool EventKeep::getRight() const
{
	return m_right;
}

bool EventKeep::getLmb() const
{
	return m_lmb;
}

bool EventKeep::getRmb() const
{
	return m_rmb;
}

int EventKeep::getMouseY() const
{
	return m_mouseY;
}

int EventKeep::getMouseX() const
{
	return m_mouseX;
}

eDynamicLib EventKeep::getCurrentLib() const
{
	return m_dynamicLib;
}

void EventKeep::eventRefresh(const int y, const int x,
	const unsigned int keys)
{
	m_mouseY = y;
	m_mouseX = x;
	m_lmb = (keys & 1);
	m_rmb = (keys & (1 << 1));

	m_exit = (keys & (1 << 30));
	m_esc = (keys & (1 << 5));

	m_up = keys & (1 << 6);
	m_down = keys & (1 << 7);
	m_left = keys & (1 << 8);
	m_right = keys & (1 << 9);

	if (keys & (1 << 29))
	{
		m_dynamicLib = SDL;
	}
	else if (keys & (1 << 28))
	{
		m_dynamicLib = SFML;
	}
	else if (keys & (1 << 27))
	{
		m_dynamicLib = OPENGL;
	}
}
