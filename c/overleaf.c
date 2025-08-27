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

    // Criando renderizador
    SDL_Renderer *renderizador = SDL_CreateRenderer(janela, -1, 0);

    SDL_SetRenderDrawColor(renderizador, 255, 255, 255, 0); // Colorindo fundo (branco)
    SDL_RenderClear(renderizador); // Limpa o renderizador
    SDL_RenderPresent(renderizador); // Atualizando a tela

    // Janela fica aberta por 3 segundos
    SDL_Delay(3000);

    return 0;  
}