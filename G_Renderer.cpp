#include "G_Renderer.h"


bool G_Renderer::init()
{
    if (!lightingTechInit()) return false;

    if (!skinnigTechInit()) return false;

    glUseProgram(0);

    return true;
}

void G_Renderer::setDirectionalLight(const DirectionalLight& arg_dir_light)
{
    m_DirectionalLight = arg_dir_light;

    switchToLightingTech();
    m_LightingTech.SetDirectionalLight(m_DirectionalLight, false);
}

void G_Renderer::updateDirectionalLightDir(const Vector3f& arg_world_dir)
{
    m_DirectionalLight.WorldDirection = arg_world_dir;
}

void G_Renderer::render(const float& arg_t)
{
    // basic model
    renderBasicModel(G_ModelMgr::getInstance().getBasicModel(0));

    // skinned model
    renderSkinnedModel(G_ModelMgr::getInstance().getSkinnedModel(0), arg_t);

    // terrain quad
    renderBasicModel(G_TerrainMgr::getInstance().getTerrainModel(0));

}

bool G_Renderer::lightingTechInit()
{
    if (!m_LightingTech.Init(m_SubTech)) {
        printf("Error initializing the lighting technique\n");
        return false;
    }

    m_LightingTech.Enable();
    m_LightingTech.SetTextureUnit(COLOR_TEXTURE_UNIT_INDEX);
    m_LightingTech.SetAlbedoTextureUnit(ALBEDO_TEXTURE_UNIT_INDEX);
    m_LightingTech.SetRoughnessTextureUnit(ROUGHNESS_TEXTURE_UNIT_INDEX);
    m_LightingTech.SetMetallicTextureUnit(METALLIC_TEXTURE_UNIT_INDEX);
    m_LightingTech.SetNormalTextureUnit(NORMAL_TEXTURE_UNIT_INDEX);

    return true;
}

bool G_Renderer::skinnigTechInit()
{
    if (!m_SkinningTech.Init()) {
        printf("Error initializing the skinning technique\n");
        return false;
    }

    m_SkinningTech.Enable();
    m_SkinningTech.SetTextureUnit(COLOR_TEXTURE_UNIT_INDEX);
    m_SkinningTech.SetSpecularExponentTextureUnit(SPECULAR_EXPONENT_UNIT_INDEX);

    return true;
}

void G_Renderer::refreshLightingPosAndDirs(BasicMesh& arg_mesh)
{
    WorldTrans& meshWorldTransform = arg_mesh.GetWorldTransform();

    if (m_DirectionalLight.DiffuseIntensity > 0.0) {
        m_DirectionalLight.CalcLocalDirection(meshWorldTransform);
    }

    for (uint i = 0; i < m_PointLightCnt; i++) {
        m_PointLights[i].CalcLocalPosition(meshWorldTransform);
    }

    for (uint i = 0; i < m_SpotLightCnt; i++) {
        m_SpotLights[i].CalcLocalDirectionAndPosition(meshWorldTransform);
    }
}

void G_Renderer::switchToLightingTech()
{
    GLint cur_prog = 0;
    glGetIntegerv(GL_CURRENT_PROGRAM, &cur_prog);

    if (cur_prog != m_LightingTech.GetProgram()) {
        m_LightingTech.Enable();
    }
}

void G_Renderer::switchToSkinningTech()
{
    GLint cur_prog = 0;
    glGetIntegerv(GL_CURRENT_PROGRAM, &cur_prog);

    if (cur_prog != m_SkinningTech.GetProgram()) {
        m_SkinningTech.Enable();
    }
}

void G_Renderer::renderBasicModel(BasicMesh& arg_basic_mseh)
{
    BasicCamera* camera = G_CameraMgr::getInstance().getCamera();

    switchToLightingTech();

    arg_basic_mseh.SetRotation(0.0f, 0.0f, 0.0f);
    arg_basic_mseh.SetPosition(0.0f, 0.0f, 0.0f);
    arg_basic_mseh.SetScale(1.0f);

    WorldTrans& modelMeshWorldTransform = arg_basic_mseh.GetWorldTransform();
    Matrix4f world = modelMeshWorldTransform.GetMatrix();
    Matrix4f view = camera->GetMatrix();
    Matrix4f projection = camera->GetProjectionMat();
    Matrix4f wvp = projection * view * world;

    m_LightingTech.SetWVP(wvp);
    m_LightingTech.SetMaterial(arg_basic_mseh.GetMaterial());
    m_LightingTech.SetPBR(false);
    Vector3f cameraLocalPos3f = arg_basic_mseh.GetWorldTransform().WorldPosToLocalPos(camera->GetPos());
    m_LightingTech.SetCameraLocalPos(cameraLocalPos3f);
    m_LightingTech.SetCameraWorldPos(camera->GetPos());
    m_LightingTech.SetWorldMatrix(world);

    arg_basic_mseh.Render();
}

void G_Renderer::renderSkinnedModel(SkinnedMesh& arg_skinned_mseh, const float& arg_t)
{
    BasicCamera* camera = G_CameraMgr::getInstance().getCamera();

    switchToSkinningTech();

    WorldTrans& worldTransform = arg_skinned_mseh.GetWorldTransform();
    worldTransform.SetRotation(90.0f, 180.0f, 0.0f);
    worldTransform.SetPosition(0.0f, 2.5f, 25.0f);
    worldTransform.SetScale(0.05f);

    Matrix4f world = worldTransform.GetMatrix();
    Matrix4f view = camera->GetMatrix();
    Matrix4f projection;
    projection.InitPersProjTransform(camera->GetPersProjInfo());
    Matrix4f wvp = projection * view * world;
    m_SkinningTech.SetWVP(wvp);

    refreshLightingPosAndDirs(arg_skinned_mseh);

    if (m_DirectionalLight.DiffuseIntensity > 0.0) {
        m_SkinningTech.UpdateDirLightDirection(m_DirectionalLight);
    }

    //m_SpotLights[0].WorldPosition = camera->GetPos();
    //m_SpotLights[0].WorldDirection = camera->GetTarget();
    //m_SpotLights[0].CalcLocalDirectionAndPosition(worldTransform);
    //m_SpotLights[1].WorldPosition = Vector3f(0.0f, 1.0f, 0.0f);
    //m_SpotLights[1].WorldDirection = Vector3f(0.0f, -1.0f, 0.0f);
    //m_SpotLights[1].CalcLocalDirectionAndPosition(worldTransform);
    //m_SkinningTech.SetSpotLights(2, m_SpotLights);

    //m_SkinningTech.UpdatePointLightsPos(m_PointLightCnt, m_PointLights);

    //m_SkinningTech.UpdateSpotLightsPosAndDir(m_SpotLightCnt, m_SpotLights);

    m_SkinningTech.SetMaterial(arg_skinned_mseh.GetMaterial());

    Vector3f cameraLocalPos3f = worldTransform.WorldPosToLocalPos(camera->GetPos());
    m_SkinningTech.SetCameraLocalPos(cameraLocalPos3f);

    vector<Matrix4f> Transforms;
    arg_skinned_mseh.GetBoneTransforms(arg_t, Transforms);

    for (uint i = 0; i < Transforms.size(); i++) {
        m_SkinningTech.SetBoneTransform(i, Transforms[i]);
    }

    arg_skinned_mseh.Render();
}
