local SDL = require("SDL")

local LARGURA = 800
local ALTURA = 600

SDL.init(SDL.flags.Everything)

local janela = SDL.createWindow{
    title = 'Hello World Evento',
    width = LARGURA,
    height = ALTURA,
    flags = {SDL.window.Resizable},
    x = SDL.window.centered,
    y = SDL.window.centered,
}

local renderizador = SDL.createRenderer(janela, -1, 0)

renderizador:setDrawColor({0, 0, 0, 255})
renderizador:clear()
renderizador:present()

local executando = true

while executando do
    local evento = SDL.waitEvent()
    if evento and evento.type == SDL.event.Quit then
        executando = false
    end
end

renderizador:destroy()
janela:destroy()
SDL.quit()