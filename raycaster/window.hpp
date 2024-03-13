#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace rayc 
{
class REWindow 
{
public:
	REWindow(int w, int h, std::string name);

	bool shouldClose() { return glfwWindowShouldClose(_window);}
	GLFWwindow* _window;

private:
	void initWindow();

	const int width;
	const int height;

	std::string windowName;
};
}