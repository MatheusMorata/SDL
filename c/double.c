#include <SDL2/SDL.h>

int main(void) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window*   win = SDL_CreateWindow("ex", 0, 0, 640, 360, SDL_WINDOW_SHOWN);
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    for (int i = 0; i < 5; i++) {
        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
        SDL_RenderClear(ren);

        SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
        SDL_Rect r = { 2 + i * 12, 10, 10, 10 };
        SDL_RenderFillRect(ren, &r);

        SDL_RenderPresent(ren);  
        SDL_Delay(500);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}