#include "app.hpp"

namespace rayc 
{
void App::run() {
    while (!reWindow.shouldClose()) {
        glfwPollEvents();
    }
}

void App::Cleanup() {
    vkDestroyInstance(_instance, nullptr);
    glfwDestroyWindow(reWindow._window);
    glfwTerminate();
}

void App::CreateInstance()
{
	VkApplicationInfo appInfo{ };
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Hello Test";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "Raycaster Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;

	VkInstanceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;

	uint32_t glfwExtensionCount = 0;
	const char** glfwExtentions;
	glfwExtentions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	createInfo.enabledExtensionCount = glfwExtensionCount;
	createInfo.ppEnabledExtensionNames = glfwExtentions;

	createInfo.enabledLayerCount = 0;

	if (vkCreateInstance(&createInfo, nullptr, &_instance) != VK_SUCCESS)
	{
		throw std::runtime_error("Failed to create Vulkan Instance!");
	}

	std::vector<VkExtensionProperties> extensions(glfwExtensionCount);

	vkEnumerateInstanceExtensionProperties(nullptr, &glfwExtensionCount, extensions.data());

	std::cout << glfwExtensionCount << " extensions supported:" << std::endl;
	
	for (const auto& extension : extensions)
	{
		std::cout << '\t' << extension.extensionName << std::endl;
	}
}
}