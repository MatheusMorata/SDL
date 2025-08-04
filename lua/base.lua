local SDL = require("SDL") -- Importando a biblioteca lua-sdl2

local init = SDL.init{SDL.flags.Video} -- Inicializando o sdl


-- Criando a janela
local janela = assert(SDL.createWindow{
    titulo = 'Codigo base',
    largura = 600,
    altura = 800,
    flags = {SDL.window.Shown}, -- Deixa a janela visível
    inicial_x = 400,
    inicial_y = 400,
})

-- Cria o renderizador
local renderizador = SDL.createRenderer(janela, -1, {
    SDL.rendererFlags.Accelerated
})