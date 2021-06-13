#ifndef BULLET_H
#define BULLET_H

#include "shared/gfx_helpers.h"
#include "shared/physics_helpers.h"
#include "spaceship/spaceship_a.h"

struct bullet
{
    bullet(SDL_Renderer* renderer,SDL_Rect rect,texture_shelf* ts,obj_meta meta,obj_motion motion);

    void input();
    void physics();
    void gfx();
    void update();

    SDL_Renderer* renderer;
    SDL_Rect rect;
    texture_shelf* ts;
    obj_meta meta;
    obj_motion motion;
};

#endif //BULLET_H
