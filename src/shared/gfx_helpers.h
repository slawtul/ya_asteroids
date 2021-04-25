#ifndef GFX_HELPERS_H
#define GFX_HELPERS_H

#include <utility>
#include <SDL_render.h>

struct gfx_helpers
{
    std::pair<int, int> opposite_edge_position(int rect_x, int rect_y, int rect_w, int rect_h, SDL_Renderer* renderer);
    bool is_off_screen(int rect_x, int rect_y, SDL_Renderer* renderer);
};

#endif //GFX_HELPERS_H
