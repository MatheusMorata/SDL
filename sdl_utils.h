#ifndef SDL_UTILS_H
#define SDL_UTILS_H

#include <SDL.h>
#include <stdbool.h>


typedef struct {
    SDL_Window* window;
    SDL_Renderer* render;
    bool success;
    char error[256];
} SDL_Resources;

SDL_Resources open_sdl(const char* window_title);

void close_sdl(SDL_Resources resources);

#endif