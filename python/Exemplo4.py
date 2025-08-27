import sdl2
import ctypes

sdl2.SDL_Init(sdl2.SDL_INIT_VIDEO)
window = sdl2.SDL_CreateWindow(
    b"Janela pySDL2", # Título da janela, precisa ser um bytes-like object (b"...")
    sdl2.SDL_WINDOWPOS_CENTERED, # Posição X
    sdl2.SDL_WINDOWPOS_CENTERED, # Posição Y
    800, # Largura
    600, # Altura
    sdl2.SDL_WINDOW_SHOWN
)
sdl2.SDL_Delay(3000)
sdl2.SDL_DestroyWindow(window)
sdl2.SDL_Quit()