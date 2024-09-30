#pragma once
#include "G_ModelMgr.h"
#include "common_struct.hpp"

class G_InstanceMgr
{
public:
	/* �����ڿ� ���Կ����� ��� ���� */
	G_InstanceMgr(const G_InstanceMgr&) = delete;
	G_InstanceMgr operator=(const G_InstanceMgr&) = delete;

	/* �Ŵ����� ���� ��ü�̹Ƿ� �̱��� */
	static G_InstanceMgr& getInstance()
	{
		static G_InstanceMgr instance;
		return instance;
	}

	/* �ʱ�ȭ */
	bool init();

	std::map<int, std::vector<BasicModelInstance>>& getBasicInstTable();

	std::map<int, std::vector<SkinnedModelInstance>>& getSkinnedInstTable();

private:
	G_InstanceMgr() {};
	~G_InstanceMgr() {};

	std::map<int, std::vector<BasicModelInstance>> ma_BasicInstTable;

	std::map<int, std::vector<SkinnedModelInstance>> ma_SkinnedInstTable;

};

