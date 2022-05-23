#ifndef SDLX_H
# define SDLX_H

# include "SDL2/SDL_image.h"
# include "SDL2/SDL_ttf.h"

# include "SDLX_input.h"
# include "SDLX_macro.h"
# include "SDLX_structs.h"

/** 
 * Standard SDLX lib functions
 */

SDLX_Display	*SDLX_Display_Get(void);
void	        SDLX_Background_Set(SDL_Texture *bg);
void	        SDLX_Start(char *name, int x, int y, int h, int w, int flags);
SDL_Texture		*SDLX_Texture_Load(char *path, SDLX_Display *display);

/**
 * SDLX renderer functions and render queues functions
 */
void 		SDLX_RenderAll(SDLX_Display *display);
void 		SDLX_RenderOne(uint32_t id);
void        SDLX_Render_Reset(SDLX_Display *display);

void 		SDLX_RenderQueues_Init();
void		SDLX_RenderQueue_Push(SDLX_Sprite *sprite);
void        SDLX_RenderQueue_Flush(uint32_t id);
void		SDLX_RenderQueue_FlushAll(void);
uint32_t    SDLX_RenderQueue_Create(SDL_bool isSorted);

void SDLX_RenderMessage_Aligned(SDLX_Display *display, int x_align, int y_align, SDL_Color color, char *text);
void SDLX_RenderMessage(SDLX_Display *display, SDL_Rect *dst, SDL_Color color, char *text);

SDLX_RenderQueue	*SDLX_RenderQueue_Get(uint32_t id);

/**
 * SDLX sprite functions
 */

void		SDLX_Sprite_Create(SDLX_Sprite *dest, uint32_t layer, SDL_Texture *texture);

/**
 * SDLX Input functions 
 */

void		SDLX_Input_Update(void);
SDLX_Input 	SDLX_Input_Get(void);

/**
 * SDLX Utils functions
 * 
 */

void 		SDLX_CapFPS();
SDLX_Time 	SDLX_Time_Get(void);
int			SDLX_TimedLoop(int (*game_loop)(void *), void *args);
int			SDLX_PointInCircle(SDL_Point point, SDLX_Circle circle);

//Maybe put dbeug in its own header to be included separately
/**
 * SDLX debug functions
 * 
 */
void 		SDLX_Sprite_Print(SDLX_Sprite *sprite);

#endif