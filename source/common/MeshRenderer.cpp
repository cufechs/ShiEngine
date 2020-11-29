#include "MeshRenderer.h"
#include "testComp.h"


ShiEngine::MeshRenderer::MeshRenderer() {

    Enabled = true;
    mesh = std::make_shared<ShiEngine::Mesh>();
    color_intensity = glm::vec4({1,1,1,1}); //pure color
    //transform = gameObject->GetComponent<Transform>();
    //setTransformationMatrix(transform->to_mat4());
    //transform = gameObject->GetComponent<Transform>();
    transform_sent = false;
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

//    if (transform_sent) {
//        //auto& x = gameObject->GetComponent<ShiEngine::Transform>();
//        transform = gameObject->GetComponent<ShiEngine::Transform>();
//        setTransformationMatrix(transform.to_mat4());
//    }


    std::cout << "Mesh renderer draw before\n";

    shaderProgram->use();
    shaderProgram->set("tint", color_intensity);
    shaderProgram->set("transform", transformationMatrix);
    mesh->draw();
    shaderProgram->unuse(); //not sure if we should un use the program
    std::cout << "Mesh renderer draw\n";
}

void ShiEngine::MeshRenderer::setMesh(std::shared_ptr<Mesh> m) {
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

ShiEngine::MeshRenderer::MeshRenderer(ShiEngine::ShaderProgram *program, glm::mat4 m) : shaderProgram(program) {
    Enabled = true;
    mesh = std::make_shared<Mesh>();
    color_intensity = glm::vec4({1,1,1,1}); //pure color
    setTransformationMatrix(m);
    std::cout << "Mesh renderer created\n";
    transform_sent = false;
}

void ShiEngine::MeshRenderer::setTransformationMatrix(glm::mat4 m) {
    transformationMatrix = m;
}

void ShiEngine::MeshRenderer::Update(double deltaTime) {
    std::cout << "Mesh renderer update\n";
    //update transformation matrix
    //get transformation matrix from parent entity and update transformationMatrix
    transform = gameObject->GetComponent<ShiEngine::Transform>();
    setTransformationMatrix(transform->to_mat4());
    std::cout << "Mesh renderer update after\n";
}

ShiEngine::MeshRenderer::MeshRenderer(ShiEngine::ShaderProgram *program) {
    Enabled = true;
    //mesh = std::make_shared<Mesh>();
    mesh = std::make_shared<ShiEngine::Mesh>();
    color_intensity = glm::vec4({1,1,1,1}); //pure color
    shaderProgram = program;
    //transform = gameObject->GetComponent<Transform>();
    //setTransformationMatrix(transform.to_mat4());
    transform_sent = true;
    std::cout << "I am here\n";
}

ShiEngine::MeshRenderer::MeshRenderer(ShiEngine::ShaderProgram *program, ShiEngine::Mesh *m) {
    shaderProgram = program;
    //mesh = std::shared_ptr<ShiEngine::Mesh>m;
    std::shared_ptr<Mesh> m1(m);
    mesh = m1;
}

//template<typename... T>
//void ShiEngine::MeshRenderer::Update(double deltaTime, T &&... arguments) {
//    //This is done just if we were to take the transformation matrix from outside
//    setTransformationMatrix(std::forward<T>(arguments)... );
//
//}



