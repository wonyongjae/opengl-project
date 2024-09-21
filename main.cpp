#include "iostream"

#include "G_WindowMgr.h"
#include "G_InputMgr.h"
#include "G_CameraMgr.h"

#include "G_Scene.h"
#include "G_Lights.h"
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

	bool init_scene = G_Scene::getInstance().init();
	if (!init_scene)
		return false;


	// 임시 빛 init
	DirectionalLight g_DirectionalLight;
	g_DirectionalLight.AmbientIntensity = 0.5f;
	g_DirectionalLight.DiffuseIntensity = 0.9f;
	g_DirectionalLight.WorldDirection = Vector3f(0.0f, 0.0f, -1.0f);
	g_DirectionalLight.Color = Vector3f(1.0f, 1.0f, 1.0f);

	bool init_renderer = G_Renderer::getInstance().init();
	if (!init_renderer)
		return false;
	G_Renderer::getInstance().SetDirectionalLight(g_DirectionalLight);

	return true;
};

void run()
{
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_ALPHA_TEST);

	while (!glfwWindowShouldClose(G_WindowMgr::getInstance().getWindow())) {

		// 이벤트 처리
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(135.0f / 255.0f, 135.0f / 255.0f, 135.0f / 255.0f, 1.0f);

		G_CameraMgr::getInstance().getCamera()->OnRender();

		G_Scene::getInstance().defaultFBOWrite();
		G_Renderer::getInstance().render();
		G_Scene::getInstance().defaultFBODraw();

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