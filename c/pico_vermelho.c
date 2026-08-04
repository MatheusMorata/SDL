#include "pico.h"

int main(void) {
    pico_init(1);

    pico_set_size((Pico_Dim){640, 360}, (Pico_Dim){640, 360});

    pico_set_color_clear((Pico_Color){0, 0, 0, 255});
    pico_output_clear();

    pico_set_color_draw((Pico_Color){255, 0, 0, 255});
    pico_output_draw_rect((Pico_Rect){10, 10, 20, 20});

    pico_output_present();

    pico_input_delay(3000);

    pico_init(0);
    return 0;
}
