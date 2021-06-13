#include "objects_debug.h"

uint16_t objects_debug::count_objs()
{
    if(objs_on_screen>max_objs_on_screen)
    {
        max_objs_on_screen=objs_on_screen;
    }
    return max_objs_on_screen;
}

void objects_debug::render_obj_qty(TTF_Font* font,SDL_Color color,SDL_Renderer* renderer) const
{
    auto rect=SDL_Rect{20,72,120,16};
    render_text rt{};
    rt.render(rect,font,color,renderer,"Obj_qty: "+std::to_string(objs_on_screen));
}

void objects_debug::render_max_obj_qty(TTF_Font* font,SDL_Color color,SDL_Renderer* renderer)
{
    auto rect=SDL_Rect{20,88,120,16};
    render_text rt{};
    rt.render(rect,font,color,renderer,"Max_qty: "+std::to_string(count_objs()));
}
