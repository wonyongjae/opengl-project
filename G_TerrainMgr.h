#pragma once


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
private:
	G_TerrainMgr() {};
	~G_TerrainMgr() {};
};

