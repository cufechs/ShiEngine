
#include "GameObjectComponent.h"
#include <iostream>

namespace ShiEngine {

    class testComp : public ShiEngine::GameObjectComponent {
    public:

        testComp() {
            Enabled = true;
            std::cout << "testComp created\n";
        }

        ~testComp() {
            Enabled = false;
            std::cout << "testComp destroyed\n";
        }

        void Start() override {
            std::cout << "testComp started\n";
        }

        void Update(double deltaTime) override {
            std::cout << "testComp updates\n";
        }

        void Draw() override {
            std::cout << "testComp draw\n";
        }

    };


}


