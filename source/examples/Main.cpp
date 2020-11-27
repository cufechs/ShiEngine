#include <application.hpp>
#include <Shader.hpp>

// This exercise Window Application that derives from "Application" parent
class Main : public ShiEngine::Application {

    ShiEngine::ShaderProgram program;
    GLuint vertex_array = 0;

    // This overriden function sets the window configuration params struct (title, size, isFullscreen).
    ShiEngine::WindowConfiguration getWindowConfiguration() override {
        return { "Engine", {1280, 720}, false };
    }

    // onInitialize() function is called once before the application loop
    void onInitialize() override {
        program.create();
        program.attach("../assets/Shaders/Phase 1/triangle.vert", GL_VERTEX_SHADER);
        program.attach("../assets/Shaders/Phase 1/Smile_1.frag", GL_FRAGMENT_SHADER);
        program.link();

        glGenVertexArrays(1, &vertex_array);

        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    }

    //void onImmediateGui(ImGuiIO &io) override {
    //    // Shows a metric window just as an example of ImGui operations
    //    ImGui::ShowMetricsWindow();
    //}

    // onDraw(deltaTime) function is called every frame 
    void onUpdate(double deltaTime) override {
        //Here you write all your game logic

    }

	void onDraw() override {
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(program);

        if(keyboard.justPressed(GLFW_KEY_KP_1))
        {
            program.create();
            program.attach("../assets/Shaders/Phase 1/triangle.vert", GL_VERTEX_SHADER);
            program.attach("../assets/Shaders/Phase 1/Smile_1.frag", GL_FRAGMENT_SHADER);
            program.link();

            glGenVertexArrays(1, &vertex_array);

            glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        }
        else if(keyboard.justPressed(GLFW_KEY_KP_2))
        {
            program.create();
            program.attach("../assets/Shaders/Phase 1/triangle.vert", GL_VERTEX_SHADER);
            program.attach("../assets/Shaders/Phase 1/Heart_2.frag", GL_FRAGMENT_SHADER);
            program.link();

            glGenVertexArrays(1, &vertex_array);

            glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        }
        else if(keyboard.justPressed(GLFW_KEY_KP_3))
        {
            program.create();
            program.attach("../assets/Shaders/Phase 1/triangle.vert", GL_VERTEX_SHADER);
            program.attach("../assets/Shaders/Phase 1/PacMan_3.frag", GL_FRAGMENT_SHADER);
            program.link();

            glGenVertexArrays(1, &vertex_array);

            glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        }
        else if(keyboard.justPressed(GLFW_KEY_KP_4))
        {
            program.create();
            program.attach("../assets/Shaders/Phase 1/triangle.vert", GL_VERTEX_SHADER);
            program.attach("../assets/Shaders/Phase 1/Shape_4.frag", GL_FRAGMENT_SHADER);
            program.link();

            glGenVertexArrays(1, &vertex_array);

            glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        }

        GLuint scale_uniform_location = glGetUniformLocation(program, "MousePos");
        glUniform2f(scale_uniform_location, mouse.getMousePosition().x, getWindowSize().y-mouse.getMousePosition().y);

        GLuint scale_uniform_location2 = glGetUniformLocation(program, "mousepos");
        glUniform2f(scale_uniform_location2, mouse.getMousePosition().x/1280, -mouse.getMousePosition().y/720);

        GLuint scale_uniform_location3 = glGetUniformLocation(program, "u_resolution");
        glUniform2f(scale_uniform_location3, getWindowSize().x, getWindowSize().y);

        glBindVertexArray(vertex_array);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);
	}

};

// Example Entry point
int main(int argc, char** argv) {
    
    // Creates an instance of EmptyWindowApplication and call run on this instance

    return Main().run();
}
