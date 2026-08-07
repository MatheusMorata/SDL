#include <pico.h>

int main(void) {
    pico_init(1);
    pico_set_size(
        (Pico_Dim){800,600},
        (Pico_Dim){160,120}
    );

    pico_set_grid(1);

    while (1) {
        pico_output_clear();

        pico_output_draw_rect(
            (Pico_Rect){40,30,80,60}
        );

        pico_output_present();
        pico_input_event(NULL, PICO_ANY);
    }

    pico_init(0);
    return 0;
}
