#ifndef GRAPHICS_DEBUG_H
#define GRAPHICS_DEBUG_H

#include <SDL.h>

struct graphics_debug
{
    void log_screen_size(SDL_Renderer* renderer);
};

#endif // GRAPHICS_DEBUG_H
