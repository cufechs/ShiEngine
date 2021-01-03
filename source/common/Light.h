#include "GameObjectComponent.h"
#include <glm/glm.hpp>

namespace ShiEngine {

    enum class LightType {
        DIRECTIONAL,
        POINT,
        SPOT
    };

    class Light : public ShiEngine::GameObjectComponent {
    private:
        // Here we define our light. First member specifies its type.
        LightType type;
        // We also define the color & intensity of the light for each component of the Phong model (Ambient, Diffuse, Specular).
        glm::vec3 diffuse, specular, ambient;
        //glm::vec3 position; // Used for Point and Spot Lights only
        //glm::vec3 direction; // Used for Directional and Spot Lights only
        // This affects how the light will dim out as we go further from the light.
        // The formula is light_received = light_emitted / (a*d^2 + b*d + c) where a, b, c are the quadratic, linear and constant factors respectively.
        struct {
            float constant, linear, quadratic;
        } attenuation; // Used for Point and Spot Lights only
        // This specifies the inner and outer cone of the spot light.
        // The light power is 0 outside the outer cone, the light power is full inside the inner cone.
        // The light power is interpolated in between the inner and outer cone.
        struct {
            float inner, outer;
        } spot_angle; // Used for Spot Lights only

        bool enabled;


    public:

        Light(LightType _type) {
            Type = ComponentType::Light;
            type = _type;

            diffuse = {1,1,1};
            specular = {1,1,1};
            ambient = {0.1f, 0.1f, 0.1f};
            attenuation = {0, 0, 1};
            spot_angle = {glm::pi<float>()/4, glm::pi<float>()/2};
            enabled = true;

        }

        ShiEngine::LightType getType() const { return type; }

        void setPhong(glm::vec3 _diffuse, glm::vec3 _specular, glm::vec3 _ambient) {
            diffuse = _diffuse;
            specular = _specular;
            ambient = _ambient;
        }

        void setAttenuation(float _constant, float _linear, float _quadratic) {
            attenuation.constant = _constant;
            attenuation.linear = _linear;
            attenuation.quadratic = _quadratic;
        }

        void setSpotAngle(float _inner, float _outer) {
            spot_angle.inner = _inner;
            spot_angle.outer = _outer;
        }


        float getAttenuationConstant() const { return attenuation.constant; }
        float getAttenuationLinear() const { return attenuation.linear; }
        float getAttenuationQuadratic() const { return attenuation.quadratic; }

        glm::vec3 getDiffuse() const { return diffuse; }
        glm::vec3 getSpecular() const { return specular; }
        glm::vec3 getAmbient() const { return ambient; }

        float getSpotAngleInner() const { return spot_angle.inner; }
        float getSpotAngleOuter() const { return spot_angle.outer; }


        void Enable() { enabled = true; }
        void Disable() { enabled = false; }
        bool isEnabled() const { return enabled; }

        void Start() override { }
        void Update(double deltaTime) override { }
        void Draw() override { }

    };


}