local SDL   = require "SDL"

local LARGURA, ALTURA = 800, 600

SDL.init{SDL.flags.Everything}
local janela = SDL.createWindow{
    title = "Hello World", 
    x = SDL.WINDOWPOS_CENTERED,
    y = SDL.WINDOWPOS_CENTERED,
    width = LARGURA,
    height = ALTURA,
    flags = SDL.WINDOW_SHOWN
}
                
local renderizador = SDL.createRenderer(janela, -1, 0)

renderizador:setDrawColor({
    r = 0,
    g = 0,
    b = 0
}) 

renderizador:clear()
renderizador:present()
SDL.delay(3000)