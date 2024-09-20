#pragma once
#include "common.hpp"
#include "dependencies/ogldev/ogldev_engine_common.h"
#include "dependencies/ogldev/ogldev_framebuffer.h"
#include "default_fbo_technique.h"

class G_Scene
{
public:
	/* �����ڿ� ���Կ����� ��� ���� */
	G_Scene(const G_Scene&) = delete;
	G_Scene operator=(const G_Scene&) = delete;

	/* �Ŵ����� ���� ��ü�̹Ƿ� �̱��� */
	static G_Scene& getInstance()
	{
		static G_Scene instance;
		return instance;
	}

	/* �ʱ�ȭ */
	bool init();

	/* �⺻ ������ ���ۿ� �׸��� */
	void defaultFBOWrite();

	/* �⺻ ������ ���ۿ� �׷��� ��� ������ */
	void defaultFBODraw();

	/* �⺻ ������ ���۷� �ؽ�ó ���� */
	void renderQuad();

	Framebuffer getDefaultFBO() { return m_DefaultFBO; };

private:
	G_Scene() {};
	~G_Scene() {};

	unsigned int quadVAO;
	unsigned int quadVBO;

	Framebuffer m_DefaultFBO;
	FBOTechnique m_DefaultFBOTech;
};