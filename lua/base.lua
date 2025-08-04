local SDL = require("SDL") -- Importando a biblioteca lua-sdl2

local init = SDL.init{SDL.flags.Video} -- Inicializando o sdl


-- Criando a janela
local janela = assert(SDL.createWindow{
    titulo = 'Codigo base',
    largura = 1280,
    altura = 800,
    flags = {SDL.window.Resizable}, -- Deixa a janela visível
    inicial_x = 400,
    inicial_y = 400,
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
        elseif e.type == SDL.event.KeyDown then
            if e.keysym.sym == SDL.key.Escape then
                visivel = false
            end
        end
    end
end

-- Libera recursos
renderizador:destroy()
janela:destroy()
SDL.quit()