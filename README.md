# SDL - C
## Exemplo 1

O primeiro exemplo é um pequeno jogo em que o objetivo do jogador é conduzir um quadrado amarelo até colidir com os quadrados vermelhos, consumindo-os. Para vencer, o jogador precisa consumir todos os quadrados vermelhos dentro do limite de 30 segundos. Caso o tempo se esgote antes disso, o jogador será derrotado.

## Exemplo 2

Cria quadrados na posição dos cliques do mouse

### Como rodar 

```

sudo apt install libsdl2-dev 
gcc Exemplo1.c sdl_utils.c -o exemplo $(sdl2-config --cflags --libs)

```

# SDL - lua
## Exemplo 

O exemplo desenvolvido em Lua é um experimento voltado para explorar a biblioteca LuaSDL2. Trata-se de um pequeno minigame em que você controla um veículo que está na contramão. O objetivo do jogo é simples, evitar colisões com outros veículos enquanto dirige. O movimento do carro é determinado pelas teclas A e D.

### Como rodar 

```

luarocks install luasdl2 
lua exemplo.lua

```