local SDL = require("SDL") -- Importando a biblioteca lua-sdl2
local img = require("SDL.image") -- Importando subsistema de imagens

local init = SDL.init{SDL.flags.Video} -- Inicializando o sdl
local formats = img.init{img.flags.PNG} -- Inicializando subssitema de imagens 

local imagem_carro = assert(img.load("img/carro.png"))
local imagem_carro_npc = assert(img.load("img/NPC.png")) 

-- Criando a janela
local janela = assert(SDL.createWindow{
    title = 'Exemplo', -- Título
    width = 800, -- Largura
    height = 600, -- Altura
    flags = {SDL.window.Resizable}, 
    x = SDL.window.centralized, -- Posição inicial da janela em x
    y = SDL.window.centralized, -- Posição inicial da janela em y
})

-- Cria o renderizador
local renderizador = SDL.createRenderer(janela, -1, {
    SDL.rendererFlags.Software
})

local carroJogador = renderizador:createTextureFromSurface(imagem_carro)
local carroNPC = renderizador:createTextureFromSurface(imagem_carro_npc)

local gramaEsquerda = {
    w = 200, -- Largura 
    h = 600, -- Altura
    x = 0, -- Posição no eixo x
    y = 0  -- Posição no eixo y
}

local gramaDireita = {
    w = 200,  
    h = 600, 
    x = 600, 
    y = 0  
}

local faixaD = {
    w = 10,  
    h = 600, 
    x = 400, 
    y = 0  
}

local faixaE = {
    w = 10,  
    h = 600, 
    x = 380,
    y = 0  
}

local carroJogadorDimensoes = {
    w = 100,  
    h = 100,
    x = 450,
    y = 500  
}

local carroNpcDimensoes = {
    w = 100,  
    h = 100,
    x = 200,
    y = 100  
}

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

    -- Asfalto
    renderizador:setDrawColor({r = 120, g = 120, b = 120}) -- Cinza 
    renderizador:clear() -- Limpa tela

    -- grama lado esquerdo
    renderizador:setDrawColor({r = 0, g = 255, b = 0}) -- Verde 
    renderizador:fillRect(gramaEsquerda)
    
    -- grama lado direito
    renderizador:setDrawColor({r = 0, g = 255, b = 0}) -- Verde 
    renderizador:fillRect(gramaDireita)

    -- faixas das via
    renderizador:setDrawColor({r = 255, g = 255, b = 0}) -- Amarelo 
    renderizador:fillRect(faixaD)

    renderizador:setDrawColor({r = 255, g = 255, b = 0}) -- Amarelo 
    renderizador:fillRect(faixaE)

    -- Carros
    renderizador:copy(carroJogador, nil, carroJogadorDimensoes)
    renderizador:copy(carroNPC, nil, carroNpcDimensoes)

    renderizador:present() -- Apresenta
    SDL.delay(16)

end

SDL.quit()