#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>

#include "IDynamic.h"
#include "Nibbler.h"
#include "EventKeep.h"

class Engine
{

public:
	Engine();
	~Engine();

	void	run();

private:
	Nibbler m_nibbler;
	EventKeep m_events;
	IDynamic * m_dynamic;
	
};

#endif