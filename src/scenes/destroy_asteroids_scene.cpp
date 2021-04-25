#include "shared/game_objects_helpers.h"
#include "destroy_asteroids_scene.h"

void destroy_asteroids_scene::update(SDL_Event& event, SDL_Renderer* renderer, texture_shelf* ts, std::vector<variant_game_obj>& game_objects)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, ts->get_texture("background_04_static.jpg"), nullptr, nullptr);
    SDL_PollEvent(&event);

    auto const spaceship_A = std::get<spaceship_a>(game_objects[0]);
    auto const spaceship_B = std::get<spaceship_b>(game_objects[1]);

    if (SDL_HasIntersection(&spaceship_A.rect, &spaceship_B.rect)) {
        SDL_LogInfo(0, "intersection");
    }

    if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_SPACE])
    {
        bullet_helpers bh {};
        auto const rect = bh.rate_rect(spaceship_A.rect);
        auto const motion = bh.rate_motion(spaceship_A.motion);
        bullet b {renderer, rect, ts, {}, motion};
        game_objects.emplace_back(b);
    }

    if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_RETURN])
    {
        bullet_helpers bh {};
        auto const rect_b = bh.rate_rect(spaceship_B.rect);
        auto const motion = bh.rate_motion(spaceship_B.motion);
        bullet b {renderer, rect_b, ts, {}, motion};
        game_objects.emplace_back(b);
    }

    game_objects_helpers goh {};
    goh.call_update_on(game_objects);
    goh.remove_not_active(game_objects);
}
