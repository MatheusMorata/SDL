#include <pico.h>

int main () {
     pico_init (1) ;
     pico_set_size (( Pico_Dim ) {450 , 300} , (Pico_Dim ) {150 , 100});
     pico_set_grid (0);
     Pico_Pos pos = pico_pos (50 , 50);
     while (1) {
         pico_output_clear () ;
         pico_output_draw_image ( pos , " tux . png " );
         pico_output_present();
         pico_input_event ( NULL , PICO_ANY );
    }
    pico_init (0);
    return 0;
}
