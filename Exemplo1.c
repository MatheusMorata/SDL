#include <SDL.h>

int main(int argc, char *argv[]){

    SDL_Window *janela = NULL;
    SDL_Renderer *render = NULL;

    // Verifica erro na inicialização do SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Erro ao iniciar SDL: %s", SDL_GetError());
        return 1;
    }

    // Cria janela
    janela = SDL_CreateWindow(
        "Ola Mundo", // Título da janela
        SDL_WINDOWPOS_CENTERED, // Posição X da janela
        SDL_WINDOWPOS_CENTERED, // Posição Y da janela
        800,600, // Tamanho da janela
        SDL_WINDOW_SHOWN // Indica se a janela está visível
    );

    // Verifica erro na criação da janela
    if(!janela){
        printf("Erro ao criar janela: %s", SDL_GetError());
        return 1;
    }

    // Cria o render
    render = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);

    // Verifica erro na criação do render
    if(!render){
        printf("Erro ao criar render: %s\n", SDL_GetError());
        SDL_DestroyWindow(janela);
        SDL_Quit();
        return 1;
    }

    // Cor de fundo: branco
    SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
    SDL_RenderClear(render);

    // Apresenta na tela
    SDL_RenderPresent(render);

    // Loop de eventos - Espera até o usuário fechar
    SDL_Event event;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }
    }

    // Limpeza
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(janela);
    SDL_Quit();

    return 0;
}
