#ifndef EVENTKEEP_H
#define EVENTKEEP_H

enum eDynamicLib
{
	SDL,
	SFML,
	OPENGL	
};

class EventKeep
{
public:
	EventKeep();
	~EventKeep();

	// void setExit(const bool);
	// void setEsc(const bool);
	// void setUp(const bool);

	// void setLmb(const bool);
	// void setRmb(const bool);
	// void setMouseY(const int);
	// void setMouseX(const int);

	bool getExit() const;
	bool getEsc() const;

	bool getUp() const;
	bool getDown() const;
	bool getLeft() const;
	bool getRight() const;

	bool getLmb() const;
	bool getRmb() const;
	int getMouseY() const;
	int getMouseX() const;

	eDynamicLib getCurrentLib() const;

	void eventRefresh(const int, const int, const unsigned int);

private:
	bool m_exit;
	bool m_esc;

	bool m_up;
	bool m_down;
	bool m_left;
	bool m_right;

	bool m_lmb;
	bool m_rmb;
	int m_mouseY;
	int m_mouseX;

	eDynamicLib m_dynamicLib;

};

#endif