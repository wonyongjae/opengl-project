#pragma once
#include <map>
#include <vector>
#include <iostream>
#include "terrain_path.hpp"
#include "dependencies/ogldev/ogldev_basic_mesh.h"

class G_TerrainMgr
{
public:
	/* 생성자와 대입연산자 사용 방지 */
	G_TerrainMgr(const G_TerrainMgr&) = delete;
	G_TerrainMgr operator=(const G_TerrainMgr&) = delete;

	/* 매니저는 전역 객체이므로 싱글톤 */
	static G_TerrainMgr& getInstance()
	{
		static G_TerrainMgr instance;
		return instance;
	}

	/* 초기화 */
	bool init();

	BasicMesh& getTerrainModel(unsigned int arg_terrain_index);

private:
	G_TerrainMgr() {};
	~G_TerrainMgr() {};

	bool terrainAllLoad();

	std::map<unsigned int, BasicMesh*> m_TerrainTable;
};

