//#include "GameObjectComponent.h"
#include "GameObject.h"
#include <glm/glm.hpp>
#include "Transform.h"

namespace ShiEngine {

    class EnemyMovement : public ShiEngine::GameObjectComponent {
    private:
        //float speed;
        bool followPlayer;
        glm::vec3 followDirection;
        glm::vec3 speed;
        glm::vec3 increment;
        Transform* transform;
        float x_increment, x_oscill_dist; // oscillation on x-axes
        float y_increment, y_oscill_dist; // oscillation on y-axes
        float z_increment, z_oscill_dist; // oscillation on z-axes
        glm::vec3 origin_pos;
    public:
        EnemyMovement() {
            Type = ComponentType::EnemyMove;
            x_increment = 0.0;
            y_increment = 0.0;
            z_increment = 0.0;
            x_oscill_dist = 0.0;
            y_oscill_dist = 0.0;
            z_oscill_dist = 0.0;
        }


        void setOscillateX(float dist=0, float incr=0) {
            x_increment = incr;
            x_oscill_dist = dist;
        }

        void setOscillateY(float dist=0, float incr=0) {
            y_increment = incr;
            y_oscill_dist = dist;
        }

        void setOscillateZ(float dist=0, float incr=0) {
            z_increment = incr;
            z_oscill_dist = dist;
        }



        void Start() override {
            transform = static_cast<ShiEngine::Transform*>(gameObject->GetComponent(ComponentType::Transform));
            origin_pos.x = transform->position.x;
            origin_pos.y = transform->position.y;
            origin_pos.z = transform->position.z;
        }

        void Update(double deltaTime) override {

            if (!transform) return; //this gameObject does not have a transform!

            oscillateX();
            oscillateY();
            oscillateZ();
            //transform->position = transform->position + increment;

        }
        void Draw() override { }


    private:
        void oscillateX() {
            transform->position.x += x_increment;

            if (transform->position.x >= origin_pos.x + x_oscill_dist) {
                x_increment = -abs(x_increment);
            } else if (transform->position.x <= origin_pos.x - x_oscill_dist) {
                x_increment = abs(x_increment);
            }

        }

        void oscillateY() {
            transform->position.y += y_increment;

            if (transform->position.y >= origin_pos.y + y_oscill_dist) {
                y_increment = -abs(y_increment);
            } else if (transform->position.y <= origin_pos.y - y_oscill_dist) {
                y_increment = abs(y_increment);
            }
//            if (transform->position.y >= 1.5 && transform->position.y <= 1.6 ) {
//                increment.y = -speed.y;
//            }
//            else if (transform->position.y <= 0 && transform->position.y >= -0.1) {
//                increment.y = speed.y;
//            }
        }

        void oscillateZ() {

            transform->position.z += z_increment;

            if (transform->position.z >= origin_pos.z + z_oscill_dist) {
                z_increment = -abs(z_increment);
            } else if (transform->position.z <= origin_pos.z - z_oscill_dist) {
                z_increment = abs(z_increment);
            }
        }


    };


}