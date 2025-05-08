
#include "../headers/game.h"

int Game::Setup() {
    
    SDL_Init(SDL_INIT_EVERYTHING);
#ifdef SDL_HINT_IME_SHOW_UI
    SDL_SetHint(SDL_HINT_IME_SHOW_UI, "1");
#endif
    window = SDL_CreateWindow("Sandbox Game",50,30,1280,720,SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    
    if (!window) {
        printf("Window could not be created: %s\n", SDL_GetError());
        return -1;
    }
    if (!renderer) {
        printf("Renderer could not be created: %s\n", SDL_GetError());
        return -1;
    }
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    // Setup Platform/Renderer backends
    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer2_Init(renderer);
    TextureManager::Load(renderer, testImage, "res/characters.png");
    player = new Sprite<int>(renderer, testImage);
    player->SetSize(64, 64);
return 0;
}

int Game::Run() {
    Setup();  
    bool running = true;
    while (running)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            ImGui_ImplSDL2_ProcessEvent(&event);
        }

        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Edit Color");
        ImGui::ColorEdit4("Change BG SDL2", imcolor);
        ImGui::End();
        ImGui::Render();

        SDL_SetRenderDrawColor(renderer, imcolor[0] * 255, imcolor[1] * 255, imcolor[2] * 255, imcolor[3] * 255);
        SDL_RenderClear(renderer);

        player->Draw(renderer, 800, 800);  // ✅ Draw before presenting the frame

        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), renderer);
        SDL_RenderPresent(renderer);
    }

    Exit();
    return 0;
}


int Game::Exit() {
    TextureManager::Cleanup();
    delete player;
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
    return 0;
}