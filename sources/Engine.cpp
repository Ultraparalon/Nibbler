#include "Engine.h"

Engine::Engine()
{
	m_dynamic = new DynamicSdl();
}
Engine::~Engine()
{
	delete m_dynamic;
}

void	Engine::run()
{
	std::cout << "Engine is succefuly runing" << std::endl;
	// while (!m_events.getExit())
	// {
	// 	m_dynamic->eventRefresh(m_events);
	// }
}
