import sdl2
import sdl2.ext

sdl2.ext.init()
LARGURA, ALTURA = 800, 600

window = sdl2.ext.Window("Quadrado Azul - Tempo - Padrao Python", size=(LARGURA, ALTURA))
window.show()
renderer = sdl2.ext.Renderer(window)
quadrado = sdl2.SDL_Rect((LARGURA // 2) - 50, (ALTURA // 2) - 50, 100, 100)

running = True
ultimoTempo = sdl2.SDL_GetTicks()
velocidade = 100.0

while running:
    events = sdl2.ext.get_events()
    for event in events:
        if event.type == sdl2.SDL_QUIT:
            running = False
            
    tempoAtual = sdl2.SDL_GetTicks()
    deltaTime = (tempoAtual - ultimoTempo) / 100.0
    ultimoTempo = tempoAtual
    
    quadrado.x = quadrado.x + int(velocidade * deltaTime)
    if quadrado.x > LARGURA:
        quadrado.x = -quadrado.w
            
    renderer.clear(sdl2.ext.Color(0, 0, 0))
    renderer.fill(quadrado, sdl2.ext.Color(0, 0, 255))
    renderer.present()
    sdl2.SDL_Delay(16)
sdl2.ext.quit()