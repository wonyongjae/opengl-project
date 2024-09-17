#pragma once
#include <GL/glew.h>
#include "G_CameraMgr.h"
#include "dependency/ogldev/technique.h"
#include "dependency/ogldev/ogldev_math_3d.h"
#include "dependency/ogldev/ogldev_world_transform.h"


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
};

