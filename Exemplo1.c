#include <SDL.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "sdl_utils.h"

// Função para verificar colisão entre dois retângulos (quadrados)
int colisao_rects(SDL_Rect a, SDL_Rect b) {
    return (a.x < b.x + b.w) &&
           (a.x + a.w > b.x) &&
           (a.y < b.y + b.h) &&
           (a.y + a.h > b.y);
}

// Função para marcar quadrados vermelhos como consumidos após colisão
void colisao(SDL_Rect quadrado, SDL_Rect quadrados[], int consumidos[]) {
    for (int i = 0; i < 10; i++) {
        if (!consumidos[i] && colisao_rects(quadrado, quadrados[i])) {
            consumidos[i] = 1;  // Marca como consumido
        }
    }
}

int main(int argc, char* argv[]) {
    SDL_Resources sdl_resources = open_sdl("Quadradinhos");
    if (!sdl_resources.success) {
        printf("%s\n", sdl_resources.error);
        return 1;
    }

    srand(time(NULL));
    // Posição inicial do quadrado amarelo
    int x = 400;
    int y = 300;
    int tamanho = 10;
    SDL_Rect quadrado = { x, y, tamanho, tamanho };

    // Inicializa os quadrados vermelhos e vetor de consumidos
    int consumidos[10] = {0};
    SDL_Rect quadrados[10];
    for (int i = 0; i < 10; i++) {
        quadrados[i].x = rand() % (800 - tamanho);
        quadrados[i].y = rand() % (600 - tamanho);
        quadrados[i].w = tamanho;
        quadrados[i].h = tamanho;
    }

    int rodando = 1;
    SDL_Event event;

    // Marca o tempo inicial para o cronômetro
    time_t tempo_inicio = time(NULL);

    while (rodando) {
        // Verifica se os 30 segundos já passaram
        time_t agora = time(NULL);
        if (difftime(agora, tempo_inicio) >= 30) {
            printf("VOCÊ PERDEU!\n");
            break;
        }

        // Verifica se o jogador venceu (todos os quadrados foram consumidos)
        int venceu = 1;
        for (int i = 0; i < 10; i++) {
            if (consumidos[i] == 0) {
                venceu = 0;  // Ainda resta quadrados vermelhos
                break;
            }
        }
        if (venceu) {
            printf("VOCÊ GANHOU!\n");
            break;
        }

        // Processa os eventos (teclado e fechamento de janela)
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                rodando = 0;  // Fecha o jogo
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_w:
                        y -= 10;  // Move para cima
                        break;
                    case SDLK_s:
                        y += 10;  // Move para baixo
                        break;
                    case SDLK_a:
                        x -= 10;  // Move para esquerda
                        break;
                    case SDLK_d:
                        x += 10;  // Move para direita
                        break;
                }
            }
        }

        // Atualiza a posição do quadrado amarelo
        quadrado.x = x;
        quadrado.y = y;

        // Verifica colisão com os quadrados vermelhos
        colisao(quadrado, quadrados, consumidos);

        // Limpa a tela (define cor de fundo branca)
        SDL_SetRenderDrawColor(sdl_resources.render, 255, 255, 255, 255);
        SDL_RenderClear(sdl_resources.render);

        // Desenha os quadrados vermelhos restantes
        for (int i = 0; i < 10; i++) {
            if (!consumidos[i]) {
                SDL_SetRenderDrawColor(sdl_resources.render, 255, 0, 0, 255);
                SDL_RenderFillRect(sdl_resources.render, &quadrados[i]);
            }
        }

        // Desenha o quadrado amarelo (jogador)
        SDL_SetRenderDrawColor(sdl_resources.render, 255, 255, 0, 255);
        SDL_RenderFillRect(sdl_resources.render, &quadrado);

        // Atualiza a tela
        SDL_RenderPresent(sdl_resources.render);

        SDL_Delay(16);  // 60 FPS
    }

    close_sdl(sdl_resources);

    return 0;
}