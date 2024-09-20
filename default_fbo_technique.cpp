#include "default_fbo_technique.h"

bool FBOTechnique::Init()
{
    if (!Technique::Init()) {
        return false;
    }

    if (!AddShader(GL_VERTEX_SHADER, "resource/assets/shaders/default_FBO.vs")) {
        return false;
    }

    if (!AddShader(GL_FRAGMENT_SHADER, "resource/assets/shaders/default_FBO.fs")) {
        return false;
    }

    if (!Finalize()) {
        return false;
    }


    m_SamplerLoc = GetUniformLocation("gSampler");

    if (m_SamplerLoc == INVALID_UNIFORM_LOCATION)
        return false;

    return true;
}

void FBOTechnique::SetTextureUnit(unsigned int arg_texture_unit)
{
	glUniform1i(m_SamplerLoc, arg_texture_unit);
}


