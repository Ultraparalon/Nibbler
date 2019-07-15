#include "Nibbler.h"

Nibbler::Nibbler() : m_height(10), m_width(10), direction(UP)
{
    buttons.push_back(Button(1, 1, 32, 128, NEW_GAME));
    buttons.push_back(Button(3, 1, 32, 128, EXIT));

    food = Drawable(1, 1, FOOD);
	// food.setTexture(FOOD);
	// generateFood();
}

Nibbler::~Nibbler() {}

void Nibbler::setPoleSize(const int y, const int x)
{
    m_height = y;
    m_width = x;
}

std::list<Drawable> const & Nibbler::getDrawable()
{
    return gameObjects;
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

void Nibbler::game(const EventKeep & ek) 
{
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

    // static time_t second = time(NULL);
    // if (second != time(NULL))
    // {
    //     // std::cout << clock() << std::endl;
    //     second = time(NULL);
    //     move();
    // }
    static clock_t tick = clock();
    if (clock() > tick + CLOCKS_PER_SEC / 200)
    {
        // std::cout << CLOCKS_PER_SEC << std::endl;
        tick = clock();
        move();
    }
    // std::cout << CLOCKS_PER_SEC << std::endl;
    // std::cout << clock() << std::endl;

    //things to draw
    gameObjects.clear();

    for (std::list<Drawable>::iterator it = snake.begin();
        it != snake.end(); it++)
    {
        gameObjects.push_front(*it);
    }

    gameObjects.push_front(food);

    for (int x = 0; x <= m_height + 1; x++)
    {
        gameObjects.push_front(Drawable(x, 0, OBSTACLE));
        gameObjects.push_front(Drawable(x, m_width + 1, OBSTACLE));
    }
    for (int x = 1; x <= m_width; x++)
    {
        gameObjects.push_front(Drawable(0, x, OBSTACLE));
        gameObjects.push_front(Drawable(m_height + 1, x, OBSTACLE));
    }
}

bool Nibbler::tryToMove(Drawable & head)
{
    if (snake.back().getPosY() <= 0 || snake.back().getPosY() > m_height ||
        snake.back().getPosX() <= 0 || snake.back().getPosX() > m_width)
    {
        return false;
    }

    switch (direction)
    {
        case UP:
            head.setPos(snake.back().getPosY() - 1, snake.back().getPosX());
            break;
        case DOWN:
            head.setPos(snake.back().getPosY() + 1, snake.back().getPosX());
            break;
        case LEFT:
            head.setPos(snake.back().getPosY(), snake.back().getPosX() - 1);
            break;
        case RIGHT:
            head.setPos(snake.back().getPosY(), snake.back().getPosX() + 1);
            break;
    }

	snake.back().setTexture(SNAKE_BODY);
    if (head != food)
    {
        snake.pop_front();
    }

    for (auto i : snake)
    {
        if (i == head)
            return false;
    }

    return true;
}

void Nibbler::move()
{
    Drawable head = snake.back();

	if (!tryToMove(head))
	{
	    state = MENU;
	    return;
	}

	snake.push_back(head);
	// snake.push_back(Drawable(head.getPosY(), head.getPosX(), head.getTexture()));
	if (head == food)
	{
	    generateFood();
	}
}

void Nibbler::generateFood()
{
    bool unset = true;

    /* checking whether food wasn't generated on the snake's body */
    while (unset)
    {
        food.setPos(rand() % m_height + 1, rand() % m_width + 1);
        unset = false;
        for (auto i : snake)
        {
            if (i == food)
            {
                unset = true;
                break;
            }
        }
    }
}

void Nibbler::menu(const EventKeep & ek)
{
    if (ek.getLmb())
    {
        if (buttons[0].clicked(ek.getMouseY(), ek.getMouseX()))
        {
            direction = UP;

            snake.clear();
            snake.push_front(Drawable((m_height >> 1), (m_width >> 1), SNAKE_HEAD));
            snake.push_front(Drawable(snake.front().getPosY() + 1,
                snake.front().getPosX(), SNAKE_BODY));
            snake.push_front(Drawable(snake.front().getPosY() + 1,
                snake.front().getPosX(), SNAKE_BODY));
            
            generateFood();
            state = GAME;
        }
        if (buttons[1].clicked(ek.getMouseY(), ek.getMouseX()))
        {
            exit(0);
        }
    }

    //things to draw
    gameObjects.clear();
    for (auto it : buttons)
    {
        gameObjects.push_back(it);
    }

}

void Nibbler::gameOver(const EventKeep &)
{

}
