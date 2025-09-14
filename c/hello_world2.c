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

    // Desenha a cena uma única vez
    SDL_SetRenderDrawColor(renderizador, 0, 0, 255, 255); // R, G, B, Alpha
    SDL_RenderClear(renderizador);
    // Define a cor para o nosso retângulo (Branco)
    SDL_SetRenderDrawColor(renderizador, 255, 255, 255, 255);
    // Cria o retângulo no centro da tela
    SDL_Rect retangulo = { (LARGURA_JANELA / 2) - 50, (ALTURA_JANELA / 2) - 50, 100, 100 }; // x, y, largura, altura
    SDL_RenderFillRect(renderizador, &retangulo); // Desenha o retângulo
    SDL_RenderPresent(renderizador); // Mostra o que foi desenhado na tela

    bool executando = true;
    SDL_Event evento;
    while (executando) {
        // Evento para fechar a janela [X] ou ALT + F4
        SDL_WaitEvent(&evento);
        if (evento.type == SDL_QUIT) {
            executando = false;
        }
    }
    // Limpeza de Recursos
    SDL_DestroyRenderer(renderizador);
    SDL_DestroyWindow(janela);
    SDL_Quit();
    return 0;
}