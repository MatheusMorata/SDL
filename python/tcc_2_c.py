import sdl2
import ctypes

sdl2.SDL_Init(sdl2.SDL_INIT_VIDEO)
LARGURA, ALTURA = 800, 600

window = sdl2.SDL_CreateWindow(
    b"Hello World Evento - Padrao C", 
    sdl2.SDL_WINDOWPOS_CENTERED, 
    sdl2.SDL_WINDOWPOS_CENTERED, 
    LARGURA, ALTURA, 
    sdl2.SDL_WINDOW_SHOWN
)
renderer = sdl2.SDL_CreateRenderer(window, -1, sdl2.SDL_RENDERER_ACCELERATED)

executando = True
evento = sdl2.SDL_Event()

while executando:
    if sdl2.SDL_WaitEventTimeout(ctypes.byref(event), 16) != 0:
        if evento.type == sdl2.SDL_QUIT:
            executando = False

sdl2.SDL_DestroyRenderer(renderer)
sdl2.SDL_DestroyWindow(window)
sdl2.SDL_Quit()
