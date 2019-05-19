#include "Engine.hpp"

Engine::Engine() {}
Engine::Engine(int const y, int const x)
{
	map = new char*[y];
	for (int i = 0; i < y; i++)
	{
		map[i] = new char[x];
	}
	gui = nullptr;
}
Engine::~Engine() {}

void	Engine::run()
{
	std::cout << "Engine is succefuly runing" << std::endl;
}