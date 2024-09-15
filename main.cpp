#include "iostream"
#include "G_WindowMgr.h"
#include "G_InputMgr.h"



bool init() 
{
	bool init_window = G_WindowMgr::getInstance().init();
	if (!init_window)
		return false;

	G_InputMgr::getInstance().init(G_WindowMgr::getInstance().getWindow());

	return true;
};

void run()
{
	while (!glfwWindowShouldClose(G_WindowMgr::getInstance().getWindow())) {
		// 버퍼와 렌더링 로직을 여기에 추가합니다.

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(135.0f / 255.0f, 135.0f / 255.0f, 135.0f / 255.0f, 1.0f);

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
	init();
	run();
	end();
}