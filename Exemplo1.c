#include <SDL.h>
#include <stdio.h>
#include <time.h>

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
    SDL_Window* janela = NULL;
    SDL_Renderer* render = NULL;
    srand(time(NULL)); // Inicializa números aleatórios 

    // Inicializa o SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erro ao iniciar SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Cria a janela
    janela = SDL_CreateWindow(
        "Ola Mundo",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_SHOWN
    );

    // Verifica erros na criação da janela
    if (!janela) {
        printf("Erro ao criar janela: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Cria o renderizador
    render = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);
    if (!render) {
        printf("Erro ao criar render: %s\n", SDL_GetError());
        SDL_DestroyWindow(janela);
        SDL_Quit();
        return 1;
    }

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
        SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
        SDL_RenderClear(render);

        // Desenha os quadrados vermelhos restantes
        for (int i = 0; i < 10; i++) {
            if (!consumidos[i]) {
                SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
                SDL_RenderFillRect(render, &quadrados[i]);
            }
        }

        // Desenha o quadrado amarelo (jogador)
        SDL_SetRenderDrawColor(render, 255, 255, 0, 255);
        SDL_RenderFillRect(render, &quadrado);

        // Atualiza a tela
        SDL_RenderPresent(render);

        SDL_Delay(16);  // 60 FPS
    }

    // Limpeza 
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(janela);
    SDL_Quit();

    return 0;
}
