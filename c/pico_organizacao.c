#include "pico.h"
#include <math.h>

int main(void) {
    Pico_Color preto = {0, 0, 0, 255};
    Pico_Color vermelho = {255, 0, 0, 255};

    pico_init(1);

    pico_set_color_clear(preto);
    pico_set_color_draw(vermelho);

    pico_output_clear();

    Pico_Pos quadrado[20 * 15];
    int index = 0;

    for (int y = 10; y <= 24; y++) {
        for (int x = 10; x <= 29; x++) {
            quadrado[index].x = x;
            quadrado[index].y = y;
            index++;
        }
    }

    Pico_Pos linha[64];

    for (int i = 0; i <= 63; i++) {
        linha[i].x = i;
        linha[i].y = (int)floor(i * 35.0 / 63.0);
    }

    pico_output_draw_pixels(quadrado, 20 * 15);
    pico_output_draw_pixels(linha, 64);

    pico_input_delay(5000);

    pico_init(0);

    return 0;
}