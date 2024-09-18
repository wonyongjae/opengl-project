#pragma once
#include <GL/glew.h>
#include "G_CameraMgr.h"
//#include "dependencies/ogldev/technique.h"
//#include "dependencies/ogldev/ogldev_math_3d.h"
//#include "dependencies/ogldev/ogldev_world_transform.h"
#include "dependencies/ogldev/ogldev_basic_mesh.h"
#include "dependencies/ogldev/ogldev_new_lighting.h"
#include "dependencies/ogldev/ogldev_engine_common.h"
#include "G_CameraMgr.h"

class G_Renderer
{
public:
	/* 생성자와 대입연산자 사용 방지 */
	G_Renderer(const G_Renderer&) = delete;
	G_Renderer operator=(const G_Renderer&) = delete;

	/* 매니저는 전역 객체이므로 싱글톤 */
	static G_Renderer& getInstance()
	{
		static G_Renderer instance;
		return instance;
	}

	/* 초기화 */
	bool init();

	// 임시
	void render();
private:
	G_Renderer() {};
	~G_Renderer() {};

	void SwitchToLightingTech();

	BasicMesh* m_pBasicMesh = nullptr;		// 3d box
	LightingTechnique m_lightingTech;		// 기본 모델 셰이더
	int m_subTech = LightingTechnique::SUBTECH_DEFAULT;
};

