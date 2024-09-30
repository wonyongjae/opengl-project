#pragma once
#include "dependencies/ogldev/ogldev_util.h"
#include "dependencies/ogldev/ogldev_math_3d.h"

struct BasicModelInstance
{
	unsigned int	m_ModelIndex;
	Vector3f		m_Position;
	Vector3f		m_Rotation;
	float			m_Scale;
};

struct AnimationInfo 
{
	unsigned int	m_AnimationIndex;
};

struct SkinnedModelInstance : BasicModelInstance
{
	AnimationInfo m_AnimationInfo;
};