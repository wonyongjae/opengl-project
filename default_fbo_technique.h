#pragma once
#include "dependencies/ogldev/technique.h"
#include "dependencies/ogldev/ogldev_math_3d.h"

class FBOTechnique : public Technique
{
public:
	FBOTechnique() {};

	virtual bool Init();

	void SetTextureUnit(unsigned int arg_texture_unit);

private:

	GLuint m_SamplerLoc = -1;
};

