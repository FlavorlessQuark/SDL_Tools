#include "SDLX/SDLX.h"
#include "SDL2/SDL_image.h"
int main()
{
	SDLX_Display *display;
	SDL_Rect 	dst;
	SDL_Rect 	bdst;
	SDLX_Anim	*anim;
	SDLX_Anim	*bnim;
	SDLX_Animator *a;
	SDLX_Animator *b;
	SDL_Texture *tex;

	int i;

	i = 0;
	SDLX_Start("DEFAULT", WIN_X, WIN_Y, WIN_H, WIN_W, SDL_WINDOW_SHOWN);
	display = SDLX_DisplayGet();
	tex = SDL_CreateTextureFromSurface(display->renderer, IMG_Load("test.png"));
	dst.h = 32;
	dst.w = 32;
	dst.x =100;
	dst.y =100;
	bdst.h = 32;
	bdst.w = 32;
	bdst.x = 200;
	bdst.y = 100;
	anim = SDLX_AnimLoad(tex, 8, 32, 32, SDL_TRUE, 0, 0);
	bnim = SDLX_AnimLoad(tex, 8, 32, 32, SDL_FALSE, 0, 0);
	a = SDLX_AnimatorInstantiate(NULL, &anim, 1, &dst);
	b = SDLX_AnimatorInstantiate(a, NULL, 1, &bdst);
	SDLX_RenderQueueAdd(0, anim->sprites[0]);
	SDLX_RenderQueueAdd(0, anim->sprites[0]);
	SDLX_RenderQueueAdd(0, anim->sprites[0]);
	SDLX_RenderQueueAdd(0, anim->sprites[0]);
	SDLX_RenderQueueAdd(0, anim->sprites[0]);
	//SDL_Log("Init\n");
	i = 10;
	int n = 0;
	while (1)
	{
		SDLX_ResetWindow();
		SDLX_InputLoop();
		// SDLX_AnimationUpdate();
		// SDL_SetRenderDrawColor(display->renderer, i, 0, 0, 255);
		SDLX_RenderQueueDisplay(SDLX_RenderQueueFetch(NULL)[0], display);
		SDL_RenderPresent(display->renderer);
		SDLX_FPSAdjust();
		while (i < n)
		{
			SDLX_RenderQueueAdd(0, anim->sprites[0]);
			i++;
		}
		n += 2;
		i = 0;
	}
}