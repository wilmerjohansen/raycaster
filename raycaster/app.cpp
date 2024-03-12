#include "app.hpp"

namespace wind {
	void App::run() {
		while (!reWindow.shouldClose()) {
			glfwPollEvents();

		}
	}
}