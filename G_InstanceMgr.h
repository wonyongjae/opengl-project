#pragma once

class G_InstanceMgr
{
public:
	/* �����ڿ� ���Կ����� ��� ���� */
	G_InstanceMgr(const G_InstanceMgr&) = delete;
	G_InstanceMgr operator=(const G_InstanceMgr&) = delete;

	/* �Ŵ����� ���� ��ü�̹Ƿ� �̱��� */
	static G_InstanceMgr& getInstance()
	{
		static G_InstanceMgr instance;
		return instance;
	}

	/* �ʱ�ȭ */
	bool init();

private:
	G_InstanceMgr() {};
	~G_InstanceMgr() {};
};

