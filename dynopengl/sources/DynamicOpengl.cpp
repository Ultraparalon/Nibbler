#include "DynamicOpengl.h"

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

}

DynamicOpengl::~DynamicOpengl()
{
	glfwDestroyWindow(window);
}

void DynamicOpengl::drawObject(const int y, const int x,
	const unsigned int type)
{

}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void DynamicOpengl::render()
{

	// glfwSetKeyCallback(window, key_callback);

	// while (!glfwWindowShouldClose(window))
	// {

	// }
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

do{
    // Пока что ничего не выводим. Это будет в уроке 2.

    // Сбрасываем буферы
    // glfwSwapBuffers(window);
    glfwPollEvents();

} // Проверяем нажатие клавиши Escape или закрытие окна
while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
glfwWindowShouldClose(window) == 0 );
}

void DynamicOpengl::playSound(const int sound)
{

}

void DynamicOpengl::playMusic(const int music)
{

}

void DynamicOpengl::inputRefresh()
{

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
