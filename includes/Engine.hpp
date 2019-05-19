#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <iostream>
#include <memory>
#include "IGUI.hpp"

class Engine
{
	char **	map;
	IGUI * gui;

public:
	Engine();
	Engine(int, int);
	~Engine();

	void	run();
	
};

#endif