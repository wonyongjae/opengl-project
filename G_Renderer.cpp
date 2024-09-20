#include "G_Renderer.h"


bool G_Renderer::init()
{
    m_pBasicMesh = new BasicMesh();
    m_pBasicMesh->LoadMesh("resource/assets/models/box/box.obj");
    m_pBasicMesh->SetRotation(0.0f, 0.0f, 0.0f);
    m_pBasicMesh->SetPosition(0.0f, 0.0f, 0.0f);
    m_pBasicMesh->SetScale(1.0f);

    if (!m_lightingTech.Init(m_subTech)) {
        printf("Error initializing the lighting technique\n");
        exit(1);
    }

    m_lightingTech.Enable();
    m_lightingTech.SetTextureUnit(COLOR_TEXTURE_UNIT_INDEX);
    m_lightingTech.SetAlbedoTextureUnit(ALBEDO_TEXTURE_UNIT_INDEX);
    m_lightingTech.SetRoughnessTextureUnit(ROUGHNESS_TEXTURE_UNIT_INDEX);
    m_lightingTech.SetMetallicTextureUnit(METALLIC_TEXTURE_UNIT_INDEX);
    m_lightingTech.SetNormalTextureUnit(NORMAL_TEXTURE_UNIT_INDEX);

    glUseProgram(0);

    return true;
}

void G_Renderer::render()
{
    SwitchToLightingTech();

    BasicCamera* camera = G_CameraMgr::getInstance().getCamera();
    WorldTrans& meshWorldTransform = m_pBasicMesh->GetWorldTransform();
    Matrix4f World = meshWorldTransform.GetMatrix();
    Matrix4f View = camera->GetMatrix();
    Matrix4f Projection = camera->GetProjectionMat();
    Matrix4f WVP = Projection * View * World;

    m_lightingTech.SetWVP(WVP);
    m_lightingTech.SetMaterial(m_pBasicMesh->GetMaterial());
    m_lightingTech.SetPBR(false);
    Vector3f CameraLocalPos3f = m_pBasicMesh->GetWorldTransform().WorldPosToLocalPos(camera->GetPos());
    m_lightingTech.SetCameraLocalPos(CameraLocalPos3f);
    m_lightingTech.SetCameraWorldPos(camera->GetPos());
    m_lightingTech.SetWorldMatrix(World);

    m_pBasicMesh->Render();
}

void G_Renderer::SwitchToLightingTech()
{
    GLint cur_prog = 0;
    glGetIntegerv(GL_CURRENT_PROGRAM, &cur_prog);

    if (cur_prog != m_lightingTech.GetProgram()) {
        m_lightingTech.Enable();
    }
}
