import sdl2
import sdl2.sdlimage
import ctypes

LARGURA, ALTURA = 800, 600
sdl2.SDL_Init(sdl2.SDL_INIT_EVERYTHING)
sdl2.sdlimage.IMG_Init(sdl2.sdlimage.IMG_INIT_PNG)

janela = sdl2.SDL_CreateWindow(
    b"Quadrado com textura - Padrao C",
    sdl2.SDL_WINDOWPOS_CENTERED, sdl2.SDL_WINDOWPOS_CENTERED,
    LARGURA, ALTURA, sdl2.SDL_WINDOW_SHOWN
)
renderizador = sdl2.SDL_CreateRenderer(janela, -1, sdl2.SDL_RENDERER_ACCELERATED)

quadrado = sdl2.SDL_Rect((LARGURA // 2) - 50, (ALTURA // 2) - 50, 100, 100)
superficie = sdl2.sdlimage.IMG_Load(b"textura.png")
textura_quadrado = sdl2.SDL_CreateTextureFromSurface(renderizador, superficie)

executando = True
evento = sdl2.SDL_Event()
while executando:
    while sdl2.SDL_PollEvent(ctypes.byref(evento)) != 0:
        if evento.type == sdl2.SDL_QUIT:
            executando = False
            
    sdl2.SDL_SetRenderDrawColor(renderizador, 0, 0, 0, 255)
    sdl2.SDL_RenderClear(renderizador)
    sdl2.SDL_RenderCopy(renderizador, textura_quadrado, None, quadrado)
    sdl2.SDL_RenderPresent(renderizador)

sdl2.SDL_FreeSurface(superficie)
sdl2.SDL_DestroyTexture(textura_quadrado)
sdl2.SDL_DestroyRenderer(renderizador)
sdl2.SDL_DestroyWindow(janela)
sdl2.sdlimage.IMG_Quit()
sdl2.SDL_Quit()