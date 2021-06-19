#ifndef FRAMES_DEBUG_H
#define FRAMES_DEBUG_H

#include <string>
#include <SDL_ttf.h>
#include "text/render_text.h"

struct frames_debug
{
    double frame_time;
    double frames_per_sec;
    double max_fps;
    double min_fps;

    uint32_t current_time;
    uint32_t last_time;
    uint32_t frame_delta_time;

    double rate_frames_per_sec();
    double rate_frame_delta_time();
    double rate_max_frames();
    double rate_min_frames();

    void render_frames_per_sec(TTF_Font* font, SDL_Color color, SDL_Renderer* renderer);
    void render_max_frames(TTF_Font* font, SDL_Color color, SDL_Renderer* renderer);
    void render_min_frames(TTF_Font* font, SDL_Color color, SDL_Renderer* renderer);
};

#endif // FRAMES_DEBUG_H
