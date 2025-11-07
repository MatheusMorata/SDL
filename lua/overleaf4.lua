local SDL = require("SDL")
local IMG = require("SDL.image")

local LARGURA = 800
local ALTURA = 600

SDL.init(SDL.flags.Video)
IMG.init(IMG.flags.PNG)

local janela = SDL.createWindow{
    title = "Quadrado com textura",
    width = LARGURA,
    height = ALTURA,
    flags = { SDL.window.Shown },
    x = SDL.window.centered,
    y = SDL.window.centered,
}

local renderizador = SDL.createRenderer(janela, -1, 0)

renderizador:setDrawColor({r = 0, g = 0, b = 0})
renderizador:clear()

local quadrado = {
    x = math.floor(LARGURA / 2 - 50),
    y = math.floor(ALTURA / 2 - 50),
    w = 100,
    h = 100
}

local superficie = IMG.load("textura.png")
local textura = renderizador:createTextureFromSurface(superficie)


renderizador:copy(textura, nil, quadrado)
renderizador:present()

local executando = true
while executando do
    local evento = SDL.waitEvent()
    if evento and evento.type == SDL.event.Quit then
        executando = false
    end
end

textura:destroy()
renderizador:destroy()
janela:destroy()
IMG.quit()
SDL.quit()