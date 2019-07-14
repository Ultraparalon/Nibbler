#include "DynamicOpengl.h"

int g_keys = 0;

static unsigned int keyaction(const int key)
{
	switch (key)
	{
		case GLFW_KEY_ESCAPE: return (1 << 5);
		case GLFW_KEY_1: return (1 << 29);
		case GLFW_KEY_2: return (1 << 28);
		case GLFW_KEY_3: return (1 << 27);
		case GLFW_KEY_W: return (1 << 6);
		case GLFW_KEY_S: return (1 << 7);
		case GLFW_KEY_A: return (1 << 8);
		case GLFW_KEY_D: return (1 << 9);
		default: return 0;
	}
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	switch (action)
	{
		case GLFW_PRESS: g_keys |= keyaction(key); break;
		case GLFW_RELEASE: g_keys &= ~keyaction(key); break;
	}
}

DynamicOpengl::DynamicOpengl()
{
	if (!glfwInit())
	{
		exit(1);
	}
	// glfwWindowHint(GLFW_FSAA_SAMPLES, 4); // 4x Сглаживание
	// glfwWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3); // Мы хотим использовать OpenGL 3.3
	// glfwWindowHint(GLFW_OPENGL_VERSION_MINOR, 3);
	// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	// glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Мы не хотим старый OpenGL
	
	window = glfwCreateWindow( 1024, 768, "OpenGL", NULL, NULL);
	if (!window)
	{
		std::cout << "window not created" << std::endl;
	}
	else
		std::cout << "Window created" << std::endl;

	glfwMakeContextCurrent(window);

	glewExperimental = true;

	if (glewInit() != GLEW_OK)
	{
		std::cout << "!Glew" << std::endl;
		exit(1);
	}

	glfwSetKeyCallback(window, &key_callback);

	//for some weird reason it's not working(((
	// glfwLoadTexture2D("dynopengl/resources/textures/snake_head.bmp", 0);
	// glfwReadImage("dynopengl/resources/textures/snake_head.bmp", 0);

}

DynamicOpengl::~DynamicOpengl()
{
	glfwDestroyWindow(window);
}

void DynamicOpengl::drawBackground(const unsigned int)
{

}

void DynamicOpengl::drawObject(const int y, const int x,
	const unsigned int type)
{

}

void DynamicOpengl::render()
{

	// glfwSetKeyCallback(window, key_callback);

	// while (!glfwWindowShouldClose(window))
	// {

	// }

}

void DynamicOpengl::playSound(const int sound)
{

}

void DynamicOpengl::playMusic(const int music)
{

}


void DynamicOpengl::inputRefresh()
{
	// glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
	// glfwWindowShouldClose(window) == 0 )
	// {
	//     glfwPollEvents();
	// }
	glfwPollEvents();

	m_keys = g_keys;

	// key_callback
}

int DynamicOpengl::getMouseY() const
{
	return m_mousey;
}

int DynamicOpengl::getMouseX() const
{
	return m_mousex;
}

unsigned int DynamicOpengl::getKeys() const
{
	return m_keys;
}

extern "C" IDynamic * create()
{
	return new DynamicOpengl();
}
