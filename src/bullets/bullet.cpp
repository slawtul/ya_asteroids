#include "bullet.h"

bullet::bullet(SDL_Renderer* renderer, SDL_Rect rect, texture_shelf* ts, obj_meta meta, obj_motion motion)
    : renderer(renderer), rect(rect), ts(ts), meta(meta), motion(motion)
{
}

void bullet::update()
{
    input();
    physics();
    gfx();
}

void bullet::input()
{
    // Fire bullet input ('space' or 'enter' key) is handled in the scene file
}

void bullet::physics()
{
    motion.dx += std::cos(motion.angle * constants::DEG_TO_RAD) * motion.acceleration;
    motion.dy += std::sin(motion.angle * constants::DEG_TO_RAD) * motion.acceleration;

    physics_helpers ph {};
    if (const double speed = ph.current_speed(motion.dx, motion.dy); speed > motion.max_speed)
    {
        motion.dx *= motion.max_speed / speed;
        motion.dy *= motion.max_speed / speed;
    }
}

void bullet::gfx()
{
    rect.x += static_cast<int>(motion.dx);
    rect.y += static_cast<int>(motion.dy);

    if (gfx_helpers gh {}; gh.is_off_screen(rect.x, rect.y, renderer))
    {
        meta.is_active = false;
        return;
    }

    SDL_RenderCopyEx(renderer, ts->get_texture("bullet_short_single.png"), nullptr, &rect, motion.angle + 90, nullptr, SDL_FLIP_NONE);
}
