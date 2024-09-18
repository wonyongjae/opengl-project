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
private:
	G_Renderer() {};
	~G_Renderer() {};

	void SwitchToLightingTech();

	BasicMesh* m_pBasicMesh = nullptr;		// 3d box
	LightingTechnique m_lightingTech;		// �⺻ �� ���̴�
	int m_subTech = LightingTechnique::SUBTECH_DEFAULT;
};

