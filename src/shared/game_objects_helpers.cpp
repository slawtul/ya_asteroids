#include "game_objects_helpers.h"

auto is_active = [](auto& game_obj)
{
    return game_obj.meta.is_active;
};

void game_objects_helpers::remove_not_active(std::vector<variant_game_obj>& game_objects)
{
    const auto not_active = std::remove_if(game_objects.begin(), game_objects.end(),
        [](const auto& game_obj) {
            return !std::visit(is_active, game_obj);
        });
    game_objects.erase(not_active, game_objects.end());
}

auto run_update = [](auto& game_obj)
{
    return game_obj.update();
};

void game_objects_helpers::call_update_on(std::vector<variant_game_obj>& game_objects)
{
    // Reverse iterator is used because of bullets should be fired under spaceships
    for (auto it = game_objects.rbegin(); it != game_objects.rend(); ++it) {
        std::visit(run_update, *it);
    }
}
