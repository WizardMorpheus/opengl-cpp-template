#ifndef GUI_H
#define GUI_H

#include "imgui/imgui.h"
#include "GLFW/glfw3.h"

class GUI {
private:
	// Our state
    bool fileMenuOpen;
    ImGuiIO io;

public:
    GUI(GLFWwindow* window);

    ~GUI();

    void render(GLFWwindow* window);

    void cleanup();

};


#endif