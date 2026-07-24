local SDL   = require "SDL"

local LARGURA, ALTURA = 800, 600

SDL.init{SDL.flags.Everything}

local janela = SDL.createWindow{
    title = "Quadrado azul animado", 
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

local executando = true
local evento = nil
local quadrado = {
    w = (LARGURA / 2) - 50, 
    h = (ALTURA / 2) - 50, 
    x = 100, 
    y = 100
}
local ultimoTempo = SDL.getTicks()
local tempoAtual = 0
local velocidade = 100

while executando do
    evento = SDL.waitEvent(16)
    
    if evento and evento.type == SDL.event.Quit then
        executando = false
    end

    tempoAtual = SDL.getTicks()
    deltaTime = (tempoAtual - ultimoTempo) / 100
    ultimoTempo = tempoAtual

    quadrado.x = quadrado.x + (velocidade * deltaTime)

    if quadrado.x > LARGURA then
        quadrado.x = -quadrado.w
    end

    renderizador:setDrawColor({
        r = 0,
        g = 0, 
        b = 0
    })
    renderizador:clear()
    renderizador:setDrawColor({
        r = 0,
        g = 0,
        b = 255
    })
    renderizador:fillRect(quadrado)
    
    renderizador:present()
end