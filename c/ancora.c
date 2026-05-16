#include <SDL2/SDL.h>

int main(void) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window*   win = SDL_CreateWindow("ex", 0, 0, 640, 360, SDL_WINDOW_SHOWN);
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
    SDL_RenderClear(ren);

    int sw = 640, sh = 360; 
    int rw =  60, rh =  60;  

    SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
    SDL_Rect r = {
        (sw - rw) / 2,   
        (sh - rh) / 2,   
        rw, rh
    };
    SDL_RenderFillRect(ren, &r);

    SDL_RenderPresent(ren);
    SDL_Delay(3000);

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}