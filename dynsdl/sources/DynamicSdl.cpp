#include <DynamicSdl.h>

DynamicSdl::DynamicSdl()
{
}

DynamicSdl::~DynamicSdl() {}

void DynamicSdl::drawBackground(const unsigned int)
{
	gui.drawBackground(0);
}

void DynamicSdl::drawObject(const int y, const int x, const unsigned int type)
{
	gui.drawObject(y, x, type);
}

void DynamicSdl::render()
{
	gui.render();
}

void DynamicSdl::playSound(const int sound)
{

}

void DynamicSdl::playMusic(const int music)
{

}


void DynamicSdl::inputRefresh()
{
	input.refresh();
}

int DynamicSdl::getMouseY() const
{
	return input.getMouseY();
}

int DynamicSdl::getMouseX() const
{
	return input.getMouseX();
}

unsigned int DynamicSdl::getKeys() const
{
	return input.getKeys();
}

extern "C" IDynamic * create()
{
	return new DynamicSdl();
}
