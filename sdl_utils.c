#include "sdl_utils.h"
#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

SDL_Resources open_sdl(const char* window_title){
    // inicializa struct
    SDL_Resources resources;
    resources.window = NULL;
    resources.render = NULL;
    resources.success = false;
    resources.error[0] = '\0';

    // inicializa o SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        snprintf(resources.error, sizeof(resources.error), "Erro ao iniciar SDL: %s", SDL_GetError());
        return resources;
    }

    // window
    resources.window = SDL_CreateWindow(
        window_title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_SHOWN
    );

    if (!resources.window) {
        snprintf(resources.error, sizeof(resources.error), "Erro ao criar window: %s", SDL_GetError());
        SDL_Quit();
        return resources;
    }

    // renderizador
    resources.render = SDL_CreateRenderer(resources.window, -1, SDL_RENDERER_ACCELERATED);
    if (!resources.render) {
        snprintf(resources.error, sizeof(resources.error), "Erro ao criar render: %s", SDL_GetError());
        SDL_DestroyWindow(resources.window);
        SDL_Quit();
        return resources;
    }

    resources.success = true;
    return resources;
}

void close_sdl(SDL_Resources resources){
    if (resources.render) {
        SDL_DestroyRenderer(resources.render);
    }
    if (resources.window) {
        SDL_DestroyWindow(resources.window);
    }
    SDL_Quit();
}
