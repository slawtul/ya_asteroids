#include "init/sdl2_helpers.h"
#include "text/render_text.h"
#include "scenes/destroy_asteroids_scene.h"
#include "debug_info/graphics_debug.h"

#ifdef DEBUG

#include "debug_info/frames_debug.h"
#include "debug_info/objects_debug.h"

#endif

int main(int argc, char* argv[])
{
    SDL_LogInfo(0, "Program parameters: argc %d", argc);
    SDL_LogInfo(0, "Program parameters: argv %s", *argv);

    sdl2_helpers sdl2{};
    sdl2.init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    TTF_Init();

    const auto WR = SDL_WINDOW_RESIZABLE;
    const auto WHDPI = SDL_WINDOW_ALLOW_HIGHDPI;
    const auto RA = SDL_RENDERER_ACCELERATED;
    const auto RVSYNC = SDL_RENDERER_PRESENTVSYNC;

    const auto window = sdl2.create_window("YA Asteroids", 1920, 1080, WR | WHDPI);
    const auto renderer = sdl2.create_renderer(window, RA | RVSYNC);

    graphics_debug gd{};
    gd.log_screen_size(renderer);

    texture_shelf ts{};
    ts.add_init_images(renderer);

    std::vector<variant_game_obj> game_objects;
    game_objects.reserve(1024);

    spaceship_a ship_a{renderer, {0, 100, 64, 64}, &ts, {}, {}};
    spaceship_b ship_b{renderer, {100, 100, 64, 64}, &ts, {}, {}};

    game_objects.emplace_back(ship_a);
    game_objects.emplace_back(ship_b);

    #ifdef DEBUG
    const auto font = TTF_OpenFont("./resources/terminus.ttf", 16);
    const auto white = SDL_Color{255, 255, 255, 127};
    frames_debug fd{};
    objects_debug od{};
    #endif

    SDL_Event event{};
    destroy_asteroids_scene scene{};

    while (true) {
        if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_ESCAPE]) {
            break;
        }

        #ifdef DEBUG
        fd.current_time = SDL_GetTicks();
        #endif

        scene.update(event, renderer, &ts, game_objects);

        #ifdef DEBUG
        fd.render_frames_per_sec(font, white, renderer);
        fd.render_max_frames(font, white, renderer);
        fd.render_min_frames(font, white, renderer);
        od.objs_on_screen = game_objects.size();
        od.render_max_obj_qty(font, white, renderer);
        od.render_obj_qty(font, white, renderer);
        #endif

        SDL_RenderPresent(renderer);
    }

    #ifdef DEBUG
    SDL_LogInfo(0, "Max objects qty: %d", static_cast<int>(od.max_objs_on_screen));
    SDL_LogInfo(0, "Avg FPS: %.2f", fd.frames_per_sec);
    SDL_LogInfo(0, "Max FPS: %.2f", fd.max_fps);
    SDL_LogInfo(0, "Min FPS: %.2f", fd.min_fps);
    SDL_LogInfo(0, "Stop game");
    TTF_CloseFont(font);
    #endif

    //Free memory
    game_objects.clear();
    ts.destroy_textures();
    SDL_FreeSurface(SDL_GetWindowSurface(window));
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return 0;
}
