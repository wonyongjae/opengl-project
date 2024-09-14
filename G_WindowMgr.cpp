#include "G_WindowMgr.h"

bool G_WindowMgr::init()
{
	/* Initialize the glfw library */
	if (!glfwInit())
		return false;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	/* Create a windowed mode window and its OpenGL context */
	g_Window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HIGHT, PROJECT_NAME, NULL, NULL);
	if (!g_Window)
	{
		glfwTerminate();
		return false;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(g_Window);

	/* Initialize the glew library */
	if (glewInit() != GLEW_OK) {
		glfwDestroyWindow(g_Window);
		glfwTerminate();
		return false;
	}

	return true;
}
