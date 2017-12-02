#include "lispcraft.h"

/*
 * return status:
 *         0: good
 *         -1: not good
 *         other: err code
 */

void* init_glfw(int width, int height, const char* title)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
	glfwMakeContextCurrent(window);

	window_width = width;
	window_height = height;

	glewExperimental = GL_TRUE;
	glewInit();

	glfwSwapInterval(1);

	main_window = window;
	return (void*)window;
}

int get_frame_size()
{
	glfwGetFramebufferSize(main_window, &window_width, &window_height);
	return 0;
}

