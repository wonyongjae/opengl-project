#pragma once
#include <map>
#include <vector>
#include <iostream>
#include "terrain_path.hpp"
#include "dependencies/ogldev/ogldev_basic_mesh.h"

class G_TerrainMgr
{
public:
	/* �����ڿ� ���Կ����� ��� ���� */
	G_TerrainMgr(const G_TerrainMgr&) = delete;
	G_TerrainMgr operator=(const G_TerrainMgr&) = delete;

	/* �Ŵ����� ���� ��ü�̹Ƿ� �̱��� */
	static G_TerrainMgr& getInstance()
	{
		static G_TerrainMgr instance;
		return instance;
	}

	/* �ʱ�ȭ */
	bool init();

	BasicMesh& getTerrainModel(unsigned int arg_terrain_index);

private:
	G_TerrainMgr() {};
	~G_TerrainMgr() {};

	bool terrainAllLoad();

	std::map<unsigned int, BasicMesh*> m_TerrainTable;
};

