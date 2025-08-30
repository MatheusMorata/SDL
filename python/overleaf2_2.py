import sys
import sdl2
import sdl2.ext

executando = True

# Inicializando a biblioteca
sdl2.ext.init()

# Criando janela 800x600 centralizada
janela = sdl2.ext.Window("Exemplo", size=(800, 600))
janela.show()

# Cria renderizador e fábrica de sprites
renderizador = sdl2.ext.Renderer(janela)
fabrica = sdl2.ext.SpriteFactory(sdl2.ext.TEXTURE, renderer=renderizador)
# Cria quadrado
quadrado = fabrica.from_image("textura.png")
quadrado.position = (400, 300)

while executando:
    # Evento para fechar a janela [X] ou ALT + F4
    for e in sdl2.ext.get_events():
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

    # Limpa a tela (branca)
    cor_fundo = sdl2.ext.Color(255, 255, 255)
    renderizador.clear(cor_fundo) 
    renderizador.copy(quadrado.texture, dstrect=(quadrado.x, quadrado.y, 50, 50))
    # Mostra na tela
    renderizador.present()
    sdl2.SDL_Delay(16)

sdl2.ext.quit()
