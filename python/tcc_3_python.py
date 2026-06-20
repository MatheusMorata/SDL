import sdl2
import sdl2.ext

sdl2.ext.init()
LARGURA, ALTURA = 800, 600

window = sdl2.ext.Window("Quadrado Azul - Padrao Python", size=(LARGURA, ALTURA))
window.show()
renderer = sdl2.ext.Renderer(window)
quadrado = sdl2.SDL_Rect((LARGURA // 2) - 50, (ALTURA // 2) - 50, 100, 100)

executando = True
while executando:
    events = sdl2.ext.get_events()
    for event in events:
        if event.type == sdl2.SDL_QUIT:
            executando = False
            
    renderer.clear(sdl2.ext.Color(0, 0, 0))
    renderer.fill(quadrado, sdl2.ext.Color(0, 0, 255))
    renderer.present()
sdl2.ext.quit()