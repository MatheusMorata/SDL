import sdl2
import sdl2.ext # Contém algumas classes e helpers úteis
import random
import time
import sys
import ctypes
from utils import open_sdl, close_sdl

# class SDLResources:
#     def __init__(self):
#         self.window = None
#         self.renderer = None
#         self.success = False
#         self.error = ""

# def open_sdl(window_title: str) -> SDLResources:
#     """
#     Inicializa SDL, cria janela e renderizador.
#     Retorna um objeto SDLResources com o resultado.
#     """
#     resources = SDLResources()

#     # Inicializa o SDL
#     if sdl2.SDL_Init(sdl2.SDL_INIT_VIDEO) < 0:
#         resources.error = f"Erro ao iniciar SDL: {sdl2.SDL_GetError().decode('utf-8')}"
#         return resources

#     # Cria a janela
#     resources.window = sdl2.SDL_CreateWindow(
#         window_title.encode('utf-8'), # utf-8 obrigatório
#         sdl2.SDL_WINDOWPOS_CENTERED,
#         sdl2.SDL_WINDOWPOS_CENTERED,
#         800, 600,
#         sdl2.SDL_WINDOW_SHOWN
#     )
#     if not resources.window:
#         resources.error = f"Erro ao criar window: {sdl2.SDL_GetError().decode('utf-8')}"
#         sdl2.SDL_Quit()
#         return resources

#     # Cria o renderizador
#     resources.renderer = sdl2.SDL_CreateRenderer(
#         resources.window,
#         -1, # Índice do driver de renderização (-1 para o primeiro disponível)
#         sdl2.SDL_RENDERER_ACCELERATED | sdl2.SDL_RENDERER_PRESENTVSYNC # Acelerado por hardware e VSync
#     )
#     if not resources.renderer:
#         resources.error = f"Erro ao criar render: {sdl2.SDL_GetError().decode('utf-8')}"
#         sdl2.SDL_DestroyWindow(resources.window)
#         sdl2.SDL_Quit()
#         return resources

#     resources.success = True
#     return resources

# def close_sdl(resources: SDLResources):
#     """
#     Libera os recursos SDL.
#     """
#     if resources.renderer:
#         sdl2.SDL_DestroyRenderer(resources.renderer)
#     if resources.window:
#         sdl2.SDL_DestroyWindow(resources.window)
#     sdl2.SDL_Quit()

# --- Funções de Lógica do Jogo (equivalente às do main.c) ---

# Função para verificar colisão entre dois retângulos (quadrados)
def colisao_rects(rect_a: sdl2.SDL_Rect, rect_b: sdl2.SDL_Rect) -> bool:
    return (rect_a.x < rect_b.x + rect_b.w and
            rect_a.x + rect_a.w > rect_b.x and
            rect_a.y < rect_b.y + rect_b.h and
            rect_a.y + rect_a.h > rect_b.y)

# Função para marcar quadrados vermelhos como consumidos após colisão
def colisao(quadrado_jogador: sdl2.SDL_Rect, quadrados_vermelhos: list[sdl2.SDL_Rect], consumidos: list[int]):
    for i in range(len(quadrados_vermelhos)):
        if not consumidos[i] and colisao_rects(quadrado_jogador, quadrados_vermelhos[i]):
            consumidos[i] = 1  # Marca como consumido

def main():
    sdl_resources = open_sdl("Quadradinhos Python")
    if not sdl_resources.success:
        print(sdl_resources.error)
        return 1

    random.seed(time.time())

    # Posição inicial do quadrado amarelo
    x, y = 400, 300
    tamanho = 10
    quadrado_jogador = sdl2.SDL_Rect(x, y, tamanho, tamanho)

    # Inicializa os quadrados vermelhos e vetor de consumidos
    num_quadrados_vermelhos = 10
    consumidos = [0] * num_quadrados_vermelhos
    quadrados_vermelhos = []
    for _ in range(num_quadrados_vermelhos):
        qx = random.randint(0, 800 - tamanho)
        qy = random.randint(0, 600 - tamanho)
        quadrados_vermelhos.append(sdl2.SDL_Rect(qx, qy, tamanho, tamanho))

    running = True
    event = sdl2.SDL_Event()

    # Marca o tempo inicial para o cronômetro
    tempo_inicio = time.time() # time.time() retorna float em segundos desde a época Unix

    while running:
        # Verifica se os 30 segundos já passaram
        agora = time.time()
        if (agora - tempo_inicio) >= 30:
            print("VOCÊ PERDEU!")
            running = False
            break # Break do while loop

        # Verifica se o jogador venceu (todos os quadrados foram consumidos)
        venceu = True
        for i in range(num_quadrados_vermelhos):
            if consumidos[i] == 0:
                venceu = False  # Ainda restam quadrados vermelhos
                break
        
        if venceu:
            print("VOCÊ GANHOU!")
            running = False
            break # Break do while loop

        # Processa os eventos (teclado e fechamento de janela)
        while sdl2.SDL_PollEvent(ctypes.byref(event)) != 0: # sdl2.SDL_PollEvent retorna 0 se não há eventos
            if event.type == sdl2.SDL_QUIT:
                running = False
            elif event.type == sdl2.SDL_KEYDOWN:
                sym = event.key.keysym.sym # Código da tecla pressionada
                if sym == sdl2.SDLK_w:
                    y -= 10 # Move para cima
                elif sym == sdl2.SDLK_s:
                    y += 10 # Move para baixo
                elif sym == sdl2.SDLK_a:
                    x -= 10 # Move para esquerda
                elif sym == sdl2.SDLK_d:
                    x += 10 # Move para direita

        # Atualiza a posição do quadrado amarelo
        quadrado_jogador.x = x
        quadrado_jogador.y = y

        # Verifica colisão com os quadrados vermelhos
        colisao(quadrado_jogador, quadrados_vermelhos, consumidos)

        # Limpa a tela (define cor de fundo branca)
        sdl2.SDL_SetRenderDrawColor(sdl_resources.renderer, 255, 255, 255, 255)
        sdl2.SDL_RenderClear(sdl_resources.renderer)

        # Desenha os quadrados vermelhos restantes
        for i in range(num_quadrados_vermelhos):
            if not consumidos[i]:
                sdl2.SDL_SetRenderDrawColor(sdl_resources.renderer, 255, 0, 0, 255)
                # RenderFillRect espera um ponteiro para SDL_Rect
                # isso é necessário pq o PySDL2 é um binding para a biblioteca SDL em C
                sdl2.SDL_RenderFillRect(sdl_resources.renderer, ctypes.byref(quadrados_vermelhos[i]))

        # Desenha o quadrado amarelo (jogador)
        sdl2.SDL_SetRenderDrawColor(sdl_resources.renderer, 255, 255, 0, 255)
        sdl2.SDL_RenderFillRect(sdl_resources.renderer, ctypes.byref(quadrado_jogador)) # ponteiro para SDL_Rect

        # Atualiza a tela
        sdl2.SDL_RenderPresent(sdl_resources.renderer)

        sdl2.SDL_Delay(16)  # 60 FPS

    close_sdl(sdl_resources)
    return 0

if __name__ == "__main__":
    sys.exit(main())