#ifndef GAME_OBJECTS_HELPERS_H
#define GAME_OBJECTS_HELPERS_H

#include <ranges>
#include <scenes/destroy_asteroids_scene.h>

struct game_objects_helpers
{
    void remove_not_active(std::vector<variant_game_obj>& game_objects);

    void call_update_on(std::vector<variant_game_obj>& game_objects);
};

#endif //GAME_OBJECTS_HELPERS_H
