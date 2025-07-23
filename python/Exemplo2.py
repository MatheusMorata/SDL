import sdl2
import ctypes
import sys
from utils import open_sdl, close_sdl, SDLResources

MAX_CLICK_SQUARES = 100
CLICK_SQUARE_SIZE = 20

click_squares: list[sdl2.SDL_Rect] = []

def handle_mouse_click_and_draw(event: sdl2.SDL_Event):
    if event.type == sdl2.SDL_MOUSEBUTTONDOWN:
        if event.button.button == sdl2.SDL_BUTTON_LEFT:
            if len(click_squares) < MAX_CLICK_SQUARES:
                square_x = event.button.x - (CLICK_SQUARE_SIZE // 2)
                square_y = event.button.y - (CLICK_SQUARE_SIZE // 2)
                new_square = sdl2.SDL_Rect(square_x, square_y, CLICK_SQUARE_SIZE, CLICK_SQUARE_SIZE)
                click_squares.append(new_square)
                print(f"criado em: ({event.button.x}, {event.button.y})")
            else:
                print(f"limite atingido ({MAX_CLICK_SQUARES})!")

def main():
    game_resources = open_sdl("Desenhos de Quadrados PySDL2")
    if not game_resources.success:
        print(game_resources.error)
        return 1

    running = True
    event = sdl2.SDL_Event() # Objeto SDL_Event para capturar eventos

    while running:
        while sdl2.SDL_PollEvent(ctypes.byref(event)) != 0:
            if event.type == sdl2.SDL_QUIT:
                running = False
            handle_mouse_click_and_draw(event)

        # limpa a tela
        sdl2.SDL_SetRenderDrawColor(game_resources.renderer, 255, 255, 255, 255)
        sdl2.SDL_RenderClear(game_resources.renderer)

        # loop para desenhar os quadrados clicados
        sdl2.SDL_SetRenderDrawColor(game_resources.renderer, 0, 0, 255, 255)
        for i in range(len(click_squares)):
            sdl2.SDL_RenderFillRect(game_resources.renderer, ctypes.byref(click_squares[i]))

        sdl2.SDL_RenderPresent(game_resources.renderer)
        sdl2.SDL_Delay(10)

    close_sdl(game_resources)

    return 0

if __name__ == "__main__":
    sys.exit(main())