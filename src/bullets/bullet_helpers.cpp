#include "bullet_helpers.h"

obj_motion bullet_helpers::rate_motion(const obj_motion& spaceship_motion)
{
    obj_motion motion{};
    motion.acceleration=32;
    motion.angle=spaceship_motion.angle;
    motion.max_speed=spaceship_motion.max_speed*4;
    return motion;
}

SDL_Rect bullet_helpers::rate_rect(const SDL_Rect& spaceship_rect)
{
    SDL_Rect rect{0,0,4,20};
    rect.x=spaceship_rect.x+(spaceship_rect.w-rect.w)/2;
    rect.y=spaceship_rect.y+(spaceship_rect.h-rect.h)/2;
    return rect;
}
