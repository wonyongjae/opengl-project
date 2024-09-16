#include "iostream"
#include "G_WindowMgr.h"
#include "G_InputMgr.h"
#include "G_CameraMgr.h"
#include "G_Renderer.h"


bool init() 
{
	bool init_window = G_WindowMgr::getInstance().init();
	if (!init_window)
		return false;

	bool init_input  = G_InputMgr::getInstance().init(G_WindowMgr::getInstance().getWindow());
	if (!init_input)
		return false;

	bool init_camera = G_CameraMgr::getInstance().init();
	if (!init_camera)
		return false;

	bool init_renderer = G_Renderer::getInstance().init();
	if (!init_renderer)
		return false;

	return true;
};

void run()
{
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(G_WindowMgr::getInstance().getWindow())) {
		// 버퍼와 렌더링 로직을 여기에 추가합니다.

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(135.0f / 255.0f, 135.0f / 255.0f, 135.0f / 255.0f, 1.0f);

		G_CameraMgr::getInstance().getCamera()->OnRender();
		G_Renderer::getInstance().renderCube();

		// 이벤트 처리
		glfwPollEvents();

		// Swap buffers
		glfwSwapBuffers(G_WindowMgr::getInstance().getWindow());
	}
};

void end()
{
	G_WindowMgr::getInstance().cleanup();
}


int main() 
{
	if (!init()) {
		std::cerr << "Initialization failed!" << std::endl;
		return -1;
	}

	run();
	end();
}