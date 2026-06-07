import sdl2
import ctypes

LARGURA = 800
ALTURA = 600

sdl2.SDL_Init(sdl2.SDL_INIT_VIDEO)
window = sdl2.SDL_CreateWindow(
    b"Janela PySDL2 - Padrao C", 
    sdl2.SDL_WINDOWPOS_CENTERED, 
    sdl2.SDL_WINDOWPOS_CENTERED, 
    LARGURA,
    ALTURA, 
    sdl2.SDL_WINDOW_SHOWN
)
renderer = sdl2.SDL_CreateRenderer(window, -1, sdl2.SDL_RENDERER_ACCELERATED)

running = True
event = sdl2.SDL_Event()

while running:
    while sdl2.SDL_PollEvent(ctypes.byref(event)) != 0:
        if event.type == sdl2.SDL_QUIT:
            running = False
            
    sdl2.SDL_RenderClear(renderer)
    sdl2.SDL_RenderPresent(renderer)
    
    sdl2.SDL_Delay(16)

sdl2.SDL_DestroyRenderer(renderer)
sdl2.SDL_DestroyWindow(window)
sdl2.SDL_Quit()