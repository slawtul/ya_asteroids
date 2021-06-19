#include "spaceship_a.h"

spaceship_a::spaceship_a(SDL_Renderer* renderer, SDL_Rect rect, texture_shelf* ts, obj_meta meta, obj_motion motion)
        : renderer{renderer}, rect{rect}, ts{ts}, meta{meta}, motion{motion}
{
}

void spaceship_a::update()
{
    input();
    physics();
    gfx();
}

void spaceship_a::input()
{
    if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_D]) {
        motion.angle += 6.0;
    }
    if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_A]) {
        motion.angle -= 6.0;
    }
    if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_W]) {
        motion.acceleration = 0.6;
        motion.max_speed = 8.0;
    }
    else {
        motion.acceleration = 0.2;
        motion.max_speed = 6.0;
    }
}

void spaceship_a::physics()
{
    motion.dx += std::cos(motion.angle * constants::DEG_TO_RAD) * motion.acceleration;
    motion.dy += std::sin(motion.angle * constants::DEG_TO_RAD) * motion.acceleration;

    physics_helpers ph{};
    if (const double speed = ph.current_speed(motion.dx, motion.dy);speed > motion.max_speed) {
        motion.dx *= motion.max_speed / speed;
        motion.dy *= motion.max_speed / speed;
    }
}

void spaceship_a::gfx()
{
    rect.x += static_cast<int>(motion.dx);
    rect.y += static_cast<int>(motion.dy);

    gfx_helpers gh{};
    const auto[x, y] = gh.opposite_edge_position(rect.x, rect.y, rect.w, rect.h, renderer);
    rect.x = x;
    rect.y = y;

    SDL_RenderCopyEx(renderer, ts->get_texture("DKO-api-X1.png"), nullptr, &rect, motion.angle + 90, nullptr, SDL_FLIP_NONE);
}
