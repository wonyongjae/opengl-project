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
	// model load
	static unsigned int model_cnt = 0;

	BasicMesh* basicMesh = new BasicMesh();
	basicMesh->LoadMesh(MODEL_BOX);

	m_BasicModelTable.emplace(model_cnt, basicMesh);

	model_cnt++;

	return true;
}


BasicMesh& G_ModelMgr::getBasicModelTable(unsigned int arg_model_index)
{
	auto model_it = m_BasicModelTable.find(arg_model_index);
	return *model_it->second;

}