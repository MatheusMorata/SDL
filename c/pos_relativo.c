#include "pico.h"

int main(void)
{
    pico_init(1);

    pico_set_size(
        (Pico_Dim){800, 600},
        (Pico_Dim){800, 600}
    );

    pico_set_color_clear(
        (Pico_Color){0, 0, 0, 255}
    );

    /*
       Desenha utilizando o centro do objeto
       como ponto de referência.
    */
    pico_set_anchor_draw(
        (Pico_Anchor){PICO_CENTER, PICO_MIDDLE}
    );


    /*
       Retângulo de referência.
       Ele representa uma área qualquer da interface.
    */
    Pico_Rect panel = {
        400, 300,
        400, 300
    };


    /*
       Obtém uma posição correspondente a 50% da largura
       e 50% da altura do retângulo de referência.
    */
    Pico_Pos center = pico_pos_ext(
        (Pico_Pct){50, 50},
        panel,
        (Pico_Anchor){PICO_CENTER, PICO_MIDDLE}
    );


    pico_set_color_draw(
        (Pico_Color){0, 100, 255, 255}
    );

    pico_output_clear();


    /*
       Desenha o painel.
    */
    pico_output_draw_rect(panel);


    /*
       Desenha o objeto posicionado relativamente
       ao painel.
    */
    pico_set_color_draw(
        (Pico_Color){255, 0, 0, 255}
    );

    pico_output_draw_rect(
        (Pico_Rect){
            center.x,
            center.y,
            100,
            50
        }
    );


    pico_output_present();

    pico_input_delay(3000);

    pico_init(0);

    return 0;
}
