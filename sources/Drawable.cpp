#include "Drawable.h"

Drawable::Drawable() {}
Drawable::Drawable(const int y, const int x,
	const eTexture texture) : m_posy(y), m_posx(x), m_texture(texture) {}
Drawable::Drawable(const int y, const int x, const eTexture texture,
	const std::string name) : m_posy(y), m_posx(x), m_texture(texture),
	m_name(name) {}
Drawable::~Drawable() {}

int Drawable::getPosY() const
{
	return m_posy;
}

int Drawable::getPosX() const
{
	return m_posx;
}

eTexture Drawable::getTexture() const
{
	return m_texture;
}

std::string Drawable::getName() const
{
	return m_name;
}

void Drawable::setPosY(const int val)
{
	m_posy = val;
}

void Drawable::setPosX(const int val)
{
	m_posx = val;
}

void Drawable::setPos(const int y, const int x)
{
	m_posy = y;
	m_posx = x;
}

void Drawable::setName(const std::string str)
{
	m_name = str;
}

void Drawable::setTexture(const eTexture t) {
    m_texture = t;
}

void Drawable::moveY(const int val)
{
	m_posy += val;
}

void Drawable::moveX(const int val)
{
	m_posx += val;
}


bool Drawable::operator==(Drawable const &d) const {
    return (this->getPosX() == d.getPosX() && this->getPosY() == d.getPosY());
}

bool Drawable::operator!=(Drawable const &d) const {
    return !(*this == d);
}