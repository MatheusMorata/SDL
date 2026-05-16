#include "pico.h"

int main(void) {
    pico_init(1);
    pico_set_color_draw((Pico_Color){255, 0, 0, 255});
    pico_output_draw_rect((Pico_Rect){10, 10, 20, 20});
    pico_input_delay(3000);
    pico_init(0);
    return 0;
}