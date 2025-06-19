#include <SDL.h>
#include <stdio.h>
#include <time.h>

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
        SDL_WINDOWPOS_CENTERED, // Posição x inicial
        SDL_WINDOWPOS_CENTERED, // Posição y inicial
        800, 600, // Tamanho inicial
        SDL_WINDOW_SHOWN // Exibir a janela
    );

    // Verifica erro ao criar janela
    if (!janela) {
        printf("Erro ao criar janela: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Cria o render
    render = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);
    
    // Verifica erro ao criar render
    if (!render) {
        printf("Erro ao criar render: %s\n", SDL_GetError());
        SDL_DestroyWindow(janela);
        SDL_Quit();
        return 1;
    }

    // Posição e tamanho inicial do quadrado
    int x = 400;
    int y = 300;
    int tamanho = 30;
    SDL_Rect quadrado = { x, y, tamanho, tamanho };

    // Quadrados não interativos
    SDL_Rect quadrados[10];
    for (int i = 0; i < 10; i++) {
        quadrados[i].x = rand() % 800;  
        quadrados[i].y = rand() % 600;          
        quadrados[i].w = 10;           
        quadrados[i].h = 10;           
    }

    int rodando = 1;
    SDL_Event event;

    while (rodando) {
        // Processa eventos
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                rodando = 0;
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_w:
                        y -= 10; // Move para cima
                        break;
                    case SDLK_s:
                        y += 10; // Move para baixo
                        break;
                    case SDLK_a:
                        x -= 10; // Move para esquerda
                        break;
                    case SDLK_d:
                        x += 10; // Move para direita
                        break;
                }
            }
        }

        // Atualiza a posição do quadrado
        quadrado.x = x;
        quadrado.y = y;

        // Limpa a tela (cor de fundo branca)
        SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
        SDL_RenderClear(render);

        for(int i = 0; i <= 10; i++){
            SDL_SetRenderDrawColor(render, 255, 0, 0, 255); // Cor: Vermelho 
            SDL_RenderFillRect(render, &quadrados[i]);
        }

        // Desenha o quadrado amarelo
        SDL_SetRenderDrawColor(render, 255, 255, 0, 255); // Cor: Amarelo 
        SDL_RenderFillRect(render, &quadrado);

        // Apresenta na tela
        SDL_RenderPresent(render);

        SDL_Delay(16); // Aproximadamente 60 FPS
    }

    // Limpeza
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(janela);
    SDL_Quit();

    return 0;
}
