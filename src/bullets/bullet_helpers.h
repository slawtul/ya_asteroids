#ifndef BULLET_HELPERS_H
#define BULLET_HELPERS_H

#include "bullet.h"

struct bullet_helpers
{
    // Calculates bullet motion from spaceship motion
    obj_motion rate_motion(const obj_motion& spaceship_motion);

    // Calculates bullet rect from spaceship rect
    SDL_Rect rate_rect(const SDL_Rect& spaceship_rect);
};

#endif //BULLET_HELPERS_H
