#ifndef NIBBLER_H
#define NIBBLER_H

#include <vector>
#include <list>
#include <ctime>
#include <iostream>

#include "EventKeep.h"
#include "Drawable.h"
#include "Button.h"

enum gameStates {
	MENU,
	GAME,
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

	void setPoleSize(const int, const int);

	void run(const EventKeep &);
	std::list<Drawable> const & getDrawable();
	// void switchState(enum gameStates);
	// void changeDirection(enum snakeDirections);

private:
	int m_height;
	int m_width;
	enum snakeDirections	direction;
	enum gameStates         state;

	// std::list<> food;
	std::list<Drawable> snake;
	Drawable            food;

	std::vector<Button> buttons;

	std::list<Drawable> gameObjects;

	/* functions to handle game states */
    void game(const EventKeep &);
    void menu(const EventKeep &);
    void gameOver(const EventKeep &);

    //game funcs
    bool tryToMove(Drawable &);
	void move();
	void generateFood();


    struct GameOverException : public std::exception {};
};

#endif