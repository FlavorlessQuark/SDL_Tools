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

SDLX_Display	*SDLX_DisplayGet(void);
void	        SDLX_BackgroundSet(SDL_Texture *bg);
void			SDLX_InitDefault();
void	        SDLX_Init(char *name, int x, int y, int h, int w, int flags);
SDL_Texture		*SDLX_TextureLoad(char *path, SDLX_Display *display);

/**
 * SDLX renderer functions and render queues functions
 */
void 		SDLX_RenderAll(SDLX_Display *display);
void 		SDLX_RenderOne(uint32_t id);
void        SDLX_RenderReset(SDLX_Display *display);

void 		SDLX_RenderQueuesInit();
void		SDLX_RenderQueuePush(SDLX_Sprite *sprite);
void        SDLX_RenderQueueFlush(uint32_t id);
void		SDLX_RenderQueueFlushAll(void);
uint32_t    SDLX_RenderQueueCreate(SDL_bool isSorted);

void 		SDLX_RenderMessageAligned(SDLX_Display *display, int x_align, int y_align, SDL_Color color, char *text);
void 		SDLX_RenderMessage(SDLX_Display *display, SDL_Rect *dst, SDL_Color color, char *text);

SDLX_RenderQueue	*SDLX_RenderQueueGet(uint32_t id);

/**
 * SDLX sprite functions
 */

void		SDLX_SpriteCreate(SDLX_Sprite *dest, uint32_t layer, SDL_Texture *texture);

/**
 * SDLX Input functions
 */

void		SDLX_InputUpdate(void);
SDLX_Input 	SDLX_InputGet(void);

void SDLX_InputMap(int keyType, int fromKey, int toKey);

/**
 * SDLX Utils functions
 *
 */

void 		SDLX_CapFPS();
SDLX_Time 	SDLX_TimeGet(void);
int			SDLX_TimedLoop(int (*game_loop)(void *), void *args);
int			SDLX_PointInCircle(SDL_Point point, SDLX_Circle circle);

//Maybe put dbeug in its own header to be included separately
/**
 * SDLX debug functions
 *
 */
void 		SDLX_SpritePrint(SDLX_Sprite *sprite);

#endif
