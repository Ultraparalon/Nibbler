#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <dlfcn.h>

#include "IDynamic.h"
#include "Nibbler.h"
#include "EventKeep.h"

class Engine
{

public:
	Engine();
	~Engine();

	void run();

	void changeLib(const eDynamicLib);

private:
	Nibbler m_nibbler;
	EventKeep m_events;

	eDynamicLib currentLibrary;

	void * m_handle;
	IDynamic * m_dynamic;
	
};

#endif