#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "sdl_utils.h"

#define MAX_CLICK_SQUARES 100
#define CLICK_SQUARE_SIZE 20

SDL_Rect click_squares[MAX_CLICK_SQUARES];
int num_click_squares = 0;

void handle_mouse_click_and_draw(SDL_Event* event) {
    if (event->type == SDL_MOUSEBUTTONDOWN) {
        if (event->button.button == SDL_BUTTON_LEFT) {
            if (num_click_squares < MAX_CLICK_SQUARES) {
                click_squares[num_click_squares].x = event->button.x - (CLICK_SQUARE_SIZE / 2);
                click_squares[num_click_squares].y = event->button.y - (CLICK_SQUARE_SIZE / 2);
                click_squares[num_click_squares].w = CLICK_SQUARE_SIZE;
                click_squares[num_click_squares].h = CLICK_SQUARE_SIZE;
                num_click_squares++;
                printf("criado em: (%d, %d)\n", event->button.x, event->button.y);
            } else {
                printf("limite atingido (%d)!\n", MAX_CLICK_SQUARES);
            }
        }
    }
}

int main(int argc, char* argv[]) {
    SDL_Resources game_resources = open_sdl("desenhos de quadrados");
    if (!game_resources.success) {
        printf("%s\n", game_resources.error);
        return 1;
    }

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            handle_mouse_click_and_draw(&event);
        }

        // limpa a tela
        SDL_SetRenderDrawColor(game_resources.render, 255, 255, 255, 255);
        SDL_RenderClear(game_resources.render);

        // loop para desenhar os quadrados
        SDL_SetRenderDrawColor(game_resources.render, 0, 0, 255, 255); // azul
        for (int i = 0; i < num_click_squares; i++) {
            SDL_RenderFillRect(game_resources.render, &click_squares[i]);
        }

        SDL_RenderPresent(game_resources.render);
        SDL_Delay(10);
    }
    close_sdl(game_resources);

    return 0;
}