#ifndef DESTROY_ASTEROIDS_SCENE_H
#define DESTROY_ASTEROIDS_SCENE_H

#include <SDL.h>
#include <vector>
#include <algorithm>
#include <variant>
#include <iostream>
#include "images/texture_shelf.h"
#include "bullets/bullet.h"
#include "bullets/bullet_helpers.h"
#include "spaceship/spaceship_a.h"
#include "spaceship/spaceship_b.h"

using variant_game_obj=std::variant<spaceship_a,spaceship_b,bullet>;

struct destroy_asteroids_scene
{
    void update(SDL_Event& event,SDL_Renderer* renderer,texture_shelf* ts,std::vector<variant_game_obj>& game_objects);
};

#endif // DESTROY_ASTEROIDS_SCENE_H
