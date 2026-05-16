local SDL   = require "SDL"
local IMG   = require "SDL.image"

local LARGURA, ALTURA = 800, 600

SDL.init{SDL.flags.Everything}
IMG.init{IMG.flags.PNG}

local janela = SDL.createWindow{
    title = "Quadrado com textura", 
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

local quadrado = {
    x = (LARGURA / 2) - 50 , 
    y = (ALTURA / 2) - 50,
    w = 100,
    h = 100
}

local superficie = IMG.load("textura.png")
local textura_quadrado = renderizador:createTextureFromSurface(superficie)
renderizador:copy(textura_quadrado, nil, quadrado)
renderizador:setDrawColor({
    r = 0,
    g = 0,
    b = 255
})

renderizador:fillRect(quadrado)
renderizador:present()

local executando = true

while executando do
    local e = SDL.waitEvent()
    if e.type == SDL.event.Quit then
        executando = false
    end
end 