#include "pico.h"

int main(void) {
    pico_init(1);
    pico_set_color_draw((Pico_Color){255, 0, 0, 255});

    for (int i = 0; i < 5; i++) {
        pico_output_draw_rect((Pico_Rect){2 + i * 12, 10, 10, 10});
        pico_input_delay(500);   
    }

    pico_init(0);
    return 0;
}