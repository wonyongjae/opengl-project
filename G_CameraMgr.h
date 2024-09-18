#pragma once
#include "common.hpp"
#include "dependencies/ogldev/ogldev_basic_glfw_camera.h"

class G_CameraMgr
{
public:
	/* 생성자와 대입연산자 사용 방지 */
	G_CameraMgr(const G_CameraMgr&) = delete;
	G_CameraMgr operator=(const G_CameraMgr&) = delete;

	/* 매니저는 전역 객체이므로 싱글톤 */
	static G_CameraMgr& getInstance()
	{
		static G_CameraMgr instance;
		return instance;
	}

	/* 초기화 */
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

