#ifndef IDYNAMIC_H
#define IDYNAMIC_H

#include <list>

#include "EventKeep.h"
#include "Drawable.h"

enum eSound
{
	SOUND1,
	SOUND2
};

enum eMusic
{
	MUSIC1,
	MUSIC2
};

class IDynamic
{
public:
	virtual ~IDynamic() {};

	virtual void eventRefresh(EventKeep &) = 0;
	virtual void drawObjects(std::list<Drawable const * const> &) = 0;
	virtual void render() = 0;
	virtual void playSounds(std::list<eSound> &) = 0;
	virtual void playMusic(eMusic) = 0;
	
};

#endif