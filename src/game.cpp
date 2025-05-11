#include "../headers/game.h"
#include <iostream>

Game::Game(SDL_Renderer* renderer, SDL_Window* window) : renderer(renderer), window(window), isRunning(true) {
    Initialize();
}

Game::~Game() {
    Cleanup();
}
Spritesheet* characterSheet = nullptr;
void Game::Initialize() {
    // Initialize the game logic here (load resources, set initial state, etc.)
    std::cout << "Game initialized." << std::endl;
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io{ImGui::GetIO()};

    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    ImGui_ImplSDL2_InitForSDLRenderer(window,renderer);
    ImGui_ImplSDLRenderer2_Init(renderer);

    if(!TextureManager::Load("characters", "res/characters.png", renderer)) {
        std::cout << "Failed to load characters" << std::endl;
    }
    characterSheet = new Spritesheet("characters", 32,32);
    characterSheet->SetGridSize(736, 128);

}

void Game::Run() {
    while (isRunning) {
        HandleEvents();
        Update();
        Render();
    }
}

void Game::HandleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        ImGui_ImplSDL2_ProcessEvent(&event);
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
        // Handle other events (keyboard, mouse, etc.) here
    }
}

void Game::Update() {

    characterSheet->Update();
}
bool showPanel{true};
void Game::Render() {
    ImGui_ImplSDLRenderer2_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    ImGui::DockSpaceOverViewport();
    ImGui::Render();
    SDL_RenderClear(renderer);  // Clear the renderer
    characterSheet->Draw(renderer, 100,100, 3);
    ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), renderer);
    if (showPanel) {
    ImGui::Begin("Image Window", &showPanel);
    ImGui::Text("Fuck You");
    ImGui::End();
    }
    SDL_RenderPresent(renderer); // Present the renderer to the screen
}

void Game::Cleanup() {
    // Clean up resources here
    delete characterSheet;
    characterSheet = nullptr;
    TextureManager::Cleanup();
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    std::cout << "Game resources cleaned up." << std::endl;
}
