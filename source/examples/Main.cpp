#include <application.hpp>
#include <Shader.hpp>
#include "GameObject.h"
#include "MeshRenderer.h"
#include "testComp.h"
#include "Camera.h"
#include "CameraController.h"

// This exercise Window Application that derives from "Application" parent
class Main : public ShiEngine::Application {

    ShiEngine::ShaderProgram program;
    GLuint vertex_array = 0;
    ShiEngine::GameObject GO;
    ShiEngine::MeshRenderer* mesh;
    //ShiEngine:: comp_mesh;
    ShiEngine::GameObject obj1;

    ShiEngine::Transform* transform;
    ShiEngine::Camera* camera;
    //ShiEngine::Camera* camera;
    ShiEngine::FlyCameraController controller;
    //std::shared_ptr<ShiEngine::testComp> comp1;

    // This overriden function sets the window configuration params struct (title, size, isFullscreen).
    ShiEngine::WindowConfiguration getWindowConfiguration() override {
        return { "Engine", {1280, 720}, false };
    }



    // onInitialize() function is called once before the application loop
    void onInitialize() override {

       // std::cout << "name = " << typeid(ShiEngine::Transform).name() << std::endl;

        program.create("../assets/Shaders/Phase 1/transform.vert", GL_VERTEX_SHADER, "../assets/Shaders/Phase 1/tint.frag", GL_FRAGMENT_SHADER);

        ShiEngine::Transform* trans_for_mesh = new ShiEngine::Transform();
        transform = new ShiEngine::Transform();
        transform->position = glm::vec3({0, 0, 0});
        transform->scale = glm::vec3({5,5,5});
        transform->rotation = glm::vec3({0,0,0});

        glm::vec4 m = glm::vec4({1,1,1,1}); //responsible for the intensity of the color


        glm::mat4 trans = trans_for_mesh->to_mat4();

        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        camera = new ShiEngine::Camera();

       // std::cout<<"field of view, aspect_ratio, near, far "<<field_of_view_y << "space"<< aspect_ratio<< "space"<< near<< "space"<< far;
        //std::cout<<"hey";

        // camera->setEyePosition({10.f, 10.f, 10.f});
        //camera->setTarget({0.f, 0.f, 0.f});
        //camera->setUp({0, 1, 0});
        //camera->setupPerspective(glm::pi<float>()/2, static_cast<float>(width)/height, 0.1f, 100.0f);


//        mesh = std::make_shared<ShiEngine::MeshRenderer>(&program, trans);
        mesh = new ShiEngine::MeshRenderer(&program);
        mesh->Setcam(camera);
        controller.initialize(this, camera);
        mesh->Primitives(ShiEngine::Cube3D, true);

        //comp_mesh = mesh;
        //comp1 = std::make_shared<ShiEngine::testComp>();

        //obj1.AddComponent(comp1);
        obj1.AddComponent(transform);
        obj1.AddComponent(camera);
       // obj1.AddComponent(Cameraconrtoller);
      //  obj2.AddComponent(transform);
        obj1.AddComponent(mesh);

        //obj1.AddComponent(comp_mesh);
        //obj1.AddComponent(comp1);

        //glGenVertexArrays(1, &vertex_array);

        //glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

        obj1.Start();

        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);

        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
        glFrontFace(GL_CCW);

        glClearColor(0, 0, 0, 1);
    }

    //void onImmediateGui(ImGuiIO &io) override {
    //    // Shows a metric window just as an example of ImGui operations
    //    ImGui::ShowMetricsWindow();
    //}

    void onUpdate(double deltaTime) override {
        //Here you write all your game logic
        controller.Update(deltaTime);
        obj1.Update(deltaTime);

    }

	void onDraw() override {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        obj1.Draw();

	}

};

// Example Entry point
int main(int argc, char** argv) {
    
    // Creates an instance of EmptyWindowApplication and call run on this instance
    return Main().run();
}
