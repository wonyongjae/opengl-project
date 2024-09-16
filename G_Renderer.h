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
	void initCube();
	void renderCube();
	void compileShaders();
	void addShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType);
private:
	G_Renderer() {};
	~G_Renderer() {};

	// �ӽ�
	GLuint m_VBO;
	GLuint m_IBO;
	GLuint ShaderProgram;
	GLuint gWVPLocation;
	WorldTrans CubeWorldTransform;
	const char* pVSFileName = "resource/assets/shaders/cube.vs";
	const char* pFSFileName = "resource/assets/shaders/cube.fs";

};

