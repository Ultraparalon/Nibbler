#ifndef EVENTKEEP_H
#define EVENTKEEP_H

class EventKeep
{
public:
	EventKeep();
	~EventKeep();

	void setExit(const bool);
	void setEsc(const bool);
	void setLmb(const bool);
	void setRmb(const bool);
	void setMouseY(const int);
	void setMouseX(const int);

	bool getExit() const;
	bool getEsc() const;
	bool getLmb() const;
	bool getRmb() const;
	int getMouseY() const;
	int getMouseX() const;

private:
	bool exit;
	bool esc;

	bool lmb;
	bool rmb;
	int mouseY;
	int mouseX;

};

#endif