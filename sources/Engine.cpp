#include "Engine.h"

Engine::Engine()
{
	// m_dynamic = new DynamicSdl();
	// currentLibrary = SDL;

	// m_handle = dlopen("dynsdl/libdynsdl.dylib", RTLD_LAZY);
	// if (!m_handle)
	// {
	// 	std::cout << "Couldn't open dyn lib" << std::endl;
	// 	std::cout << dlerror() << std::endl;
	// 	exit(1);
	// }
	currentLibrary = SFML;

	m_handle = dlopen("dynsfml/libdynsfml.dylib", RTLD_LAZY);
	if (!m_handle)
	{
		std::cout << "Couldn't open dyn lib" << std::endl;
		std::cout << dlerror() << std::endl;
		exit(1);
	}

	IDynamic * (*create)();

	create = (IDynamic*(*)())(dlsym(m_handle, "create"));
	if (!create)
	{
		std::cout << "function not created" << std::endl;
		exit(1);
	}

	m_dynamic = create();
}
Engine::~Engine()
{
	delete m_dynamic;
	if (m_handle)
	{
		std::cout << "handle is open" << std::endl;
		dlclose(m_handle);
	}
}

void	Engine::run()
{
	std::cout << "Engine is succefuly runing" << std::endl;
	while (!m_events.getExit())
	{
		// events
		m_dynamic->inputRefresh();
		m_events.eventRefresh(m_dynamic->getMouseY(),
			m_dynamic->getMouseX(), m_dynamic->getKeys());

		if (m_events.getCurrentLib() != currentLibrary)
		{
			changeLib(m_events.getCurrentLib());
		}
		// temporary check
		if (m_events.getEsc())
		{
			break;
		}

		// game logic
		m_nibbler.run(m_events);
		
		// draw screen
		// m_dynamic->drawBackground(x);
		m_dynamic->drawBackground(0);
		std::list<Drawable> const & draw = m_nibbler.getDrawable();
		for (std::list<Drawable>::const_iterator it = draw.begin();
			it != draw.end(); it++)
		{
			m_dynamic->drawObject((*it).getPosY() * 32, (*it).getPosX() * 32,
				(*it).getTexture());	
		}
		// m_dynamic->drawObject(100, 100, 0);
		m_dynamic->render();
	}

}

static std::string getAddress(const eDynamicLib eLib)
{
	switch (eLib)
	{
		case SDL: return "dynsdl/libdynsdl.dylib";
		case SFML: return "dynsfml/libdynsfml.dylib";
		case OPENGL: return "dynopengl/libdynopengl.dylib";
		default: return "dynsdl/libdynsdl.dylib";
	}
}

void	Engine::changeLib(const eDynamicLib eLib)
{
	delete m_dynamic;
	dlclose(m_handle);

	currentLibrary = eLib;

	const std::string libAddress = getAddress(eLib);

	m_handle = dlopen(libAddress.c_str(), RTLD_LAZY);
	if (!m_handle)
	{
		std::cout << dlerror() << std::endl;
	}
	else
	{
		std::cout << "lib " << libAddress << " opened" << std::endl;
	}

	IDynamic * (*create)();

	create = (IDynamic*(*)())(dlsym(m_handle, "create"));
	if (!create)
	{
		std::cout << dlerror() << std::endl;
	}

	m_dynamic = create();

	// m_events = EventKeep();
}
