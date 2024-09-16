#include "G_CameraMgr.h"

bool G_CameraMgr::init()
{
    Vector3f pos(0.0f, 0.0f, -5.0f); // ī�޶� �������� �ڷ� 5 ���� �̵�
    Vector3f target(0.0f, 0.0f, 1.0f); // ī�޶� Z�� ���� ������ �ٶ�
    Vector3f up(0.0f, 1.0f, 0.0f);
    float fov = 45.0f;
    float near = 0.1f;
    float far = 100.0f;
    PersProjInfo persProjInfo = { fov, (float)WINDOW_WIDTH, (float)WINDOW_HEIGHT, near, far };
    m_ProjCamera = new BasicCamera(persProjInfo, pos, target, up);

	return true;
}
