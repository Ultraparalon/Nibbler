#ifndef DYNAMICOPENGL_H
#define DYNAMICOPENGL_H

#include "../../includes/IDynamic.h"

#include <iostream>

// #include <glm/glm.hpp>
#include <GL/glew.h>

// #include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <OpenGL/glext.h>

class DynamicOpengl : public IDynamic
{
public:
	DynamicOpengl();
	~DynamicOpengl();

	void drawBackground(const unsigned int);
	void drawObject(const int, const int, const unsigned int);
	void render();
	void playSound(const int);
	void playMusic(const int);

	void inputRefresh();
	int getMouseY() const;
	int getMouseX() const;
	unsigned int getKeys() const;
	
	unsigned int m_keys;

private:
	int m_mousey;
	int m_mousex;
	// unsigned int m_keys;

	GLFWwindow * window;

	// void key_callback(GLFWwindow *, int, int, int, int);
	
};

#endif