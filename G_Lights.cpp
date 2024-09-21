#include "G_Lights.h"

void DirectionalLight::CalcLocalDirection(const WorldTrans& worldTransform)
{
    LocalDirection = worldTransform.WorldDirToLocalDir(WorldDirection);
}

void PointLight::CalcLocalPosition(const WorldTrans& worldTransform)
{
    LocalPosition = worldTransform.WorldPosToLocalPos(WorldPosition);
}

void SpotLight::CalcLocalDirectionAndPosition(const WorldTrans& worldTransform)
{
    CalcLocalPosition(worldTransform);

    LocalDirection = worldTransform.WorldDirToLocalDir(WorldDirection);
}
