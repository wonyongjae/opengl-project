#include "G_InstanceMgr.h"

bool G_InstanceMgr::init()
{
	for (const auto& basicModelPair : G_ModelMgr::getInstance().getBasicModelTable())
	{
		int key = basicModelPair.first;
		std::vector<BasicModelInstance> basicModelInstList;
		this->ma_BasicInstTable.insert({ key, basicModelInstList });
	}

	for (const auto& skinnedModelPair : G_ModelMgr::getInstance().getSkinnedModelTable())
	{
		int key = skinnedModelPair.first;
		std::vector<SkinnedModelInstance> skinnedModelInstList;
		this->ma_SkinnedInstTable.insert({ key, skinnedModelInstList });
	}

    return true;
}

std::map<int, std::vector<BasicModelInstance>>& G_InstanceMgr::getBasicInstTable()
{
	return ma_BasicInstTable;
}

std::map<int, std::vector<SkinnedModelInstance>>& G_InstanceMgr::getSkinnedInstTable()
{
	return ma_SkinnedInstTable;
}
