#include "G_TerrainMgr.h"

bool G_TerrainMgr::init()
{
	if (!terrainAllLoad())
		return false;
    return true;
}

BasicMesh& G_TerrainMgr::getTerrainTable(unsigned int arg_terrain_index)
{
	auto terrain_it = m_TerrainTable.find(arg_terrain_index);
	return *terrain_it->second;
}

bool G_TerrainMgr::terrainAllLoad()
{
	// terrain load
	static unsigned int model_cnt = 0;

	BasicMesh* basicMesh = new BasicMesh();
	basicMesh->LoadMesh(MODEL_GROUND);

	m_TerrainTable.emplace(model_cnt, basicMesh);

	return true;
}
