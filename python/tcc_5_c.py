import sdl2
import ctypes

sdl2.SDL_Init(sdl2.SDL_INIT_VIDEO)
LARGURA, ALTURA = 800, 600

window = sdl2.SDL_CreateWindow(
    b"Quadrado Azul - Tempo - Padrao C", 
    sdl2.SDL_WINDOWPOS_CENTERED, sdl2.SDL_WINDOWPOS_CENTERED, 
    LARGURA, ALTURA, sdl2.SDL_WINDOW_SHOWN
)
renderer = sdl2.SDL_CreateRenderer(window, -1, sdl2.SDL_RENDERER_ACCELERATED)
quadrado = sdl2.SDL_Rect((LARGURA // 2) - 50, (ALTURA // 2) - 50, 100, 100)

running = True
event = sdl2.SDL_Event()
ultimoTempo = sdl2.SDL_GetTicks()
velocidade = 100.0

while running:
    if sdl2.SDL_WaitEventTimeout(ctypes.byref(event), 16) != 0:
        if event.type == sdl2.SDL_QUIT:
            running = False
            
    tempoAtual = sdl2.SDL_GetTicks()
    deltaTime = (tempoAtual - ultimoTempo) / 100.0
    ultimoTempo = tempoAtual
    
    quadrado.x = quadrado.x + int(velocidade * deltaTime)
    if quadrado.x > LARGURA:
        quadrado.x = -quadrado.w
            
    sdl2.SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255)
    sdl2.SDL_RenderClear(renderer)
    sdl2.SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255)
    sdl2.SDL_RenderFillRect(renderer, quadrado)
    
    sdl2.SDL_RenderPresent(renderer)
    sdl2.SDL_Delay(16)

sdl2.SDL_DestroyRenderer(renderer)
sdl2.SDL_DestroyWindow(window)
sdl2.SDL_Quit()
