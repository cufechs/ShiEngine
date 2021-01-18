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
        float Counter;
        Transform* transformPlayer;
        bool look;                        // look at player
        float orig_angle_y;
    public:
        float StartAfter;

        EnemyMovement() {
            Type = ComponentType::EnemyMove;
            x_increment = 0.0;
            y_increment = 0.0;
            z_increment = 0.0;
            x_oscill_dist = 0.0;
            y_oscill_dist = 0.0;
            z_oscill_dist = 0.0;
            StartAfter = 0;
            Counter = 0;
            transformPlayer = nullptr;
            look = false;
            followPlayer = false;
            Counter = 0;
            StartAfter = 0;
        }

        EnemyMovement(float startAfter) {
            Type = ComponentType::EnemyMove;
            x_increment = 0.0;
            y_increment = 0.0;
            z_increment = 0.0;
            x_oscill_dist = 0.0;
            y_oscill_dist = 0.0;
            z_oscill_dist = 0.0;
            StartAfter = startAfter;
            Counter = 0;
            transformPlayer = nullptr;
            look = false;
            followPlayer = false;
        }

        EnemyMovement(Transform* transformPlayer, bool follow=false, bool look=false) {
            Type = ComponentType::EnemyMove;
            x_increment = 0.0;
            y_increment = 0.0;
            z_increment = 0.0;
            x_oscill_dist = 0.0;
            y_oscill_dist = 0.0;
            z_oscill_dist = 0.0;
            setFollow(transformPlayer, look);
            this->look = look;
            this->followPlayer = follow;
            Counter = 0;
            StartAfter = 0;
        }

        void setFollow(Transform* transformPlayer, bool follow=false, bool look=false) {
            this->transformPlayer = transformPlayer;
            this->look = look;
            this->followPlayer = follow;
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

            orig_angle_y = transform->rotation.y;
        }

        void Update(double deltaTime) override {
            if (!transform) return; //this gameObject does not have a transform!

            if(Counter > StartAfter)
            {
                oscillateX(deltaTime*50);
                oscillateY(deltaTime*50);
                oscillateZ(deltaTime*50);

                if (transformPlayer != nullptr) {
                    if (followPlayer)
                        transform->position += (transformPlayer->position - transform->position) * glm::vec3(deltaTime);

                    if (look) {
                        glm::vec3 diff = transformPlayer->position - transform->position;
                        float angle = 180 * glm::atan((transformPlayer->position.x - transform->position.x) /
                                                      (transformPlayer->position.z - transform->position.z)) / 3.14;
                        angle = (diff.x < 0 && diff.z < 0) ? angle :
                                (diff.x >= 0 && diff.z >= 0) ? 180 + abs(angle) :
                                (diff.x >= 0 && diff.z < 0) ? angle :
                                (diff.x < 0 && diff.z > 0) ? 180 - abs(angle) : angle;

                        transform->rotation.y = orig_angle_y + 270 + angle;

                    }
                }

            }
            else
                Counter += (float)deltaTime;
            //transform->position = transform->position + increment;

        }
        void Draw() override { }


    private:
        void oscillateX(double deltatime) {
            transform->position.x += x_increment*deltatime;

            if (transform->position.x >= origin_pos.x + x_oscill_dist) {
                x_increment = -abs(x_increment);
            } else if (transform->position.x <= origin_pos.x - x_oscill_dist) {
                x_increment = abs(x_increment);
            }

        }

        void oscillateY(double deltatime) {
            transform->position.y += y_increment*deltatime;

            if (transform->position.y >= origin_pos.y + y_oscill_dist) {
                y_increment = -abs(y_increment);
            } else if (transform->position.y <= origin_pos.y - y_oscill_dist) {
                y_increment = abs(y_increment);
            }

        }

        void oscillateZ(double deltatime) {

            transform->position.z += z_increment*deltatime;

            if (transform->position.z >= origin_pos.z + z_oscill_dist) {
                z_increment = -abs(z_increment);
            } else if (transform->position.z <= origin_pos.z - z_oscill_dist) {
                z_increment = abs(z_increment);
            }
        }


    };


}