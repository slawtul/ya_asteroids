#include "gfx_helpers.h"

bool gfx_helpers::is_off_screen(int rect_x, int rect_y, SDL_Renderer* renderer)
{
    int screen_width {}, screen_height {};
    SDL_GetRendererOutputSize(renderer, &screen_width, &screen_height);

    return (rect_x < 0 || rect_y < 0) || (rect_x > screen_width || rect_y > screen_height);
}

std::pair<int, int>
gfx_helpers::opposite_edge_position(int rect_x, int rect_y, int rect_w, int rect_h, SDL_Renderer* renderer)
{
    int screen_width {}, screen_height {};
    SDL_GetRendererOutputSize(renderer, &screen_width, &screen_height);

    if (rect_x > screen_width)
    {
        rect_x = -rect_w;
    }
    if (rect_y > screen_height)
    {
        rect_y = -rect_h;
    }
    if (rect_x < -rect_w)
    {
        rect_x = screen_width;
    }
    if (rect_y < -rect_h)
    {
        rect_y = screen_height;
    }
    return {rect_x, rect_y};
}
