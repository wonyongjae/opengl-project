#pragma once
#include <map>
#include <vector>
#include <iostream>
#include "model_path.hpp"
#include "dependencies/ogldev/ogldev_basic_mesh.h"

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

	BasicMesh& getBasicModelTable(unsigned int arg_model_index);

private:
	G_ModelMgr() {};
	~G_ModelMgr();

	bool modelAllLoad();

	std::map<unsigned int, BasicMesh*> m_BasicModelTable;
};

