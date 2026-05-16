#include "pico.h"

int main(void) {
    pico_init(1);

    pico_set_anchor_draw((Pico_Anchor){PICO_CENTER, PICO_MIDDLE});
    pico_output_draw_rect((Pico_Rect){32, 18, 20, 20});

    pico_input_delay(3000);
    pico_init(0);
    return 0;
}