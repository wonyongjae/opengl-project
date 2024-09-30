#pragma once
#include "G_ModelMgr.h"
#include "common_struct.hpp"

class G_InstanceMgr
{
public:
	/* 생성자와 대입연산자 사용 방지 */
	G_InstanceMgr(const G_InstanceMgr&) = delete;
	G_InstanceMgr operator=(const G_InstanceMgr&) = delete;

	/* 매니저는 전역 객체이므로 싱글톤 */
	static G_InstanceMgr& getInstance()
	{
		static G_InstanceMgr instance;
		return instance;
	}

	/* 초기화 */
	bool init();

	std::map<int, std::vector<BasicModelInstance>>& getBasicInstTable();

	std::map<int, std::vector<SkinnedModelInstance>>& getSkinnedInstTable();

private:
	G_InstanceMgr() {};
	~G_InstanceMgr() {};

	std::map<int, std::vector<BasicModelInstance>> ma_BasicInstTable;

	std::map<int, std::vector<SkinnedModelInstance>> ma_SkinnedInstTable;

};

