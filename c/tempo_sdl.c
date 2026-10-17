#include "pico.h"

int main(void) {
    pico_init(1);
    pico_set_title("Quadrado Azul - Tempo");
    pico_set_size((Pico_Dim){800, 600}, (Pico_Dim){800, 600});

    pico_set_anchor_draw((Pico_Anchor){PICO_CENTER, PICO_MIDDLE});
    Pico_Pos centro = pico_pos((Pico_Pct){50, 50});
    Pico_Rect quadrado = {centro.x, centro.y, 100, 100};
    Pico_Event event;

    while (1) {
        pico_input_event_timeout(&event, PICO_ANY, 16);
        if (event.type == PICO_QUIT) {
            break;
        }

        quadrado.x += 2;
        if (quadrado.x > 800) {
            quadrado.x = -quadrado.w;
        }

        pico_output_clear();
        pico_set_color_draw((Pico_Color){0, 0, 255, 255});
        pico_output_draw_rect(quadrado);
    }

    pico_init(0);
    return 0;
}
