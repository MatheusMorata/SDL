#include <SDL2/SDL.h>

#define LARGURA 800
#define ALTURA 600

int main(int argc, char* argv[]){

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* janela = SDL_CreateWindow(
        "Hello World",               
        SDL_WINDOWPOS_CENTERED,              
        SDL_WINDOWPOS_CENTERED,              
        LARGURA,                      
        ALTURA,                       
        SDL_WINDOW_SHOWN                     
    );

    SDL_Renderer* renderizador = SDL_CreateRenderer(janela, -1, 0);                          

    SDL_SetRenderDrawColor(renderizador, 0, 0, 0, 255);
    SDL_RenderClear(renderizador); 
    SDL_RenderPresent(renderizador); 
    SDL_Delay(3000); 
    
    SDL_DestroyRenderer(renderizador);
    SDL_DestroyWindow(janela);
    SDL_Quit();
    return 0;
}