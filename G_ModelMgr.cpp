#include "G_ModelMgr.h"

G_ModelMgr::~G_ModelMgr()
{
	for (auto& it : m_BasicModelTable)
	{
		it.second = nullptr;
		delete it.second;
	}
}

bool G_ModelMgr::init()
{
	if (!modelAllLoad())
		return false;
	return true;
}

bool G_ModelMgr::modelAllLoad()
{
	// basic model load
	if (!basicModelLoad(MODEL_BOX)) return false;

	// skinned model load
	if (!skinnedModelLoad(MODEL_MAN)) return false;
	
	return true;
}

bool G_ModelMgr::basicModelLoad(const char* arg_model_path)
{
	static unsigned int model_cnt = 0;
	BasicMesh* basicMesh = new BasicMesh();
	if (!basicMesh->LoadMesh(arg_model_path)) {
		printf("Error loading mesh %s", arg_model_path);
		return false;
	}
	m_BasicModelTable.emplace(model_cnt, basicMesh);
	
	return true;
}

bool G_ModelMgr::skinnedModelLoad(const char* arg_model_path)
{
	static unsigned int model_cnt = 0;
	SkinnedMesh* skinnedMesh = new SkinnedMesh();
	if (!skinnedMesh->LoadMesh(arg_model_path)) {
		printf("Error loading mesh %s", arg_model_path);
		return false;
	}
	m_SkinnedModelTable.emplace(model_cnt, skinnedMesh);

	return true;
}


BasicMesh& G_ModelMgr::getBasicModel(unsigned int arg_model_index)
{
	auto model_it = m_BasicModelTable.find(arg_model_index);
	return *model_it->second;

}

SkinnedMesh& G_ModelMgr::getSkinnedModel(unsigned int arg_model_index)
{
	auto model_it = m_SkinnedModelTable.find(arg_model_index);
	return *model_it->second;
}

std::map<unsigned int, BasicMesh*>& G_ModelMgr::getBasicModelTable()
{
	return m_BasicModelTable;
}


std::map<unsigned int, SkinnedMesh*>& G_ModelMgr::getSkinnedModelTable()
{
	return m_SkinnedModelTable;
}
