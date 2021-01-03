#include "MeshRenderer.h"
#include "testComp.h"
#include "Camera.h"

#include <glm/gtx/string_cast.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/glm.hpp>
#include <glm/geometric.hpp>
#include "GameState.h"
#include "Globals/Global_vars.h"

ShiEngine::MeshRenderer::MeshRenderer() {

    Type = ComponentType::MeshRenderer;
    Enabled = true;
    color_intensity = glm::vec4({1,1,1,1}); //pure color
    //transform = gameObject->GetComponent<Transform>();
    //setTransformationMatrix(transform->to_mat4());
    //transform = gameObject->GetComponent<Transform>();
    transform_sent = false;

}

void ShiEngine::MeshRenderer:: Setcam(Camera *cam)
{
    cam_era=cam;
}

ShiEngine::MeshRenderer::~MeshRenderer() {
    //delete mesh;
    if (mesh != NULL) {
        destroy();
        mesh = nullptr;
    }
    Enabled = false;
}

void ShiEngine::MeshRenderer::Primitives(ShiEngine::Shapes3D shape, bool colored) {
    if (shape == ShiEngine::Sphere3D) {
        mesh->Sphere(colored);
    } else if (shape == ShiEngine::Cube3D) {
        mesh->Cuboid(colored);
    } else if (shape == ShiEngine::Plane3D) {
        mesh->Plane(colored);
    }


}

void ShiEngine::MeshRenderer::destroy() {
    mesh->destroy();
    Enabled = false;
}

void ShiEngine::MeshRenderer::Draw() {


    shaderProgram->use();

    //material = static_cast<ShiEngine::Material*>(gameObject->GetComponent(ComponentType::Material));
    if (material->texture != NULL) {
        shaderProgram = material->shaderProgram;
        //material->sampler->use(ShiEngine::Global::Global_ShaderProgram); //ShaderProgram's"sampler" uniform is set inside this function
        material->texture->Draw(); //bind the texture
        shaderProgram->set("sampler", 0);
    }

    shaderProgram->set("tint", color_intensity);
    shaderProgram->set("material.albedo_tint", material->albedo_tint);
    shaderProgram->set("material.specular_tint", material->specular_tint);
    shaderProgram->set("material.roughness_range", material->roughness_range);
    shaderProgram->set("material.emissive_tint", material->emissive_tint);

    // TODO: add a skybox, set initially with zeros
    shaderProgram->set("sky_light.top_color", glm::vec3(0.0f));
    shaderProgram->set("sky_light.middle_color", glm::vec3(0.0f));
    shaderProgram->set("sky_light.bottom_color", glm::vec3(0.0f));


    shaderProgram->set("camera_position", cam_era->getEyePosition());
    shaderProgram->set("view_projection", cam_era->getVPMatrix());

    shaderProgram->set("object_to_world", transformationMatrix);
    shaderProgram->set("object_to_world_inv_transpose", glm::inverse(transformationMatrix), true);

//    shaderProgram->set("material.diffuse", material->diffuse);
//    shaderProgram->set("material.specular", material->specular);
//    shaderProgram->set("material.ambient", material->ambient);
//    shaderProgram->set("material.shininess", material->shininess);


   // We will go through all the lights and send the enabled ones to the shader.
    int light_index = 0;
    const int MAX_LIGHT_COUNT = 16;
    for(const auto light : lights) {
        if(!light->isEnabled()) continue;

        std::string prefix = "lights[" + std::to_string(light_index) + "].";


        shaderProgram->set(prefix + "type", static_cast<int>(light->getType()));
        shaderProgram->set(prefix + "color", light->color);

        switch (light->getType()) {
            case LightType::DIRECTIONAL:
                shaderProgram->set(prefix + "direction", glm::normalize(lightTransforms[light_index]->direction));
                break;
            case LightType::POINT:
                shaderProgram->set(prefix + "position", lightTransforms[light_index]->position);
                shaderProgram->set(prefix + "attenuation_constant", light->getAttenuationConstant());
                shaderProgram->set(prefix + "attenuation_linear", light->getAttenuationLinear());
                shaderProgram->set(prefix + "attenuation_quadratic", light->getAttenuationQuadratic());
                break;
            case LightType::SPOT:
                shaderProgram->set(prefix + "position", lightTransforms[light_index]->position);
                shaderProgram->set(prefix + "direction", glm::normalize(lightTransforms[light_index]->direction));
                shaderProgram->set(prefix + "attenuation_constant", light->getAttenuationConstant());
                shaderProgram->set(prefix + "attenuation_linear", light->getAttenuationLinear());
                shaderProgram->set(prefix + "attenuation_quadratic", light->getAttenuationQuadratic());
                shaderProgram->set(prefix + "inner_angle", light->getSpotAngleInner());
                shaderProgram->set(prefix + "outer_angle", light->getSpotAngleOuter());
                break;
        }
        light_index++;
        if(light_index >= MAX_LIGHT_COUNT) break;
    }
    // Since the light array in the shader has a constant size, we need to tell the shader how many lights we sent.
    shaderProgram->set("light_count", light_index);


    mesh->draw();


    //renderState->SetBlending();

//    glEnable(GL_DEPTH_TEST);
//    glDepthFunc(GL_LEQUAL);
//
//    glEnable(GL_CULL_FACE);
//    glCullFace(GL_BACK);
//    glFrontFace(GL_CCW);

    glClearColor(0, 0, 0, 1);

    shaderProgram->unuse(); //not sure if we should un use the program
}

void ShiEngine::MeshRenderer::setMesh(ShiEngine::Mesh* m) {
    mesh = m;
}

void ShiEngine::MeshRenderer::Start() {
    Enabled = true;
    transform = (Transform*)gameObject->GetComponent(ComponentType::Transform);

    std::vector<ShiEngine::GameObject*> gameObject_vec = GameState::getGameObjects();

    for (auto _gameObj : gameObject_vec) {

        if (_gameObj->Tag == ShiEngine::Tags::LIGHT ) {

            ShiEngine::Transform* transformLight = static_cast<ShiEngine::Transform*>(_gameObj->GetComponent(ComponentType::Transform));
            ShiEngine::Light* lightComponent = static_cast<ShiEngine::Light*>(_gameObj->GetComponent(ComponentType::Light));
            this->SetLight(lightComponent, transformLight);
        } else if(_gameObj->Tag == ShiEngine::Tags::CAMERA) {
            ShiEngine::Camera* _camera = static_cast<ShiEngine::Camera*>(_gameObj->GetComponent(ComponentType::Camera));
            this->Setcam(_camera);
        }

    }



}

void ShiEngine::MeshRenderer::setShader(ShiEngine::ShaderProgram *program) {
    shaderProgram = program;

}



void ShiEngine::MeshRenderer::setTransformationMatrix(glm::mat4 m) {
    transformationMatrix = transform->to_mat4();
}

void ShiEngine::MeshRenderer::Update(double deltaTime) {
    //std::cout << "Mesh renderer update\n";
    //update transformation matrix
    //get transformation matrix from parent entity and update transformationMatrix
    //std::cout << "Mesh renderer update after\n";
    transformationMatrix = transform->to_mat4();
}

ShiEngine::MeshRenderer::MeshRenderer(ShiEngine::ShaderProgram *program) {
    Type = ComponentType::MeshRenderer;
    Enabled = true;
    color_intensity = glm::vec4({1,1,1,1}); //pure color
    shaderProgram = program;
    transform_sent = true;
}

ShiEngine::MeshRenderer::MeshRenderer(ShiEngine::ShaderProgram *program, ShiEngine::Mesh *m) {
    Type = ComponentType::MeshRenderer;
    Enabled = true;
    shaderProgram = program;
    mesh = m;
    color_intensity = glm::vec4({1,1,1,1}); //pure color
}


void ShiEngine::MeshRenderer::SetLight(ShiEngine::Light *_light) {
    lights.push_back(_light);
}

void ShiEngine::MeshRenderer::SetLight(ShiEngine::Light *_light, ShiEngine::Transform *_transformLight) {
    lights.push_back(_light);
    lightTransforms.push_back(_transformLight);
}

void ShiEngine::MeshRenderer::SetMaterial(Material* _material) {
    material = _material;
}

void ShiEngine::MeshRenderer::SetRenderState(RenderState *_renderState) {
    renderState = _renderState;
}







