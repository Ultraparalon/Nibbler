#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <string>

enum eTexture
{
	SNAKE_HEAD,
	SNAKE_BODY,
	FOOD,
	BONUS,
	OBSTACLE,
	NEW_GAME,
	EXIT
};

class Drawable
{
public:
	Drawable();
	Drawable(const int, const int, const eTexture);
	Drawable(const int, const int,
		const eTexture, const std::string);
	Drawable(const int, const int, const int, const int,
		const eTexture, const std::string);
	~Drawable();

	int getPosY() const;
	int getPosX() const;
	int getHeight() const;
	int getWidth() const;
	eTexture getTexture() const;
	std::string getName() const;

	void setPosY(const int);
	void setPosX(const int);
	void setPos(const int y, const int x);
	void setName(const std::string);
	void setTexture(const eTexture);

	void moveY(const int);
	void moveX(const int);

	bool operator==(Drawable const &) const;
	bool operator!=(Drawable const &) const;

private:
	int m_posy;
	int m_posx;
	int m_height;
	int m_width;

	eTexture m_texture;
	std::string m_name;
	
};

#endif