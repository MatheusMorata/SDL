#include "pico.h"

int main(void) {
    pico_init(1);
    pico_set_title("Hello World");
    pico_input_delay(3000);
    pico_init(0);
    return 0;
}
