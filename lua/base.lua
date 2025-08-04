local SDL = require("SDL") -- Importando a biblioteca lua-sdl2

-- Criando a janela
local janela = assert(SDL.createWindow{
    titulo = 'Exemplo',
    largura = 600,
    altura = 800,
    flags = {SDL.Shown},
    inicial_x = 400,
    inicial_y = 400,
})