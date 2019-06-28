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
	while (!m_events.getExit())
	{
		if (m_events.getEsc())
		{
			break;
		}
		m_dynamic->eventRefresh(m_events);
		// m_dynamic->render();
	}
}
