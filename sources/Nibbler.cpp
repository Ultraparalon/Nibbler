#include "Nibbler.h"

Nibbler::Nibbler() : m_width(10), m_height(10), direction(UP)
{
	snake.push_front(Drawable((m_height >> 1), (m_width >> 1), SNAKE_HEAD));
	snake.push_front(Drawable(snake.front().getPosY() + 1,
		snake.front().getPosX(), SNAKE_BODY));
	snake.push_front(Drawable(snake.front().getPosY() + 1,
		snake.front().getPosX(), SNAKE_BODY));
}

Nibbler::~Nibbler() {}

void Nibbler::run(const EventKeep & ek)
{
	// input managment

	// need improovement
	if (ek.getUp() && direction != DOWN)
	{
		direction = UP;
	}
	else if (ek.getDown() && direction != UP)
	{
		direction = DOWN;
	}
	else if (ek.getRight() && direction != LEFT)
	{
		direction = RIGHT;
	}
	else if (ek.getLeft() && direction != RIGHT)
	{
		direction = LEFT;
	}

	static time_t second = time(NULL);
	if (second != time(NULL))
	{
		second = time(NULL);
		move();
	}
}

std::list<Drawable> const & Nibbler::getDrawable()
{
	gameObjects.clear();

	for (std::list<Drawable>::iterator it = snake.begin();
		it != snake.end(); it++)
	{
		gameObjects.push_front(*it);
	}

	return gameObjects;
}

void Nibbler::move()
{
	bool move;

	switch (direction)
	{
		case UP: move = (snake.back().getPosY() == 0) ? false : true; break;
		case DOWN: move = (snake.back().getPosY() == m_height) ? false : true; break;
		case LEFT: move = (snake.back().getPosX() == 0) ? false : true; break;
		case RIGHT: move = (snake.back().getPosX() == m_width) ? false : true; break;
	}

	if (move)
	{
		std::list<Drawable>::iterator next = snake.begin();
		next++;
		for (std::list<Drawable>::iterator it = snake.begin();
			next != snake.end(); it++, next++)
		{
			(*it).setPos((*next).getPosY(), (*next).getPosX());
		}

		switch (direction)
		{
			case UP: snake.back().moveY(-1); break;
			case DOWN: snake.back().moveY(1); break;
			case LEFT: snake.back().moveX(-1); break;
			case RIGHT: snake.back().moveX(1); break;
		}
	}
}
