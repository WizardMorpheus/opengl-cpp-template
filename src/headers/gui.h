#ifndef GUI_H
#define GUI_H

#include "imgui/imgui.h"
#include "GLFW/glfw3.h"

class GUI {
private:
	// Our state
    bool show_demo_window;
    bool show_another_window;
    ImGuiIO io;

public:
    GUI(GLFWwindow* window);

    void renderGui(GLFWwindow* window);

    void cleanupGui();

};


#endif