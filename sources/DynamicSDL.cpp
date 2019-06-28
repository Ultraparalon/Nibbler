#include <DynamicSdl.h>

DynamicSdl::DynamicSdl()
{
}

DynamicSdl::~DynamicSdl() {}

void DynamicSdl::eventRefresh(EventKeep & ek)
{
	input.refresh(ek);
}

void DynamicSdl::drawObjects(std::list<Drawable const * const> & objects)
{
	gui.drawObjects(objects);
}

void DynamicSdl::render()
{
	gui.render();
}

void DynamicSdl::playSounds(std::list<eSound> & sounds)
{

}

void DynamicSdl::playMusic(eMusic)
{

}
