#include "window.hpp"

namespace rayc 
{
REWindow::REWindow(int w, int h, std::string name) : width{ w }, height{ h }, windowName{ name } 
{
	initWindow();
}

void REWindow::initWindow() 
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	_window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
}
}