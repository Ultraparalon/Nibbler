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
	enum gameStates         state;

	// std::list<> food;
	std::list<Drawable> snake;
	std::list<Drawable> gameObjects;
	Drawable            food;
	void generateFood();
	// std::vector<Cube>		*Nibbler;
	// enum gameStates			state;

	void move();

	/* functions to handle game states */
    void game(const EventKeep &);
    void menu(const EventKeep &);
    void gameOver(const EventKeep &);


    struct GameOverException : public std::exception {};
};

#endif