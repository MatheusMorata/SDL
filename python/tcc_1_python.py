import sdl2
import sdl2.ext

sdl2.ext.init()
LARGURA, ALTURA = 800, 600

window = sdl2.ext.Window("Hello World - Padrao Python", size=(LARGURA, ALTURA))
window.show()
renderer = sdl2.ext.Renderer(window)

renderer.clear(sdl2.ext.Color(0, 0, 0))
renderer.present()

sdl2.SDL_Delay(3000)
sdl2.ext.quit()