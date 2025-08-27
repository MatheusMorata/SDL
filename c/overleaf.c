#include <SDL2\SDL.h>
#include <stdbool.h>

int main(int argc, char* args[]){
    
    bool executando = true; 
    SDL_Event e;

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

    // Criando quadrado
    SDL_Rect quadrado = {
        400, 300, // Posição x e y
        20, 20 // Largura e Altura
    };

    while(executando){
        // Evento para fechar a janela [X] ou ALT + F4
        while(SDL_PollEvent(&e) != 0){
            if(e.type == SDL_QUIT){
                executando = false;
            }
            // Verifica tecla pressionada
            else if(e.type == SDL_KEYDOWN){
                if(e.key.keysym.sym == SDLK_d){ // Tecla d pressionada
                    quadrado.x += 10;
                }else if(e.key.keysym.sym == SDLK_a){ // Tecla a pressionada
                    quadrado.x -= 10;
                }else if(e.key.keysym.sym == SDLK_s){ // Tecla s pressionada
                    quadrado.y += 10;
                }else if(e.key.keysym.sym == SDLK_w){ // Tecla w pressionada
                    quadrado.y -= 10;
                }
            }
        }
        SDL_SetRenderDrawColor(renderizador, 255, 255, 255, 0); // Colorindo fundo (branco)
        SDL_RenderClear(renderizador); // Limpa o renderizador
        SDL_SetRenderDrawColor(renderizador, 0, 0, 255, 0); // Colorindo quadrado (azul)
        SDL_RenderFillRect(renderizador, &quadrado);
        SDL_RenderPresent(renderizador); // Atualizando a tela
        SDL_Delay(16); // Controle de tempo
    }

    // Liberando recursos
    SDL_DestroyRenderer(renderizador);
    SDL_DestroyWindow(janela);
    SDL_Quit();

    return 0;  
}