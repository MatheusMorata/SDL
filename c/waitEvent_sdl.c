#include "pico.h"

int main(void) {
    pico_init(1);
    pico_set_title("Hello World Wait Event Timeout");
    Pico_Event evento;
    while (1) {
        pico_output_clear();
        pico_output_present();
        // Equivalente direto de SDL_WaitEventTimeout(&evento, 16)
        pico_input_event_timeout(&evento, PICO_ANY, 16);
        if (evento.type == PICO_QUIT) {
            break;
        }
    }
    pico_init(0);
    return 0;
}
