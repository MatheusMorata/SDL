import sdl2
import sdl2.ext

sdl2.ext.init()
window = sdl2.ext.Window("Janela pySDL2", size=(800, 600))
window.show()
sdl2.SDL_Delay(30000)
window.hide()
sdl2.ext.quit()