#pragma once 

#include "window.hpp"

namespace wind {
	class App {

	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		void run();

	private:
		REWindow reWindow{ WIDTH, HEIGHT, "Hello Vulkan!" };
	};
}