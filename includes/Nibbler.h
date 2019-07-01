#ifndef NIBBLER_H
#define NIBBLER_H

#include <vector>

enum gameStates {
	GAME,
	MENU,
	GAMEOVER
};

enum snakeDirections {
	UP, 
	DOWN,
	RIGHT,
	LEFT
};

typedef struct	cube {
	int x;
	int y;
	float size;
}				Cube;

class Nibbler
{
	// int						width;
	// int 					height;
	// std::vector<Cube>		*Nibbler;
	// enum snakeDirections	direction;
	// enum gameStates			state;


public:
	// Nibbler(int, int);
	Nibbler();
	~Nibbler();

	// void run();
	// void switchState(enum gameStates);
	// void changeDirection(enum snakeDirections);

};

#endif