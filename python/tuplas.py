from picopy.pico import PicoPy

pico = PicoPy()
pico.init(True)

pico.set_color(color=(255, 0, 0, 255))
pico.output_draw_rect(rect=(10, 10, 20, 15))

pico.init(False)
