//
// Created by addik on 10/09/2026.
//

#include "Window.h"

namespace MotionLab {
    Window::Window(Maths::Vector2<int> windowSize) {
    std::cout << "Window Initilizer called" << std::endl;

    this->size = windowSize;

    if (!glfwInit()) { return; }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);

    window = glfwCreateWindow(size.x(), size.y(), "MotionLab2D", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    // io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // IF using Docking Branch

    io.Fonts->AddFontDefaultVector();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");


    float value = 5.0f;
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // Start the ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Your ImGui UI code
        ImGui::Text("Hello, world %d", 123);
        if (ImGui::Button("Save")) {
            std::cout << "hi" << std::endl;
        }


        ImGui::ColorPicker4("Background Color", reinterpret_cast<float*>(&background), ImGuiColorEditFlags_NoSmallPreview |
                        ImGuiColorEditFlags_NoTooltip |
                        ImGuiColorEditFlags_NoLabel |
                        ImGuiColorEditFlags_NoSidePreview |
                        // ImGuiColorEditFlags_NoInputs |
                        // ImGuiColorEditFlags_NoAlpha |
                        ImGuiColorEditFlags_PickerHueBar);


        ImGui::SliderFloat("Set value", &value, 0.0f, 10.0f);

        // Render
        ImGui::Render();

        // glfwSetWindowOpacity(window, 0.0f); // breaks on windows and was pointless anyway so disabled
        glClearColor(background.red, background.green, background.blue, background.alpha);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        for (auto object : objects) {
            object.render();
        }

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    cleanUp();
}

void Window::cleanUp() {
    std::cout << "CleanUp" << std::endl;
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
}

Window::~Window() {
    // cleanUp();
}
}
