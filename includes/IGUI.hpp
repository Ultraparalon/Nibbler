#ifndef IGUI_HPP
#define IGUI_HPP

class IGUI
{
public:
	virtual ~IGUI() {};

	virtual int	draw(int, char **) = 0;	
};

#endif