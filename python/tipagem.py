from picopy.pico import PicoPy

pico = PicoPy()
pico.init(True)

cor = (255, 0, 0, 255)
pico.set_color(color=cor)
pico.output_draw_rect(rect=(10, 10, 20, 15))

pico.input_delay(1000)

cor = (0, 255, 0, 255)
pico.set_color(color=cor)
pico.output_draw_rect(rect=(35, 10, 20, 15))

pico.input_delay(1000)
pico.init(False)
