//
// Created by addik on 10/09/2026.
//

#ifndef MOTIONLABENGINE_WINDOW_H
#define MOTIONLABENGINE_WINDOW_H
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "maths/Vector.h"
#include <iostream>
#include <vector>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "Object.h"

namespace MotionLab {
    struct Color {
        float red;
        float green;
        float blue;
        float alpha;
    };

    class Window {
    private:
        GLFWwindow* window;
    public:
        Color background = {0.98, 0.9,1, 255};
        Maths::Vector2<int> size;
        std::vector<Object> objects;
        int beginLoop();
        Window(Maths::Vector2<int> windowSize = {648, 480});

        void cleanUp();

        ~Window();
    };

}

#endif //MOTIONLABENGINE_WINDOW_H
