//
// Created by ossya on 12/31/2020.
//

#ifndef GFX_LAB_TEXTURE2D_H
#define GFX_LAB_TEXTURE2D_H

#include "texture-utils.h"
#include <iostream>

namespace ShiEngine {

    static GLuint textureUnit = 0;

    class Texture2D {
    private:
        GLuint texture;
        //GLuint _textureUnit;
    public:
        int MipMapLevel;
        GLuint _textureUnit;
        Texture2D();

        Texture2D(const char *FilePath);

        Texture2D(const char *FilePath, bool GenerateMipMaps = true);

        Texture2D(const char *FilePath, GLuint texUnit, bool GenerateMipMaps = true);

        ~Texture2D() {
            std::cout <<"destructed\n";
            textureUnit--;
            glDeleteTextures(1, &texture);
        }

        Texture2D(Texture2D const &) = delete;
        Texture2D &operator=(Texture2D const &) = delete;

        void Draw();

        GLuint getTextureUnit() const { return _textureUnit; }

        void LoadTexture(const char *FilePath, bool GenerateMipMaps = true);

        void GenerateTexture(ShiEngine::Color color = {255, 255, 255, 255}, glm::ivec2 size = {1, 1});
    };
}

#endif //GFX_LAB_TEXTURE2D_H
