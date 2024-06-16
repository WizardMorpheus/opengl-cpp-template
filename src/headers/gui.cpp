#include "GUI.h"

#include "GLFW/glfw3.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include "imfilebrowser/imfilebrowser.h"

GUI::GUI(GLFWwindow* window) {

    this->fileMenuOpen = false;
    this->loading = false;
    this->saving = false;
    this->fileDialog = ImGui::FileBrowser();

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    this->io = ImGui::GetIO(); 
    (void)this->io;
    this->io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    this->io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");
}

void GUI::render(GLFWwindow* window) {
    // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // main menu bar
        if (ImGui::BeginMainMenuBar()) {
            ImGui::SetWindowFontScale(2);
            if (ImGui::BeginMenu("file", &this->fileMenuOpen)) {
                if (ImGui::MenuItem("Load")) {
                    this->fileDialog.SetTitle("Load");
                    this->fileDialog.SetTypeFilters({ ".*" }) ;
                    this->fileDialog.Open();
                    this->loading = true;
                }
                if (ImGui::MenuItem("Save")) {
                    this->fileDialog.SetTitle("Save");
                    this->fileDialog.SetTypeFilters({ ".*" }) ;
                    this->fileDialog.Open();
                    this->saving = true;
                }
                ImGui::EndMenu();
            }

            ImGui::EndMainMenuBar();
        }

        if (this->loading || this->saving) {
            this->fileDialog.Display();
            if (this->fileDialog.HasSelected()) {
                // load or save
                this->fileDialog.ClearSelected();
                this->fileDialog.Close();
                this->loading = false;
                this->saving = false;
            }
        }

		// Rendering
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void GUI::cleanup() {
    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}
