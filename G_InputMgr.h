#pragma once
#include "iostream"
#include "stdlib.h"
#include "GLFW/glfw3.h"
#include "common.hpp"

struct {
	bool isLeftPressed = false;
	bool isRightPressed = false;
	int x;
	int y;
} m_Mouse;

class G_InputMgr
{
public:
	/* �����ڿ� ���Կ����� ��� ���� */
	G_InputMgr(const G_InputMgr&) = delete;
	G_InputMgr operator=(const G_InputMgr&) = delete;

	/* �Ŵ����� ���� ��ü�̹Ƿ� �̱��� */
	static G_InputMgr& getInstance()
	{
		static G_InputMgr instance;
		return instance;
	}

	/* �ʱ�ȭ */
	bool init(GLFWwindow* arg_window);

	static void keyboardCallback(GLFWwindow* arg_window, int arg_key, int arg_scancode, int arg_action, int arg_mods);
	static void mouseCursorPosCallback(GLFWwindow* arg_window, double arg_x, double arg_y);
	static void mouseButtonCallback(GLFWwindow* arg_window, int arg_button, int arg_action, int arg_Mode);

private:
	G_InputMgr() {};
	~G_InputMgr() {};
};

