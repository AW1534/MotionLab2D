//
// Created by aw1lt on 17/09/2026.
//

#ifndef MOTIONLABENGINE_OBJECT_H
#define MOTIONLABENGINE_OBJECT_H
#include "maths/Vector.h"

namespace MotionLab {
    class Object {
    public:
        struct Transform2D {
            Maths::Vector2<float> position = {};
            Maths::Vector2<float> scale = {};
            float rotation = 0;
        } transform;

        void render();
    };
}


#endif //MOTIONLABENGINE_OBJECT_H
