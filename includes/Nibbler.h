#ifndef NIBBLER_H
#define NIBBLER_H

#include <vector>
#include <list>
#include <ctime>

#include "EventKeep.h"
#include "Drawable.h"

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
public:
	// Nibbler(int, int);
	Nibbler();
	~Nibbler();

	void run(const EventKeep &);
	std::list<Drawable> const & getDrawable();
	// void switchState(enum gameStates);
	// void changeDirection(enum snakeDirections);

private:
	int m_width;
	int m_height;
	enum snakeDirections	direction;

	// std::list<> food;
	std::list<Drawable> snake;
	std::list<Drawable> gameObjects;
	// std::vector<Cube>		*Nibbler;
	// enum gameStates			state;

	void move();


};

#endif