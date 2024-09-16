#pragma once
#include <GL/glew.h>
#include "G_CameraMgr.h"
#include "dependency/ogldev/technique.h"
#include "dependency/ogldev/ogldev_math_3d.h"
#include "dependency/ogldev/ogldev_world_transform.h"


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
	void initCube();
	void renderCube();
	void compileShaders();
	void addShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType);
private:
	G_Renderer() {};
	~G_Renderer() {};

	// 임시
	GLuint m_VBO;
	GLuint m_IBO;
	GLuint ShaderProgram;
	GLuint gWVPLocation;
	WorldTrans CubeWorldTransform;
	const char* pVSFileName = "resource/assets/shaders/cube.vs";
	const char* pFSFileName = "resource/assets/shaders/cube.fs";

};

