//
// Created by ossya on 12/24/2020.
//

#ifndef GFX_LAB_TEXTURE_UTILS_H
#define GFX_LAB_TEXTURE_UTILS_H

#include <data-types.h>

#include <glad/gl.h>
#include <glm/vec2.hpp>

#include <algorithm>

namespace ShiEngine::texture_utils {
    // Load an image from a file
    glm::ivec2 loadImage(GLuint texture, const char* filename, bool generate_mipmap = true);
    // Load an image from a file but read it as a grayscale image
    glm::ivec2 loadImageGrayscale(GLuint texture, const char* filename, bool generate_mipmap = true);

    void singleColor(GLuint texture, Color color={255,255,255,255}, glm::ivec2 size={1,1});

    void checkerBoard(GLuint texture, glm::ivec2 size, glm::ivec2 patternSize, ShiEngine::Color color1, ShiEngine::Color color2);
}
#endif //GFX_LAB_TEXTURE_UTILS_H