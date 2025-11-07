local SDL = require("SDL")

local LARGURA = 800
local ALTURA = 600

SDL.init(SDL.flags.Everything)

local janela = SDL.createWindow{
    title = 'Exemplo', 
    width = LARGURA, 
    height = ALTURA, 
    flags = {SDL.window.Resizable}, 
    x = SDL.window.centralized, 
    y = SDL.window.centralized, 
}

local renderizador = SDL.createRenderer(janela, -1, 0)

renderizador:setDrawColor({0, 0, 0, 255})
renderizador:clear()
renderizador:present()

SDL.delay(3000)

renderizador:destroy()
janela:destroy()
SDL.quit()