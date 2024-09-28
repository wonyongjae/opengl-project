#pragma once
#include <GL/glew.h>
#include "dependencies/ogldev/ogldev_skinning_technique.h"
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
	void render(const float& arg_t);

	/* �¾籤(�ܹ��� ��) ���� */
	void setDirectionalLight(const DirectionalLight& arg_dir_light);

	/* �¾籤(�ܹ��� ��)�� ���� ������Ʈ */
	void updateDirectionalLightDir(const Vector3f& arg_world_dir);


private:
	G_Renderer() {};
	~G_Renderer() {};

	bool lightingTechInit();
	bool skinnigTechInit();

	void refreshLightingPosAndDirs(BasicMesh& arg_mesh);

	void switchToLightingTech();
	void switchToSkinningTech();

	void renderBasicModel(BasicMesh& arg_basic_mseh);
	void renderSkinnedModel(SkinnedMesh& arg_skinned_mseh, const float& arg_t);

	DirectionalLight m_DirectionalLight;

	uint m_PointLightCnt = 0;
	PointLight m_PointLights[LightingTechnique::MAX_POINT_LIGHTS];

	uint m_SpotLightCnt = 0;
	SpotLight m_SpotLights[LightingTechnique::MAX_SPOT_LIGHTS];


	LightingTechnique m_LightingTech;		// �⺻ �� ���̴�
	int m_SubTech = LightingTechnique::SUBTECH_DEFAULT;
	SkinningTechnique m_SkinningTech;		// �ִϸ��̼� �� ���̴�

};

