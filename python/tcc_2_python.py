import sdl2
import sdl2.ext

LARGURA = 800
ALTURA = 600

sdl2.ext.init()

janela = sdl2.ext.Window(
    "Quadrado com textura em Python (Padrao Ext)",
    size=(LARGURA, ALTURA)
)
janela.show()

renderizador = sdl2.ext.Renderer(janela)

cor_fundo = sdl2.ext.Color(0, 0, 0)
renderizador.clear(cor_fundo)

quadrado = sdl2.SDL_Rect((LARGURA // 2) - 50, (ALTURA // 2) - 50, 100, 100)
fabrica = sdl2.ext.SpriteFactory(sdl2.ext.TEXTURE, renderer=renderizador)
sprite_quadrado = fabrica.from_image("textura.png")
renderizador.copy(sprite_quadrado, dstrect=quadrado)
renderizador.present()

executando = True
evento = sdl2.SDL_Event()
while executando:
    sdl2.SDL_WaitEvent(evento)
    if evento.type == sdl2.SDL_QUIT:
        executando = False
sdl2.ext.quit()