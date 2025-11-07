local SDL = require("SDL")

local LARGURA = 800
local ALTURA = 600

SDL.init(SDL.flags.Everything)

local janela = SDL.createWindow{
    title = "Quadrado Azul",
    width = LARGURA,
    height = ALTURA,
    flags = { SDL.window.Resizable },
    x = SDL.window.centered,
    y = SDL.window.centered,
}

local renderizador = SDL.createRenderer(janela, -1, 0)

renderizador:setDrawColor({r = 0, g = 0, b = 0})
renderizador:clear()

local quadrado = {
    x = (LARGURA / 2) - 50,
    y = (ALTURA / 2) - 50,
    w = 100,
    h = 100
}
renderizador:setDrawColor({r = 0, g = 0, b = 255})
renderizador:fillRect(quadrado)
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