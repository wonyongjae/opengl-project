#pragma once
#include "common.hpp"
#include "iostream"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

class G_WindowMgr
{
public:
	/* �����ڿ� ���Կ����� ��� ���� */
	G_WindowMgr(const G_WindowMgr&) = delete;
	G_WindowMgr operator=(const G_WindowMgr&) = delete;

	/* �Ŵ����� ���� ��ü�̹Ƿ� �̱��� */
	static G_WindowMgr& getInstance()
	{
		static G_WindowMgr instance;
		return instance;
	}

	/* �ʱ�ȭ */
	bool init();

	/* ������ ��ȯ */
	GLFWwindow* getWindow() const { return g_Window; }

	/* ������ ���� */
	void cleanup()
	{
		glfwDestroyWindow(g_Window);
		glfwTerminate();
	}

private:
	G_WindowMgr() : g_Window(nullptr) {};
	~G_WindowMgr() { cleanup(); };

	GLFWwindow* g_Window;
};

