//
// Created by teray on 1/3/2021.
#include <application.hpp>

#include <fstream>
#include <unordered_map>
#ifndef GFX_LAB_RENDERSTATE_H
#define GFX_LAB_RENDERSTATE_H



class RenderState {

private:
    bool transparent;
    float depth;
    bool enable_depth_test;
    GLenum depth_function;
    bool enable_face_culling;
    GLenum culled_face;
    GLenum front_face_winding;

    // These variables will control the blending
    bool enable_blending;
    GLenum blend_equation ;
    GLenum blend_source_factor;
    GLenum blend_destination_factor;
    glm::vec4 blend_constant_color;
public:

    RenderState()
    {
        depth_function = GL_LEQUAL;
        SetDepthTest();
        SetCulling();
        SetBlending();
    }
    RenderState(bool en_blend,bool en_depth,bool en_cull)
    {
        depth_function = GL_LEQUAL;

        SetDepthTest();
        SetCulling();
        SetBlending();

        IsBlending(en_blend);
        IsCulled(en_cull);
        IsDepthTest(en_depth);
    }

    void SetDepthTest()
    {
        if(enable_depth_test)
            glEnable(GL_DEPTH_TEST);
        else glDisable(GL_DEPTH_TEST);
        glDepthFunc(depth_function);
    }

    void IsDepthTest(bool depthtesting)
    {
        enable_depth_test = depthtesting;
    }

    void SetCulling()
    {
        culled_face = GL_BACK;
        front_face_winding = GL_CCW;

        if(enable_face_culling)
            glEnable(GL_CULL_FACE);
        else
            glDisable(GL_CULL_FACE);

        glCullFace(culled_face);
        glFrontFace(front_face_winding);
    }

    void IsCulled(bool culling)
    {
        enable_face_culling = culling;
    }
    void IsBlending(bool blending)
    {
        enable_blending = blending;
    }
    void SetBlending()
    {
        if(enable_blending)
            glEnable(GL_BLEND);
        else
            glDisable(GL_BLEND);

        blend_equation = GL_FUNC_ADD;
        blend_source_factor = GL_SRC_ALPHA;
        blend_destination_factor = GL_ONE_MINUS_SRC_ALPHA;
        blend_constant_color = {1.0f,1.0f,1.0f,1.0f};

        glBlendEquation(blend_equation);
        glBlendFunc(blend_source_factor, blend_destination_factor);
        // In case you're using any of the factors that use the constant color, you need to define it via the glBlendColor function.
        glBlendColor(blend_constant_color.r, blend_constant_color.g, blend_constant_color.b, blend_constant_color.a);
    }
};


#endif //GFX_LAB_RENDERSTATE_H