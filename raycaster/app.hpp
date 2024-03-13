#pragma once 

#include <iostream>
#include <stdexcept>
#include <vector>

#include "window.hpp"

namespace rayc
{

class App 
{

public:
	static constexpr int WIDTH = 800;
	static constexpr int HEIGHT = 600;

	void run();

	void InitVulkan();
	void Cleanup();
	void CreateInstance();

private:
	REWindow reWindow{ WIDTH, HEIGHT, "Hello Vulkan!" };
	VkInstance _instance;
};
}