import sys
import sdl2
import sdl2.ext
import ctypes

executando = True

# Inicializando a biblioteca
sdl2.ext.init()

# Criando janela 800x600 centralizada
janela = sdl2.ext.Window("Exemplo", size=(800, 600))
janela.show()

# Criando renderizador
renderizador = sdl2.ext.Renderer(janela)
# Cria quadrado
quadrado = sdl2.SDL_Rect(400, 300, 50, 50)
# Cria fabrica de sprites
fabrica = sdl2.ext.SpriteFactory(sdl2.ext.TEXTURE, renderer=renderizador)
# Carrega a imagem como um sprite
sprite_quadrado = fabrica.from_image("textura.png") 

while executando:
    for e in sdl2.ext.get_events():
        if e.type == sdl2.SDL_QUIT:
            executando = False
            break
        
        elif e.type == sdl2.SDL_KEYDOWN:
            sym = e.key.keysym.sym
            if sym == sdl2.SDLK_d:
                quadrado.x += 10
            elif sym == sdl2.SDLK_a:
                quadrado.x -= 10
            elif sym == sdl2.SDLK_s:
                quadrado.y += 10
            elif sym == sdl2.SDLK_w:
                quadrado.y -= 10
    
    # Limpa a tela (branca)
    cor_fundo = sdl2.ext.Color(255, 255, 255)
    renderizador.clear(cor_fundo)
    renderizador.copy(sprite_quadrado.texture, dstrect=quadrado)
    # Mostra na tela 
    renderizador.present()
    sdl2.SDL_Delay(16)

sdl2.ext.quit()

