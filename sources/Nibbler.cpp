#include "Nibbler.h"

Nibbler::Nibbler() : m_width(10), m_height(10), direction(UP)
{
	snake.push_front(Drawable((m_height >> 1), (m_width >> 1), SNAKE_HEAD));
	snake.push_front(Drawable(snake.front().getPosY() + 1,
		snake.front().getPosX(), SNAKE_BODY));
	snake.push_front(Drawable(snake.front().getPosY() + 1,
		snake.front().getPosX(), SNAKE_BODY));

	food.setTexture(FOOD);
	generateFood();
}

Nibbler::~Nibbler() {}

void Nibbler::game(const EventKeep & ek) {
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

void Nibbler::run(const EventKeep & ek)
{
	switch (state) {
        case GAME:
            game(ek);
            break;
        case MENU:
            menu(ek);
            break;
        case GAMEOVER:
            gameOver(ek);
            break;
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

bool Nibbler::tryToMove(Drawable &head) {
    bool move = false;

    switch (direction)
    {
        case UP:
            if (snake.back().getPosY() != 0) {
                move = true;
                head.setPos(snake.back().getPosY() + 1, snake.back().getPosX());
            }
            break;
        case DOWN:
            if (snake.back().getPosY() == m_height) {
                move = true;
                head.setPos(snake.back().getPosY() - 1, snake.back().getPosX());
            }
            break;
        case LEFT:
            if (snake.back().getPosX() == 0) {
                move = true;
                head.setPos(snake.back().getPosY(), snake.back().getPosX() - 1);
            }
            break;
        case RIGHT:
            if (snake.back().getPosX() == m_width) {
                move = true;
                head.setPos(snake.back().getPosY(), snake.back().getPosX() + 1);
            }
            break;
    }

    if (move) {
        if (head != food) {
            snake.pop_front();
        }

        for (auto i : snake) {
            if (i == head)
                return false;
        }
    }

    return move;
}

void Nibbler::move()
{
    Drawable head;

	if (!tryToMove(head)) {
	    state = GAMEOVER;
	    return;
	}

	snake.push_back(head);
	if (head == food) {
	    generateFood();
	}
}

void Nibbler::generateFood() {
    bool unset = true;

    /* checking whether food wasn't generated on the snake's body */
    while (unset) {
        food.setPos(rand() % m_height, rand() % m_width);
        unset = false;
        for (auto i : snake) {
            if (i == food) {
                unset = true;
                break;
            }
        }
    }
}