#include "SDLX/SDLX.h"

static SDLX_Display display;
void 			SDLX_Background_Set(SDL_Texture *bg) {display.background = bg;}

void	SDLX_Close(void)
{
	SDL_DestroyWindow(display.window);
    TTF_CloseFont(display.defaultFont);

    TTF_Quit();
    IMG_Quit();
	SDL_Quit();
}

static void		SDLX_Display_Set(char *name, int x, int y, int h, int w, int flags)
{
    SDL_Window *window;

	window = SDL_CreateWindow(
        name,
        x, y,
        w, h,
        flags
	);
    display.window = window;
    display.renderer = SDL_CreateRenderer(display.window, -1, 0);
    display.win_w = w;
    display.win_h = h;
}

void	        SDLX_Start(char *name, int x, int y, int h, int w, int flags)
{
	if (!SDL_WasInit(0))
		SDL_Init(SDL_INIT_EVERYTHING);
    if (!TTF_WasInit() && !TTF_Init())
    {
        SDL_Log("TTF initialized");
        display.defaultFont = TTF_OpenFont(DEFAULT_FONT_PATH, DEFAULT_FONT_SIZE);
    }
    
	SDLX_Display_Set(name, x, y, h, w, flags);
    SDLX_RenderQueues_Init();
	atexit(SDLX_Close);
}

SDLX_Display	*SDLX_Display_Get(void) 
{
    if (!display.renderer)
        return NULL;

    return &display;
}
