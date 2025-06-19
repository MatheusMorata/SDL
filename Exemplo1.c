#include <SDL.h>
#include <stdio.h>
#include <time.h>

// Função para verificar colisão entre dois retângulos
int colisao_rects(SDL_Rect a, SDL_Rect b) {
    return (a.x < b.x + b.w) &&
           (a.x + a.w > b.x) &&
           (a.y < b.y + b.h) &&
           (a.y + a.h > b.y);
}

// Função para apagar os quadrados consumidos
void verificar_colisoes(SDL_Rect quadrado, SDL_Rect quadrados[], int consumidos[]) {
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

    // Inicializa SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erro ao iniciar SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Cria a janela
    janela = SDL_CreateWindow(
        "Ola Mundo", // Título da janela 
        SDL_WINDOWPOS_CENTERED, // Posição x inicial da janela
        SDL_WINDOWPOS_CENTERED, // Posição y inicial da janela
        800, 600, // tamanho da janela
        SDL_WINDOW_SHOWN // Exibe janela
    );

    // Verifica erro ao criar janela
    if (!janela) {
        printf("Erro ao criar janela: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Cria o renderizador
    render = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);
    if (!render) {
        printf("Erro ao criar renderizador: %s\n", SDL_GetError());
        SDL_DestroyWindow(janela);
        SDL_Quit();
        return 1;
    }

    // Quadrado controlável (amarelo)
    int x = 400;
    int y = 300;
    int tamanho = 10;
    SDL_Rect quadrado = { x, y, tamanho, tamanho };

    // Quadrados vermelhos
    SDL_Rect quadrados[10];
    int consumidos[10] = {0};  // Inicializa todos como "não consumidos"

    for (int i = 0; i < 10; i++) {
        quadrados[i].x = rand() % (800 - tamanho);
        quadrados[i].y = rand() % (600 - tamanho);
        quadrados[i].w = tamanho;
        quadrados[i].h = tamanho;
    }

    int rodando = 1;
    SDL_Event event;

    while (rodando) {
        // Processa eventos
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                rodando = 0;
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_w: y -= 10; break;
                    case SDLK_s: y += 10; break;
                    case SDLK_a: x -= 10; break;
                    case SDLK_d: x += 10; break;
                }
            }
        }

        // Atualiza posição do quadrado amarelo
        quadrado.x = x;
        quadrado.y = y;

        // Verifica colisões
        verificar_colisoes(quadrado, quadrados, consumidos);

        // Limpa a tela (fundo branco)
        SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
        SDL_RenderClear(render);

        // Renderiza quadrados vermelhos não consumidos
        SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
        for (int i = 0; i < 10; i++) {
            if (!consumidos[i]) {
                SDL_RenderFillRect(render, &quadrados[i]);
            }
        }

        // Renderiza o quadrado amarelo
        SDL_SetRenderDrawColor(render, 255, 255, 0, 255);
        SDL_RenderFillRect(render, &quadrado);

        // Atualiza a tela
        SDL_RenderPresent(render);

        // Controla FPS (~60 FPS)
        SDL_Delay(16);
    }

    // Limpeza
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(janela);
    SDL_Quit();

    return 0;
}
