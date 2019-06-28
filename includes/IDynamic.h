#ifndef IDYNAMIC_H
#define IDYNAMIC_H

#include "EventKeep.h"

class IDynamic
{
public:
	virtual ~IDynamic();

	virtual void eventRefresh(EventKeep &) = 0;
	virtual void drawObjects(std::list<Drawable const * const> &) = 0;
	virtual void render() = 0;
	virtual void playSounds(std::list<Sound> &) = 0;
	virtual void playMusic(Music) = 0;
	
};

#endif