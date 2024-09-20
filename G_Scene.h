#pragma once
#include "common.hpp"
#include "dependencies/ogldev/ogldev_engine_common.h"
#include "dependencies/ogldev/ogldev_framebuffer.h"
#include "default_fbo_technique.h"

class G_Scene
{
public:
	/* 생성자와 대입연산자 사용 방지 */
	G_Scene(const G_Scene&) = delete;
	G_Scene operator=(const G_Scene&) = delete;

	/* 매니저는 전역 객체이므로 싱글톤 */
	static G_Scene& getInstance()
	{
		static G_Scene instance;
		return instance;
	}

	/* 초기화 */
	bool init();

	/* 기본 프레임 버퍼에 그리기 */
	void defaultFBOWrite();

	/* 기본 프레임 버퍼에 그려진 요소 렌더링 */
	void defaultFBODraw();

	/* 기본 프레임 버퍼로 텍스처 생성 */
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