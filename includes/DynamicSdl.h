#ifndef DYNAMICSDL_H
#define DYNAMICSDL_H

#include "IDynamic.h"

class DynamicSdl : public IDymanic
{
public:
	DynamicSdl();
	~DynamicSdl();

	void eventRefresh(EventKeep &);
	void drawObjects(std::list<Drawable const * const> &);
	void render();
	void playSounds(std::list<Sound> &);
	void playMusic(Music);
	
};

#endif