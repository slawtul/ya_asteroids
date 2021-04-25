#include "texture_shelf.h"

SDL_Texture* texture_shelf::get_texture(const std::string_view& texture_name)
{
    return shelf[texture_name];
}

void texture_shelf::add_image(SDL_Renderer* renderer, const std::string_view& texture_name, const std::string_view& file)
{
    auto surface = load_image(file);
    auto texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    shelf[texture_name] = texture;
    SDL_LogInfo(0, "Create texture for %s", std::string(file).c_str());
}

void texture_shelf::add_init_images(SDL_Renderer* renderer)
{
    add_image(renderer, "background_01_static.jpg", "resources/background_01_static.jpg");
    add_image(renderer, "background_02_static.jpg", "resources/background_02_static.jpg");
    add_image(renderer, "background_03_static.jpg", "resources/background_03_static.jpg");
    add_image(renderer, "background_04_static.jpg", "resources/background_04_static.jpg");
    add_image(renderer, "bullet_short_single.png", "resources/bullet_short_single.png");
    add_image(renderer, "DKO-api-X1.png", "resources/DKO-api-X1.png");
    add_image(renderer, "CX16-X1.png", "resources/CX16-X1.png");
    add_image(renderer, "WO84-wu-X1.png", "resources/WO84-wu-X1.png");
    add_image(renderer, "explosion.png", "resources/explosion.png");
}

void texture_shelf::destroy_textures()
{
    for (auto const &[texture_name, texture] : shelf) {
        SDL_DestroyTexture(texture);
    }
    SDL_LogInfo(0, "Destroy all textures");
}

SDL_Surface* texture_shelf::load_image(const std::string_view& file) const
{
    const auto surface = IMG_Load(std::string(file).c_str());
    if (surface == nullptr)
    {
        SDL_Log("Unable to load image %s", std::string(file).c_str());
        SDL_Quit();
    }
    return surface;
}
