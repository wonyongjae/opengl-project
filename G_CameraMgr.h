#pragma once
#include "common.hpp"
#include "dependencies/ogldev/ogldev_basic_glfw_camera.h"

class G_CameraMgr
{
public:
	/* �����ڿ� ���Կ����� ��� ���� */
	G_CameraMgr(const G_CameraMgr&) = delete;
	G_CameraMgr operator=(const G_CameraMgr&) = delete;

	/* �Ŵ����� ���� ��ü�̹Ƿ� �̱��� */
	static G_CameraMgr& getInstance()
	{
		static G_CameraMgr instance;
		return instance;
	}

	/* �ʱ�ȭ */
	bool init();

	BasicCamera* getCamera() { return m_ProjCamera; };

private:
	G_CameraMgr() {};
	~G_CameraMgr() 
	{
		delete m_ProjCamera;
		delete m_OrthoCamera;
		m_ProjCamera = nullptr;
		m_OrthoCamera = nullptr;
	};

	BasicCamera* m_ProjCamera;
	BasicCamera* m_OrthoCamera;
};

