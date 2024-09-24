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
	/* �����ڿ� ���Կ����� ��� ���� */
	G_Renderer(const G_Renderer&) = delete;
	G_Renderer operator=(const G_Renderer&) = delete;

	/* �Ŵ����� ���� ��ü�̹Ƿ� �̱��� */
	static G_Renderer& getInstance()
	{
		static G_Renderer instance;
		return instance;
	}

	/* �ʱ�ȭ */
	bool init();

	// �ӽ�
	void render();

	/* �¾籤(�ܹ��� ��) ���� */
	void SetDirectionalLight(const DirectionalLight& arg_dir_light);

	/* �¾籤(�ܹ��� ��)�� ���� ������Ʈ */
	void UpdateDirectionalLightDir(const Vector3f& arg_world_dir);


private:
	G_Renderer() {};
	~G_Renderer() {};

	void SwitchToLightingTech();

	BasicMesh* m_pBasicMesh = nullptr;		// 3d box
	LightingTechnique m_LightingTech;		// �⺻ �� ���̴�
	int m_SubTech = LightingTechnique::SUBTECH_DEFAULT;

	DirectionalLight m_DirectionalLight;


};

