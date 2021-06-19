#include "sdl2_helpers.h"

void sdl2_helpers::init(const uint32_t flags)
{
    SDL_LogSetAllPriority(SDL_LOG_PRIORITY_DEBUG);
    if (SDL_Init(flags) != 0) {
        SDL_Log("Unable to initialize SDL2 %s", SDL_GetError());
        SDL_Quit();
    }
}

SDL_Window* sdl2_helpers::create_window(const char* title, int screen_width, int screen_height, uint32_t flags)
{
    const auto window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, flags);
    if (window == nullptr) {
        SDL_Log("Unable to create a window %s", SDL_GetError());
        SDL_Quit();
    }
    return window;
}

SDL_Renderer* sdl2_helpers::create_renderer(SDL_Window* window, uint32_t flags)
{
    const auto renderer = SDL_CreateRenderer(window, -1, flags);
    if (renderer == nullptr) {
        SDL_Log("Unable to create renderer_ %s", SDL_GetError());
        SDL_Quit();
    }
    return renderer;
}
