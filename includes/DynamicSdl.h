#ifndef DYNAMICSDL_H
#define DYNAMICSDL_H

#include "IDynamic.h"
#include "SdlGui.h"
#include "SdlInput.h"

class DynamicSdl : public IDynamic
{
public:
	DynamicSdl();
	~DynamicSdl();

	void eventRefresh(EventKeep &);
	void drawObjects(std::list<Drawable const * const> &);
	void render();
	void playSounds(std::list<eSound> &);
	void playMusic(eMusic);

private:
	SdlGui gui;
	SdlInput input;
	
};

#endif