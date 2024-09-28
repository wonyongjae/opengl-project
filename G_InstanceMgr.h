#pragma once

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

private:
	G_InstanceMgr() {};
	~G_InstanceMgr() {};
};

