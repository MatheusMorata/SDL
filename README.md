# SDL

## Exemplo 1

O primeiro exemplo é um pequeno jogo em que o objetivo do jogador é conduzir um quadrado amarelo até colidir com os quadrados vermelhos, consumindo-os. Para vencer, o jogador precisa consumir todos os quadrados vermelhos dentro do limite de 30 segundos. Caso o tempo se esgote antes disso, o jogador será derrotado.

### Como rodar 

```

sudo apt install libsdl2-dev 
gcc -o exemplo Exemplo1.c `sdl2-config --cflags --libs`

```