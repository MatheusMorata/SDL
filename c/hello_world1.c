#include <SDL2/SDL.h>
#include <stdbool.h>

// Constantes para a dimensão da janela
const int LARGURA_JANELA = 800;
const int ALTURA_JANELA = 600;

int main(int argc, char* argv[]){
    // Criação da Janela
    SDL_Window* janela = SDL_CreateWindow(
        "Hello World Gráfico",               // Título da janela
        SDL_WINDOWPOS_CENTERED,              // Posição X inicial (centralizada)
        SDL_WINDOWPOS_CENTERED,              // Posição Y inicial (centralizada)
        LARGURA_JANELA,                      // Largura da janela em pixels
        ALTURA_JANELA,                       // Altura da janela em pixels
        SDL_WINDOW_SHOWN                     // Flags (a janela deve ser mostrada)
    );
    // Criação do Renderizador
    SDL_Renderer* renderizador = SDL_CreateRenderer(
        janela,                              // A janela onde o renderizador irá desenhar
        -1,                                  // Índice do driver de renderização (-1 para o primeiro disponível)
        0                                    // 0 - Sem flags - sem preferência ou requisito específico
    );
    // Desenha a cena
    SDL_SetRenderDrawColor(renderizador, 255, 255, 255, 255); // Definição da cor(R, G, B, Alpha)
    SDL_RenderClear(renderizador); // Utiliza a cor para limpar a tela
    SDL_RenderPresent(renderizador); // Mostra o que foi desenhado na tela
    SDL_Delay(3000); // pausa de 3 segundos
    // Limpeza de Recursos
    SDL_DestroyRenderer(renderizador);
    SDL_DestroyWindow(janela);
    SDL_Quit();
    return 0;
}