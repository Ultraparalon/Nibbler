#include "EventKeep.h"

EventKeep::EventKeep() : exit(false), esc(false), lmb(false), rmb(false),
							mouseY(0), mouseX(0), dynamicLib(SDL) {}
EventKeep::~EventKeep() {}

void EventKeep::setExit(const bool val)
{
	exit = val;
}

void EventKeep::setEsc(const bool val)
{
	esc = val;
}

void EventKeep::setLmb(const bool val)
{
	lmb = val;
}

void EventKeep::setRmb(const bool val)
{
	rmb = val;
}

void EventKeep::setMouseY(const int val)
{
	mouseY = val;
}

void EventKeep::setMouseX(const int val)
{
	mouseX = val;
}

bool EventKeep::getExit() const
{
	return exit;
}

bool EventKeep::getEsc() const
{
	return esc;
}

bool EventKeep::getLmb() const
{
	return lmb;
}

bool EventKeep::getRmb() const
{
	return rmb;
}

int EventKeep::getMouseY() const
{
	return mouseY;
}

int EventKeep::getMouseX() const
{
	return mouseX;
}

eDynamicLib EventKeep::getCurrentLib() const
{
	return dynamicLib;
}

void EventKeep::eventRefresh(const int y, const int x,
	const unsigned int keys)
{
	mouseY = y;
	mouseX = x;
	setExit(keys & (1 << 30));
	setEsc(keys & (1 << 5));
	setRmb(keys & (1 << 1));
	setLmb(keys & 1);

	if (keys & (1 << 29))
	{
		dynamicLib = SDL;
	}
	else if (keys & (1 << 28))
	{
		dynamicLib = SFML;
	}
	else if (keys & (1 << 27))
	{
		dynamicLib = OPENGL;
	}
}
