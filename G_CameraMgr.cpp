#include "G_CameraMgr.h"

bool G_CameraMgr::init()
{
    Vector3f pos(0.0f, 0.0f, -5.0f); // 카메라를 원점에서 뒤로 5 단위 이동
    Vector3f target(0.0f, 0.0f, 1.0f); // 카메라가 Z축 양의 방향을 바라봄
    Vector3f up(0.0f, 1.0f, 0.0f);
    float fov = 45.0f;
    float near = 0.1f;
    float far = 100.0f;
    PersProjInfo persProjInfo = { fov, (float)WINDOW_WIDTH, (float)WINDOW_HEIGHT, near, far };
    m_ProjCamera = new BasicCamera(persProjInfo, pos, target, up);

	return true;
}
