#include <SDL2\SDL.h>

int main(int argc, char* args[]){

    // Inicializando SDL2
    SDL_Init(SDL_INIT_EVERYTHING);

    // Criando uma janela 800x600 centralizada na tela
    SDL_Window* janela = SDL_CreateWindow(
        "Quadrado azul", // Titulo
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, // Posição x e y (centralizadas)
        800, 600, // Largura e Altura
        SDL_WINDOW_SHOWN // Flag para manter a janela visível
    );

    // Criando um renderizador
    SDL_Renderer* renderizador = SDL_CreateRenderer(janela, -1, 0); 

    // Criando quadrado
    SDL_Rect quadrado = {
        400, 300, // Posição X e Y
        40, 40 // Largura e Altura
    };
    
    SDL_SetRenderDrawColor(renderizador, 255, 255, 255, 0); // Pintando a janela (branco)
    SDL_RenderClear(renderizador); // Limpa o renderizador
    SDL_SetRenderDrawColor(renderizador, 0, 0, 255, 0); // Pintando o quadrado (azul) 
    SDL_RenderFillRect(renderizador, &quadrado); // Desenha o quadrado
    SDL_RenderPresent(renderizador); // Atualiza a tela com o conteúdo do renderizador
    SDL_Delay(3000); // Mantem a janela aberta por 3 segundos

    // Liberando recursos
    SDL_DestroyWindow(janela);
    SDL_DestroyRenderer(renderizador);
    SDL_Quit();
    return 0;
}