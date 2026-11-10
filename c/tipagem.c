#include "pico.h"

int main (void) {
    pico_init(1);
    
    Pico_Color cor = {255, 0, 0, 255};
    pico_set_color_draw(cor);
    pico_output_draw_rect((Pico_Rect){10, 10, 20, 15});
    
    pico_input_delay(1000);
    
    cor = (Pico_Color){0, 255, 0, 255};
    pico_set_color_draw(cor);
    pico_output_draw_rect((Pico_Rect){35, 10, 20, 15});
    
    pico_input_delay(1000);
    pico_init(0);
    return 0;
}
