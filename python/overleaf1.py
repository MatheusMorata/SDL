import sdl2
import sdl2.sdlimage
import ctypes

executando = True
e = sdl2.SDL_Event()

# Inicializando a biblioteca
sdl2.SDL_Init(sdl2.SDL_INIT_EVERYTHING)

# Criando janela 800x600 centralizada
janela = sdl2.SDL_CreateWindow(
    b"Exemplo", 
    sdl2.SDL_WINDOWPOS_CENTERED, 
    sdl2.SDL_WINDOWPOS_CENTERED, 
    800, 600, 
    sdl2.SDL_WINDOW_SHOWN
)

# Criando renderizador
renderizador = sdl2.SDL_CreateRenderer(janela, -1, 0)
# Criando quadrado
quadrado = sdl2.SDL_Rect(400, 300, 50, 50) 
superficie = sdl2.sdlimage.IMG_Load(b"textura.png") # Carrega a imagem em uma "superficie" temporaria
textura_quadrado = sdl2.SDL_CreateTextureFromSurface(renderizador, superficie) # Cria uma textura otimizada para o renderizador a partir da superficie
sdl2.SDL_FreeSurface(superficie) # Libera a superficie temporaria, pois nao precisamos mais dela

while executando:
    # Evento para fechar a janela [X] ou ALT + F4
    while sdl2.SDL_PollEvent(ctypes.byref(e)) != 0:
        if e.type == sdl2.SDL_QUIT:
            executando = False
            break
        # Verifica tecla pressionada
        elif e.type == sdl2.SDL_KEYDOWN:
            sym = e.key.keysym.sym
            if sym == sdl2.SDLK_d:
                quadrado.x += 10
            elif sym == sdl2.SDLK_a:
                quadrado.x -= 10
            elif sym == sdl2.SDLK_s:
                quadrado.y += 10
            elif sym == sdl2.SDLK_w:
                quadrado.y -= 10
    sdl2.SDL_SetRenderDrawColor(renderizador, 255, 255, 255, 0) # Colorindo fundo (branco)
    sdl2.SDL_RenderClear(renderizador) # Limpa o renderizador
    sdl2.SDL_RenderCopy(renderizador, textura_quadrado, None, ctypes.byref(quadrado)) # Desenha a textura no lugar do quadrado colorido
    sdl2.SDL_RenderPresent(renderizador) # Atualizando a tela
    sdl2.SDL_Delay(16) # Controle de tempo

# Liberando recursos
sdl2.SDL_DestroyRenderer(renderizador)
sdl2.SDL_DestroyWindow(janela)
sdl2.SDL_Quit()