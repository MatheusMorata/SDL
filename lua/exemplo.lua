local SDL = require("SDL") -- Importando a biblioteca lua-sdl2

local init = SDL.init{SDL.flags.Video} -- Inicializando o sdl

-- Criando a janela
local janela = assert(SDL.createWindow{
    title = 'Exemplo', -- Título
    width = 800, -- Largura
    height = 600, -- Altura
    flags = {SDL.window.Resizable}, 
    x = 400, -- Posição inicial da janela em x
    y = 400, -- Posição inicial da janela em y
})

-- Cria o renderizador
local renderizador = SDL.createRenderer(janela, -1, {
    SDL.rendererFlags.Software
})

local visivel = true
while visivel == true do
    -- Eventos
    for e in SDL.pollEvent() do
        if e.type == SDL.event.Quit then
            visivel = false
        elseif e.type == SDL.event.KeyDown then
            if e.keysym.sym == SDL.key.Escape then
                visivel = false
            end
        end
    end

    renderizador:setDrawColor(0, 0, 0, 255) 
    renderizador:present()
    SDL.delay(16)

end

SDL.quit()