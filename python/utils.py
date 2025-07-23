import sdl2

class SDLResources:
    def __init__(self):
        self.window = None
        self.renderer = None
        self.success = False
        self.error = ""

def open_sdl(window_title: str) -> SDLResources:
    """
    Inicializa SDL, cria janela e renderizador.
    Retorna um objeto SDLResources com o resultado.
    """
    resources = SDLResources()

    # inicializa o SDL
    if sdl2.SDL_Init(sdl2.SDL_INIT_VIDEO) < 0:
        resources.error = f"Erro ao iniciar SDL: {sdl2.SDL_GetError().decode('utf-8')}"
        return resources

    # window
    resources.window = sdl2.SDL_CreateWindow(
        window_title.encode('utf-8'), # utf-8 obrigatório
        sdl2.SDL_WINDOWPOS_CENTERED,
        sdl2.SDL_WINDOWPOS_CENTERED,
        800, 600,
        sdl2.SDL_WINDOW_SHOWN
    )
    if not resources.window:
        resources.error = f"Erro ao criar window: {sdl2.SDL_GetError().decode('utf-8')}"
        sdl2.SDL_Quit()
        return resources

    # renderizador
    resources.renderer = sdl2.SDL_CreateRenderer(
        resources.window,
        -1, # primeiro driver de renderização disponível
        sdl2.SDL_RENDERER_ACCELERATED | sdl2.SDL_RENDERER_PRESENTVSYNC
    )
    if not resources.renderer:
        resources.error = f"Erro ao criar render: {sdl2.SDL_GetError().decode('utf-8')}"
        sdl2.SDL_DestroyWindow(resources.window)
        sdl2.SDL_Quit()
        return resources

    resources.success = True
    return resources

def close_sdl(resources: SDLResources):
    """
    Libera os recursos SDL.
    """
    if resources.renderer:
        sdl2.SDL_DestroyRenderer(resources.renderer)
    if resources.window:
        sdl2.SDL_DestroyWindow(resources.window)
    sdl2.SDL_Quit()