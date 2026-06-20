import sdl2
import sdl2.ext

LARGURA, ALTURA = 800, 600
sdl2.ext.init()

janela = sdl2.ext.Window("Quadrado com textura em Python - Padrao Python", size=(LARGURA, ALTURA))
janela.show()
renderizador = sdl2.ext.Renderer(janela)

quadrado = sdl2.SDL_Rect((LARGURA // 2) - 50, (ALTURA // 2) - 50, 100, 100)
fabrica = sdl2.ext.SpriteFactory(sdl2.ext.TEXTURE, renderer=renderizador)
sprite_quadrado = fabrica.from_image("textura.png")

executando = True
while executando:
    events = sdl2.ext.get_events()
    for event in events:
        if event.type == sdl2.SDL_QUIT:
            executando = False
            
    renderizador.clear(sdl2.ext.Color(0, 0, 0))
    renderizador.copy(sprite_quadrado, dstrect=quadrado)
    renderizador.present()
sdl2.ext.quit()