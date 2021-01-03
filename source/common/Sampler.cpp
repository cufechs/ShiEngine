//
// Created by adham on 02-Jan-21.
//

#include "Sampler.h"
#include <iostream>

void ShiEngine::Sampler::create() {
    glGenSamplers(1, &sampler);
}



void ShiEngine::Sampler::destroy() {
    glDeleteSamplers(1, &sampler);
}

void ShiEngine::Sampler::use(ShiEngine::ShaderProgram *program) {
    // To tell OpenGL which sampler object we will use for this unit, we bind the sampler to unit 0 (which is specified by the 1st parameter of the following function).
    std::cout << "sampler: " << sampler << "\n";
    glBindSampler(0, sampler);
    program->set("sampler", 0);

    // Now, instead of setting the parameters for each texture, we just set it to the sampler and each unit that uses that sampler will automatically use these parameters.
    glSamplerParameteri(sampler, GL_TEXTURE_MAG_FILTER, magnification_filter);
    glSamplerParameteri(sampler, GL_TEXTURE_MIN_FILTER, minification_filter);
    glSamplerParameteri(sampler, GL_TEXTURE_WRAP_S, wrap_s);
    glSamplerParameteri(sampler, GL_TEXTURE_WRAP_T, wrap_t);
    glSamplerParameterfv(sampler, GL_TEXTURE_BORDER_COLOR, glm::value_ptr(border_color));
    glSamplerParameterf(sampler, GL_TEXTURE_MAX_ANISOTROPY_EXT, max_anisotropy);

    glPolygonMode(GL_FRONT_AND_BACK, polygon_mode);
}
