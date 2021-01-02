//
// Created by adham on 02-Jan-21.
//

#ifndef GFX_LAB_SAMPLER_H
#define GFX_LAB_SAMPLER_H


#include "application.hpp"
#include "Shader.hpp"

namespace ShiEngine {
    class Sampler : public ShiEngine::Application {
    public:
        GLuint sampler;
        GLenum magnification_filter = GL_LINEAR;
        GLenum minification_filter = GL_LINEAR_MIPMAP_LINEAR;
        GLenum wrap_s = GL_REPEAT;
        GLenum wrap_t = GL_REPEAT;
        glm::vec4 border_color = {1,1,1,1};
        GLfloat max_anisotropy = 1.0f;
        GLenum polygon_mode = GL_LINE;

        void create();
        void destroy();

        void use(ShaderProgram* program);

        Sampler() { sampler = 0; }
        ~Sampler() { destroy(); }
    };
}

#endif //GFX_LAB_SAMPLER_H
