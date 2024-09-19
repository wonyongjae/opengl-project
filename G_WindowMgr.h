#pragma once
#include "common.hpp"
#include "iostream"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

class G_WindowMgr
{
public:
	/* 생성자와 대입연산자 사용 방지 */
	G_WindowMgr(const G_WindowMgr&) = delete;
	G_WindowMgr operator=(const G_WindowMgr&) = delete;

	/* 매니저는 전역 객체이므로 싱글톤 */
	static G_WindowMgr& getInstance()
	{
		static G_WindowMgr instance;
		return instance;
	}

	/* 초기화 */
	bool init();

	/* 윈도우 반환 */
	GLFWwindow* getWindow() const { return g_Window; }

	/* 윈도우 삭제 */
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

