#ifndef IGUI_H
#define IGUI_H

class IGUI
{
public:
	virtual ~IGUI() {};

	virtual int	draw(int, char **) = 0;	
};

#endif