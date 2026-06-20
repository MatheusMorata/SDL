import sdl2
import sdl2.ext

sdl2.ext.init()
LARGURA, ALTURA = 800, 600

window = sdl2.ext.Window("Hello World Evento - Padrao Python", size=(LARGURA, ALTURA))
window.show()
renderer = sdl2.ext.Renderer(window)

executando = True
while executando:
    events = sdl2.ext.get_events()
    for event in events:
        if event.type == sdl2.SDL_QUIT:
            executando = False
sdl2.ext.quit()