#include <iostream>
#include "Engine.h"

void	wizard(int y, int x)
{
	std::cout << y << '\n' << x << std::endl;
	if (y < 10 || y > 100 || x < 10 || x > 100)
	{
		std::cout << "map is too small" << std::endl;
		exit(0);
	}
	Engine engine;
	engine.run();
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		wizard(std::stoi(argv[1]), std::stoi(argv[2]));
		std::cout << "Hello!" << std::endl;
	}

	return 0;
}
