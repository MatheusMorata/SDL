local SDL = require("SDL") -- Importando a biblioteca lua-sdl2
local img = require("SDL.image") -- Importando subsistema de imagens

local init = SDL.init{SDL.flags.Video} -- Inicializando o sdl
local formats = img.init{img.flags.PNG} -- Inicializando subssitema de imagens 

local function colisao(a, b)
    return a.x < b.x + b.w and
           a.x + a.w > b.x and
           a.y + 10 < b.y + b.h and
           a.y + a.h > b.y
end

-- Imagens
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

-- Texturas
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
    x = 250,  
    y = math.random(-800, 0) 
}

local carroNpcDimensoes2 = {
    w = 100,
    h = 100,
    x = 450,  
    y = math.random(-800, 0)
}


local npcRotacao = 90

local visivel = true
while visivel == true do

    SDL.pumpEvents()

    -- Eventos
    for e in SDL.pollEvent() do
        -- Fecha a janela ao clicar no X
        if e.type == SDL.event.Quit then
            visivel = false    
        end
    end

    local tecla = SDL.getKeyboardState()

    -- Teclado
    if tecla[SDL.scancode.D] then
        carroJogadorDimensoes.x = carroJogadorDimensoes.x + 5
    elseif tecla[SDL.scancode.A] then
        carroJogadorDimensoes.x = carroJogadorDimensoes.x - 5
    end

    -- Carro não vai para grama
    if carroJogadorDimensoes.x > 500 then
        carroJogadorDimensoes.x = 500
    elseif carroJogadorDimensoes.x < 200 then
        carroJogadorDimensoes.x = 200
    end

    -- Movimento em y dos carros do NPC
    carroNpcDimensoes.y = carroNpcDimensoes.y + 6
    carroNpcDimensoes2.y = carroNpcDimensoes2.y + 6 
    
    -- Carro NPC volta ao ponto de partida ao sair da tela
    if carroNpcDimensoes.y > 900 then
        carroNpcDimensoes.y = math.random(-800, 0)
    end

    if carroNpcDimensoes2.y > 900 then
        carroNpcDimensoes2.y = math.random(-800, 0)
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
    renderizador:copyEx({
        texture = carroNPC,
        source = nil,
        destination = carroNpcDimensoes,
        angle = npcRotacao,
        center = {                             
            x = carroNpcDimensoes.w/2,
            y = carroNpcDimensoes.h/2
        },
        flip = SDL.rendererFlip.Horizontal
    })
    renderizador:copyEx({
        texture = carroNPC,
        source = nil,
        destination = carroNpcDimensoes2,
        angle = npcRotacao,
        center = {                             
            x = carroNpcDimensoes.w/2,
            y = carroNpcDimensoes.h/2
        },
        flip = SDL.rendererFlip.Horizontal
    })

    -- Fecha o jogo se houver colisão
    if colisao(carroJogadorDimensoes,carroNpcDimensoes) or colisao(carroJogadorDimensoes,carroNpcDimensoes2) then
        visivel = false
    end

    renderizador:present() -- Apresenta
    SDL.delay(16)

end

SDL.quit()