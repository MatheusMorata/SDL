#include "pico.h"

int main(void)
{
    pico_init(1);

    pico_set_size(
        (Pico_Dim){800, 600},
        (Pico_Dim){800, 600}
    );

    pico_set_color_clear((Pico_Color){0, 0, 0, 255});

    pico_set_color_draw((Pico_Color){255, 0, 0, 255});

    pico_set_anchor_draw((Pico_Anchor){PICO_CENTER, PICO_MIDDLE});

    Pico_Pos center = pico_pos(
        (Pico_Pct){50, 50}
    );

    pico_output_clear();

    pico_output_draw_rect(
        (Pico_Rect){
            center.x,
            center.y,
            200,
            100
        }
    );

    pico_output_present();
    pico_input_delay(3000);

    pico_init(0);
    return 0;
}
