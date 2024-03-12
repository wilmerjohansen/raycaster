#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace wind {
	class REWindow {
		public:
			REWindow(int w, int h, std::string name);
			~REWindow();

			bool shouldClose() { return glfwWindowShouldClose(window);}

		private:
			void initWindow();

			const int width;
			const int height;

			std::string windowName;
			GLFWwindow *window;
	};
}