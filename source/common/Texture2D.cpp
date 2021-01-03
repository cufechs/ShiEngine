//
// Created by ossya on 12/31/2020.
//

#include "Texture2D.h"

namespace ShiEngine {
    Texture2D::Texture2D() {
        glGenTextures(1, &texture);
        uint8_t pixel_data[] = {
                255,   0,   0, 255,
                0, 255,   0, 255,
                0,   0, 255, 255,
                255, 255,   0, 255,
        };
        // To work with our texture as a 2D texture, we bind it to GL_TEXTURE_2D.
        glBindTexture(GL_TEXTURE_2D, texture);
        // In this function, we tell OpenGL how our data is aligned. This will be used when OpenGL transfers our data from the RAM to the VRAM.
        // Here we wrote that the row alignment is 4 bytes which means that each row starts at an offset that is multiple of 4 bytes.
        // This is always true for any tightly-packed texture data that has 4 components (RGBA) since each row will always be multiple of 4 bytes.
        // However, we can also use 2 or 1 and it would be correct. Actually, there is no advantage of using 4 here.
        // However, 8 will fail if we only have 1 pixel per row (or any odd number of pixels per row).
        // As a general rule, any texture data that is tightly-packed (has no padding between rows) can use an unpack alignment of 1.
        // We only need other values such as 2, 4 or 8 if we have padding between rows.
        // Possible values for this setting is 1, 2, 4 and 8. The default value is 4.
        glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
        // This function sends texture data from the RAM to the VRAM.
        // Parameters:
        // target (GLenum): The texture to which we should send the data. We pick GL_TEXTURE_2D since we will send it to the texture bound to GL_TEXTURE_2D.
        // level (GLint): The mip level in which this data should be stored. Since this data for the texture at its original size, we send it to mip level 0.
        // internalformat (GLint): The format in which the texture data will be stored in the VRAM. Since we have 4 channels (8 bits each) , we will store it as GL_RGBA8.
        // width, height (GLsizei): the width and height of the texture in pixels. Here we picked 2x2 so the data will be stored as 2 rows where each row contains 2 pixels.
        // border (GLint): This does nothing and it must be 0. In old OpenGL, this was used to indicate whether the texture would have a border or not.
        // format (GLenum): this is the format of the data as it is stored in the array "data" on the RAM. Since we have 4 components, we use GL_RGBA.
        // type (GLenum): this is the data type of each component in the array "data" on the RAM. We stored it as uint8 so we pick GL_UNSIGNED_BYTE.
        // data (const void*): this is the pointer to the data on the RAM. The function will read data from this location and send it to the GPU.
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, 2, 2, 0, GL_RGB, GL_UNSIGNED_BYTE, pixel_data);
        // This function will generate the mip map for the texture. It will automatically generate all the mip level till we reach a mip level whose size is 1x1 pixel.
        // The mip levels are generate by averaging each 2x2 pixels into 1 pixel in the higher level.
        // Therefore, if mip level (i) has a size WxH, then mip level (i+1) will have a size floor(W/2) x floor(H/2).
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    Texture2D::Texture2D(const char* FilePath) {
        glGenTextures(1, &texture);
        ShiEngine::texture_utils::loadImage(texture, FilePath);
    }

    Texture2D::Texture2D(const char* FilePath, bool GenerateMipMap) {
        glGenTextures(1, &texture);
        ShiEngine::texture_utils::loadImage(texture, FilePath, GenerateMipMap);
    }

    void Texture2D::Draw() {
        glActiveTexture(GL_TEXTURE0);
        // When we bind the texture, we also bind it to the active unit. So this texture is now bound to unit 0.
        glBindTexture(GL_TEXTURE_2D, texture);
    }

    void Texture2D::GenerateTexture(ShiEngine::Color color, glm::ivec2 size) {
        ShiEngine::texture_utils::singleColor(texture, color, size);
    }
}