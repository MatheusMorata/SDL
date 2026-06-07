import sdl2
import sdl2.ext

sdl2.ext.init()

window = sdl2.ext.Window("Janela PySDL2 - Padrao Python", size=(800, 600))
window.show()
renderer = sdl2.ext.Renderer(window)

running = True
while running:
    events = sdl2.ext.get_events()
    for event in events:
        if event.type == sdl2.SDL_QUIT:
            running = False
            
    renderer.clear()
    renderer.present()
    
    sdl2.SDL_Delay(16)

sdl2.ext.quit()