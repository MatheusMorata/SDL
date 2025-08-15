local SDL = require("SDL") -- Importando a biblioteca lua-sdl2

local init = SDL.init{SDL.flags.Video} -- Inicializando o sdl


-- Criando a janela
local janela = assert(SDL.createWindow{
    title = 'Codigo base', -- Título
    width = 800, -- Largura
    height = 600, -- Altura
    flags = {SDL.window.Resizable}, 
    x = SDL.window.PosCentered, -- Posição inicial da janela em x (centralizado)
    y = SDL.window.PosCentered, -- Posição inicial da janela em y (centralizado)
})

-- Cria o renderizador
local renderizador = SDL.createRenderer(janela, -1, {
    SDL.rendererFlags.Accelerated
})

local visivel = true
while visivel == true do
    -- Eventos
    for e in SDL.pollEvent() do
        if e.type == SDL.event.Quit then
            visivel = false
        end
    end
end

SDL.quit()