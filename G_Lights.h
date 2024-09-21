#pragma once
#include "dependencies/ogldev/ogldev_math_3d.h"
#include "dependencies/ogldev/ogldev_material.h"
#include "dependencies/ogldev/ogldev_world_transform.h"


/* ±âº» ºû Á¤ÀÇ */
class BaseLight
{
public:
    Vector3f Color = Vector3f(1.0f, 1.0f, 1.0f);
    float AmbientIntensity = 0.0f;
    float DiffuseIntensity = 0.0f;

    bool IsZero()
    {
        return ((AmbientIntensity == 0) && (DiffuseIntensity == 0.0f));
    }
};



/* ÅÂ¾ç±¤(´Ü¹æÇâ ºû) */
class DirectionalLight : public BaseLight
{
public:
    Vector3f WorldDirection = Vector3f(0.0f, 0.0f, 0.0f);

    void CalcLocalDirection(const WorldTrans& worldTransform);

    const Vector3f& GetLocalDirection() const { return LocalDirection; }

private:
    Vector3f LocalDirection = Vector3f(0.0f, 0.0f, 0.0f);
};



struct LightAttenuation
{
    float Constant = 1.0f;
    float Linear = 0.0f;
    float Exp = 0.0f;
};

/* Point */
class PointLight : public BaseLight
{
public:
    Vector3f WorldPosition = Vector3f(0.0f, 0.0f, 0.0f);
    LightAttenuation Attenuation;

    void CalcLocalPosition(const WorldTrans& worldTransform);

    const Vector3f& GetLocalPosition() const { return LocalPosition; }

private:
    Vector3f LocalPosition = Vector3f(0.0f, 0.0f, 0.0f);
};

/* ÁÖº¯±¤ */
class SpotLight : public PointLight
{
public:
    Vector3f WorldDirection = Vector3f(0.0f, 0.0f, 0.0f);
    float Cutoff = 0.0f;

    void CalcLocalDirectionAndPosition(const WorldTrans& worldTransform);

    const Vector3f& GetLocalDirection() const { return LocalDirection; }

private:
    Vector3f LocalDirection = Vector3f(0.0f, 0.0f, 0.0f);
};


/* PBR */
struct PBRLight {
    Vector4f PosDir;    // if w == 1 position, else direction
    Vector3f Intensity;
};
