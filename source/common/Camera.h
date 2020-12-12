#include <application.hpp>
#include <shader.hpp>
#include <imgui-utils/utils.hpp>
#include "GameObjectComponent.h"
//#include "GameObject.h"
#include <glm/gtx/euler_angles.hpp>
//#include "Transform.h"

#ifndef OUR_CAMERA_HPP
#define OUR_CAMERA_HPP
#include <glm/gtx/string_cast.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
//#include "Transform.h"
#include "GameObject.h"
#include "Transform.h"
#include <glm/gtx/io.hpp>

namespace ShiEngine {

    // An enum for the camera projection type
    enum struct CameraType {
        Orthographic,
        Perspective
    };
    // A class that represents a camera
    // Used to generate a view and a projection matrix
    class Camera : public ShiEngine::GameObjectComponent{
    private:

        glm::vec3 eye = {0, 0, 0}, direction = {0, 0, -1}, up = {0, 1, 0};

        float field_of_view_y = glm::radians(90.0f), orthographic_height = 2.0f, aspect_ratio = 1.0f, near = 0.01f, far = 100.0f;

        glm::mat4 V{}, P{}, VP{};

        CameraType type = CameraType::Perspective;

        ShiEngine::Transform* transform;

    public:



        Camera(){
            up = {0, 1, 0};
            eye = {0, 0, 0};
            direction = {0, 0, -1};
            field_of_view_y = glm::radians(90.0f);
            aspect_ratio = 1.0f;
            near = 0.01;
            far = 100.0f;

            Type = ComponentType::Camera;
        }

        // Setup the camera as a perspective camera
        void setupPerspective(float field_of_view_y, float aspect_ratio, float near, float far){
            this->field_of_view_y = field_of_view_y;
            this->aspect_ratio = aspect_ratio;
            this->near = near;
            this->far = far;
        }


        void setVerticalFieldOfView(float field_of_view_y){
            if(this->field_of_view_y != field_of_view_y){
                this->field_of_view_y = field_of_view_y;
            }
        }
        void setAspectRatio(float aspect_ratio){
            if(this->aspect_ratio != aspect_ratio){
                this->aspect_ratio = aspect_ratio;
            }
        }
        void setNearPlane(float near){
            if(this->near != near){
                this->near = near;
            }
        }
        void setFarPlane(float far){
            if(this->far != far){

                this->far = far;
            }
        }
        void setEyePosition(glm::vec3 eye){
            if(this->eye != eye){
                this->eye = eye;
            }
        }
        void setDirection(glm::vec3 direction){
            if(this->direction != direction){
                this->direction = direction;
            }
        }
        void setTarget(glm::vec3 target){
            glm::vec3 direction = target - eye;
            if(this->direction != direction){

                this->direction = direction;
            }
        }
        void setUp(glm::vec3 up){
            if(this->up != up){

                this->up = up;
            }
        }

        void setTransform() {
            transform = (Transform*)gameObject->GetComponent(ComponentType::Transform);

            this->setEyePosition(transform->to_mat4()*glm::vec4(0,0,0,1));
            this->setTarget(glm::vec3(0,0,0));
            this->setUp(transform->to_mat4()*glm::vec4(0,1,0,0));
        }

        glm::mat4 getProjectionMatrix(){

            if (type == CameraType::Perspective) {
                P = glm::perspective(field_of_view_y, aspect_ratio, near, far);
            } else {
                float half_height = orthographic_height * 0.5f;
                float half_width = aspect_ratio * half_height;
                P = glm::ortho(-half_width, half_width, -half_height, half_height, near, far);
            }

            //std::cout<<"field of view, aspect_ratio, near, far "<<field_of_view_y << "space"<< aspect_ratio<< "space"<< near<< "space"<< far;
            return P;
        }

        glm::mat4 getViewMatrix(){

                V = glm::lookAt(eye, eye + direction, up);

            return V;
        }

        glm::mat4 getVPMatrix(){

                VP = getProjectionMatrix() * getViewMatrix();
                // Note that we called the functions getProjectionMatrix & getViewMatrix instead of directly using V & P
                // to make sure that they are not outdated


            return VP;
        }

        [[nodiscard]] float getVerticalFieldOfView() const {return field_of_view_y;}
        [[nodiscard]] float getHorizontalFieldOfView() const {return field_of_view_y * aspect_ratio;}
        [[nodiscard]] float getOrthographicHeight() const {return orthographic_height;}
        [[nodiscard]] float getOrthographicWidth() const {return orthographic_height * aspect_ratio;}
        [[nodiscard]] float getAspectRatio() const {return aspect_ratio;}
        [[nodiscard]] float getNearPlane() const {return near;}
        [[nodiscard]] float getFarPlane() const {return far;}
        [[nodiscard]] glm::vec3 getEyePosition() const {return eye;}
        [[nodiscard]] glm::vec3 getDirection() const {return direction;}
        [[nodiscard]] glm::vec3 getOriginalUp() const {return up;}

        // Get the directions of the camera coordinates in the world space
        glm::vec3 Right(){
            getViewMatrix();
            return {V[0][0],V[1][0],V[2][0]};
        }
        glm::vec3 Left(){
            getViewMatrix();
            return {-V[0][0],-V[1][0],-V[2][0]};
        }
        glm::vec3 Up(){
            getViewMatrix();
            return {V[0][1],V[1][1],V[2][1]};
        }
        glm::vec3 Down(){
            getViewMatrix();
            return {-V[0][1],-V[1][1],-V[2][1]};
        }
        glm::vec3 Forward(){
            getViewMatrix();
            return {-V[0][2],-V[1][2],-V[2][2]};
        }
        glm::vec3 Backward(){
            getViewMatrix();
            return {V[0][2],V[1][2],V[2][2]};
        }

        // Transform point from world space to normalized device coordinates
        glm::vec3 fromWorldToDeviceSpace(glm::vec3 world){
            glm::vec4 clip = getVPMatrix() * glm::vec4(world, 1.0f);
            return glm::vec3(clip)/clip.w;
            // Note that we must divide by w. This is because of the projection matrix.
        }

        // Transform point from normalized device coordinates to world space
        glm::vec3 fromDeviceToWorldSpace(glm::vec3 device){
            glm::vec4 clip = glm::inverse(getVPMatrix()) * glm::vec4(device, 1.0f);
            return glm::vec3(clip)/clip.w;
            // Note that we must divide by w even though we not going to the NDC space. This is because of the projection matrix.
        }

        void setupOrthographic(float orthographic_height, float aspect_ratio, float near, float far){
            this->type = CameraType::Orthographic;
            this->orthographic_height = orthographic_height;
            this->aspect_ratio = aspect_ratio;
            this->near = near;
            this->far = far;
        }


        void Start() override {
            setTransform();
        }

    };

}

#endif //OUR_CAMERA_HPP
