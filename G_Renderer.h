#pragma once
#include <GL/glew.h>
#include "dependencies/ogldev/ogldev_new_lighting.h"
#include "dependencies/ogldev/ogldev_engine_common.h"
#include "G_CameraMgr.h"
#include "G_ModelMgr.h"
#include "G_TerrainMgr.h"
#include "G_Scene.h"
#include "G_Lights.h"

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

	/* 태양광(단방향 빛) 설정 */
	void SetDirectionalLight(const DirectionalLight& arg_dir_light);

	/* 태양광(단방향 빛)의 방향 업데이트 */
	void UpdateDirectionalLightDir(const Vector3f& arg_world_dir);


private:
	G_Renderer() {};
	~G_Renderer() {};

	void SwitchToLightingTech();

	BasicMesh* m_pBasicMesh = nullptr;		// 3d box
	LightingTechnique m_LightingTech;		// 기본 모델 셰이더
	int m_SubTech = LightingTechnique::SUBTECH_DEFAULT;

	DirectionalLight m_DirectionalLight;


};

