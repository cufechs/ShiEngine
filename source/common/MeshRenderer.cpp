#include "MeshRenderer.h"
#include "testComp.h"
#include "Camera.h"

#include <glm/gtx/string_cast.hpp>
ShiEngine::MeshRenderer::MeshRenderer() {

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

   // ShiEngine::Camera* cam = gameObject->GetComponent<ShiEngine::Camera>();

    shaderProgram->use();
    shaderProgram->set("tint", color_intensity);
    shaderProgram->set("transform", cam_era->getVPMatrix()*transformationMatrix );

    mesh->draw();
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);

    glClearColor(0, 0, 0, 1);

    shaderProgram->unuse(); //not sure if we should un use the program
}

void ShiEngine::MeshRenderer::setMesh(ShiEngine::Mesh* m) {
    mesh = m;
}

void ShiEngine::MeshRenderer::Start() {
    Enabled = true;
//    if (mesh == NULL) {
//        mesh = std::make_shared<Mesh>();
//    }
    //auto x = gameObject->GetComponent<Transform>();
}

void ShiEngine::MeshRenderer::setShader(ShiEngine::ShaderProgram *program) {
    shaderProgram = program;

}



void ShiEngine::MeshRenderer::setTransformationMatrix(glm::mat4 m) {
    transformationMatrix = m;
}

void ShiEngine::MeshRenderer::Update(double deltaTime) {
    //std::cout << "Mesh renderer update\n";
    //update transformation matrix
    //get transformation matrix from parent entity and update transformationMatrix
    transform = gameObject->GetComponent<ShiEngine::Transform>();
    setTransformationMatrix(transform->to_mat4());
    //std::cout << "Mesh renderer update after\n";
}

ShiEngine::MeshRenderer::MeshRenderer(ShiEngine::ShaderProgram *program) {
    Enabled = true;
    color_intensity = glm::vec4({1,1,1,1}); //pure color
    shaderProgram = program;
    transform_sent = true;
}

ShiEngine::MeshRenderer::MeshRenderer(ShiEngine::ShaderProgram *program, ShiEngine::Mesh *m) {
    Enabled = true;
    shaderProgram = program;
    mesh = m;
    color_intensity = glm::vec4({1,1,1,1}); //pure color
}





