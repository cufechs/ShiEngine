#include <application.hpp>
#include <Shader.hpp>
#include "GameObject.h"
#include "MeshRenderer.h"
#include "testComp.h"

// This exercise Window Application that derives from "Application" parent
class Main : public ShiEngine::Application {

    ShiEngine::ShaderProgram program;
    GLuint vertex_array = 0;
    ShiEngine::GameObject GO;
    ShiEngine::MeshRenderer* mesh;
    //ShiEngine:: comp_mesh;
    ShiEngine::GameObject obj1;

    ShiEngine::Transform* transform;

    //std::shared_ptr<ShiEngine::testComp> comp1;

    // This overriden function sets the window configuration params struct (title, size, isFullscreen).
    ShiEngine::WindowConfiguration getWindowConfiguration() override {
        return { "Engine", {1280, 720}, false };
    }



    // onInitialize() function is called once before the application loop
    void onInitialize() override {
//        if (typeid(ShiEngine::GameObjectComponent) == typeid(ShiEngine::MeshRenderer))
//            std::cout << "yes  "  << std::endl;
//        else std::cout << "No\n";

        program.create("../assets/Shaders/Phase 1/transform.vert", GL_VERTEX_SHADER, "../assets/Shaders/Phase 1/tint.frag", GL_FRAGMENT_SHADER);

        ShiEngine::Transform* trans_for_mesh = new ShiEngine::Transform();
        transform = new ShiEngine::Transform();
        transform->position = glm::vec3({0, 0, 0});
        transform->scale = glm::vec3({0.2,0.2,0.2});
        transform->rotation = glm::vec3({30,30,10});

        glm::vec4 m = glm::vec4({1,1,1,1}); //responsible for the intensity of the color


        glm::mat4 trans = trans_for_mesh->to_mat4();

//        mesh = std::make_shared<ShiEngine::MeshRenderer>(&program, trans);
        mesh = new ShiEngine::MeshRenderer(&program);
        mesh->Primitives(ShiEngine::Sphere3D, true);

        //comp_mesh = mesh;
        //comp1 = std::make_shared<ShiEngine::testComp>();

        //obj1.AddComponent(comp1);
        obj1.AddComponent(transform);
        obj1.AddComponent(mesh);
        //obj1.AddComponent(comp_mesh);
        //obj1.AddComponent(comp1);

        //glGenVertexArrays(1, &vertex_array);

        //glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

        obj1.Start();

    }

    //void onImmediateGui(ImGuiIO &io) override {
    //    // Shows a metric window just as an example of ImGui operations
    //    ImGui::ShowMetricsWindow();
    //}

    void onUpdate(double deltaTime) override {
        //Here you write all your game logic
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
