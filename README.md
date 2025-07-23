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
