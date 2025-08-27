#include <SDL2\SDL.h>

int main(int argc, char* args[]){
    
    // Inicializando a biblioteca
    SDL_Init(SDL_INIT_EVERYTHING);

    // Criando janela 800x600 centralizada
    SDL_Window *janela = SDL_CreateWindow(
        "Exemplo", // Titulo
        SDL_WINDOWPOS_CENTERED, // Posicao  x (centralizada)
        SDL_WINDOWPOS_CENTERED, // Posicao y (centralizada)
        800, 600, // Largura e Altura
        SDL_WINDOW_SHOWN // Mantem a janela visivel
    );

    // Janela fica aberta por 3 segundos
    SDL_Delay(3000);

    return 0;  
}