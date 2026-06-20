import sdl2

sdl2.SDL_Init(sdl2.SDL_INIT_VIDEO)
LARGURA, ALTURA = 800, 600

window = sdl2.SDL_CreateWindow(
    b"Hello World - Padrao C", 
    sdl2.SDL_WINDOWPOS_CENTERED, 
    sdl2.SDL_WINDOWPOS_CENTERED, 
    LARGURA, ALTURA, 
    sdl2.SDL_WINDOW_SHOWN
)
renderer = sdl2.SDL_CreateRenderer(window, -1, sdl2.SDL_RENDERER_ACCELERATED)

sdl2.SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255)
sdl2.SDL_RenderClear(renderer)
sdl2.SDL_RenderPresent(renderer)

sdl2.SDL_Delay(3000)

sdl2.SDL_DestroyRenderer(renderer)
sdl2.SDL_DestroyWindow(window)
sdl2.SDL_Quit()