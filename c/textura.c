#include <SDL2/SDL.h>
#include <stdbool.h>
#include <SDL2/SDL_image.h> 

#define LARGURA 800
#define ALTURA 600

int main(int argc, char* argv[]){

    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    
    SDL_Window* janela = SDL_CreateWindow(
        "Quadrado com textura",              
        SDL_WINDOWPOS_CENTERED,              
        SDL_WINDOWPOS_CENTERED,              
        LARGURA,                      
        ALTURA,                       
        SDL_WINDOW_SHOWN                     
    ); 

    SDL_Renderer* renderizador = SDL_CreateRenderer(janela, -1, 0);

    SDL_SetRenderDrawColor(renderizador, 0, 0, 0, 255);
    SDL_RenderClear(renderizador);

    SDL_Rect quadrado = { (LARGURA / 2) - 50, (ALTURA / 2) - 50, 100, 100 }; 
    SDL_Surface* superficie = IMG_Load("textura.png"); 
    SDL_Texture* textura_quadrado = SDL_CreateTextureFromSurface(renderizador, superficie); 
    SDL_RenderCopy(renderizador, textura_quadrado, NULL, &quadrado);
    SDL_RenderPresent(renderizador);

    bool executando = true;
    SDL_Event evento;
    while (executando) {
        SDL_WaitEvent(&evento);
        if (evento.type == SDL_QUIT) {
            executando = false;
        }
    }

    SDL_FreeSurface(superficie); 
    SDL_DestroyTexture(textura_quadrado);
    SDL_DestroyRenderer(renderizador);
    SDL_DestroyWindow(janela);
    IMG_Quit();
    SDL_Quit();

    return 0;
}