#pragma once
#include <map>
#include <vector>
#include <iostream>
#include "model_path.hpp"
#include "dependencies/ogldev/ogldev_basic_mesh.h"

class G_ModelMgr
{
public:
	/* 생성자와 대입연산자 사용 방지 */
	G_ModelMgr(const G_ModelMgr&) = delete;
	G_ModelMgr operator=(const G_ModelMgr&) = delete;

	/* 매니저는 전역 객체이므로 싱글톤 */
	static G_ModelMgr& getInstance()
	{
		static G_ModelMgr instance;
		return instance;
	}

	/* 초기화 */
	bool init();

	BasicMesh& getBasicModelTable(unsigned int arg_model_index);

private:
	G_ModelMgr() {};
	~G_ModelMgr();

	bool modelAllLoad();

	std::map<unsigned int, BasicMesh*> m_BasicModelTable;
};

