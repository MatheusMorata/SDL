local SDL = require("SDL")

local LARGURA = 800
local ALTURA = 600

SDL.init(SDL.flags.Video)

local janela = SDL.createWindow{
    title = "Quadrado Azul - Tempo",
    width = LARGURA,
    height = ALTURA,
    flags = { SDL.window.Shown },
    x = SDL.window.centered,
    y = SDL.window.centered,
}

local renderizador = SDL.createRenderer(janela, -1, 0)

local quadrado = {
    x = math.floor(LARGURA / 2 - 50),
    y = math.floor(ALTURA / 2 - 50),
    w = 100,
    h = 100
}

local executando = true
local ultimoTempo = SDL.getTicks()
local velocidade = 100.0 

while executando do
    for evento in SDL.pollEvent() do
        if evento.type == SDL.event.Quit then
            executando = false
        end
    end

    local tempoAtual = SDL.getTicks()
    local deltaTime = (tempoAtual - ultimoTempo) / 100.0
    ultimoTempo = tempoAtual

    quadrado.x = quadrado.x + (velocidade * deltaTime)
    if quadrado.x > LARGURA then
        quadrado.x = -quadrado.w
    end

    renderizador:setDrawColor({r = 0, g = 0, b = 0})
    renderizador:clear()
    renderizador:setDrawColor({r = 0, g = 0, b = 255})
    renderizador:fillRect(quadrado)
    renderizador:present()

end

renderizador:destroy()
janela:destroy()
SDL.quit()