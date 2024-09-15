#include "G_WindowMgr.h"

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
	// �����ӹ��� ũ�Ⱑ ����Ǹ� ���ο� ũ��� ����Ʈ ����
	std::cout << "Framebuffer size changed: " << width << " x " << height << std::endl;
	glViewport(0, 0, width, height);
}

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
	g_Window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, PROJECT_NAME, NULL, NULL);
	if (!g_Window)
	{
		glfwTerminate();
		return false;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(g_Window);

	/* Framebuffer Size Callback set */
	glfwSetFramebufferSizeCallback(g_Window, framebufferSizeCallback);

	/* Initialize the glew library */
	if (glewInit() != GLEW_OK) {
		glfwDestroyWindow(g_Window);
		glfwTerminate();
		return false;
	}

	return true;
}
