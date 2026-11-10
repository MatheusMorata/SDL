from picopy.pico import PicoPy

pico = PicoPy()
pico.init(True)

pico.set_color((0, 0, 0, 255))
pico.set_color((255, 0, 0, 255))

pico.output_clear()

quadrado = [
    (x, y) 
    for y in range(10, 25) 
    for x in range(10, 30)
]

linha = []
for i in range(64):
    y = int(i * 35 / 63)
    linha.append((i, y))

pico.output_draw_pixels(quadrado)
pico.output_draw_pixels(linha)

pico.input_delay(5000)

pico.init(False)
