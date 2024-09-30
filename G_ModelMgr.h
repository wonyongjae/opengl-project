#pragma once
#include <map>
#include <vector>
#include <iostream>
#include "model_path.hpp"
#include "dependencies/ogldev/ogldev_skinned_mesh.h"

class G_ModelMgr
{
public:
	/* �����ڿ� ���Կ����� ��� ���� */
	G_ModelMgr(const G_ModelMgr&) = delete;
	G_ModelMgr operator=(const G_ModelMgr&) = delete;

	/* �Ŵ����� ���� ��ü�̹Ƿ� �̱��� */
	static G_ModelMgr& getInstance()
	{
		static G_ModelMgr instance;
		return instance;
	}

	/* �ʱ�ȭ */
	bool init();

	BasicMesh& getBasicModel(unsigned int arg_model_index);

	SkinnedMesh& getSkinnedModel(unsigned int arg_model_index);

	std::map<unsigned int, BasicMesh*>& getBasicModelTable();

	std::map<unsigned int, SkinnedMesh*>& getSkinnedModelTable();

private:
	G_ModelMgr() {};
	~G_ModelMgr();

	bool modelAllLoad();

	bool basicModelLoad(const char* arg_model_path);

	bool skinnedModelLoad(const char* arg_model_path);

	std::map<unsigned int, BasicMesh*> m_BasicModelTable;

	std::map<unsigned int, SkinnedMesh*> m_SkinnedModelTable;
};

