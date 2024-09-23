#include "G_Renderer.h"


bool G_Renderer::init()
{
    //m_pBasicMesh = new BasicMesh();
    //m_pBasicMesh->LoadMesh("resource/assets/models/box/box.obj");
    //m_pBasicMesh->SetRotation(0.0f, 0.0f, 0.0f);
    //m_pBasicMesh->SetPosition(0.0f, 0.0f, 0.0f);
    //m_pBasicMesh->SetScale(1.0f);

    if (!m_LightingTech.Init(m_SubTech)) {
        printf("Error initializing the lighting technique\n");
        exit(1);
    }

    m_LightingTech.Enable();
    m_LightingTech.SetTextureUnit(COLOR_TEXTURE_UNIT_INDEX);
    m_LightingTech.SetAlbedoTextureUnit(ALBEDO_TEXTURE_UNIT_INDEX);
    m_LightingTech.SetRoughnessTextureUnit(ROUGHNESS_TEXTURE_UNIT_INDEX);
    m_LightingTech.SetMetallicTextureUnit(METALLIC_TEXTURE_UNIT_INDEX);
    m_LightingTech.SetNormalTextureUnit(NORMAL_TEXTURE_UNIT_INDEX);

    glUseProgram(0);

    return true;
}

void G_Renderer::SetDirectionalLight(const DirectionalLight& arg_dir_light)
{
    m_DirectionalLight = arg_dir_light;

    SwitchToLightingTech();
    m_LightingTech.SetDirectionalLight(m_DirectionalLight, false);
}

void G_Renderer::UpdateDirectionalLightDir(const Vector3f& arg_world_dir)
{
    m_DirectionalLight.WorldDirection = arg_world_dir;
}

void G_Renderer::render()
{
    SwitchToLightingTech();

    BasicMesh& b_mseh = G_ModelMgr::getInstance().getBasicModelTable(0);
    b_mseh.SetRotation(0.0f, 0.0f, 0.0f);
    b_mseh.SetPosition(0.0f, 0.0f, 0.0f);
    b_mseh.SetScale(1.0f);

    BasicCamera* camera = G_CameraMgr::getInstance().getCamera();
    WorldTrans& meshWorldTransform = b_mseh.GetWorldTransform();
    Matrix4f World = meshWorldTransform.GetMatrix();
    Matrix4f View = camera->GetMatrix();
    Matrix4f Projection = camera->GetProjectionMat();
    Matrix4f WVP = Projection * View * World;

    m_LightingTech.SetWVP(WVP);
    m_LightingTech.SetMaterial(b_mseh.GetMaterial());
    m_LightingTech.SetPBR(false);
    Vector3f CameraLocalPos3f = b_mseh.GetWorldTransform().WorldPosToLocalPos(camera->GetPos());
    m_LightingTech.SetCameraLocalPos(CameraLocalPos3f);
    m_LightingTech.SetCameraWorldPos(camera->GetPos());
    m_LightingTech.SetWorldMatrix(World);

    b_mseh.Render();

    //m_pBasicMesh->Render();
}

void G_Renderer::SwitchToLightingTech()
{
    GLint cur_prog = 0;
    glGetIntegerv(GL_CURRENT_PROGRAM, &cur_prog);

    if (cur_prog != m_LightingTech.GetProgram()) {
        m_LightingTech.Enable();
    }
}
