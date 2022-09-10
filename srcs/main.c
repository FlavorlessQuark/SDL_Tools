#include "../includes/SDLX/SDLX.h"

#include "../includes/SDLX/SDLX_unitTest.h"



int main()
{
	SDLX_Display *display;
	SDLX_Input	input;

	SDLX_InitDefault();
	display = SDLX_DisplayGet();

	// RunInputTests();
	SDLX_InputMap(SDLX_KEYBOARDTYPE, SDL_SCANCODE_LEFT, SDL_SCANCODE_LEFT);
	SDLX_InputMap(SDLX_KEYBOARDTYPE, SDL_SCANCODE_A, SDL_SCANCODE_LEFT);
	SDLX_InputMap(SDLX_KEYBOARDTYPE, SDL_SCANCODE_RIGHT, SDL_SCANCODE_RIGHT);
	SDLX_InputMap(SDLX_KEYBOARDTYPE, SDL_SCANCODE_D, SDL_SCANCODE_RIGHT);
	SDLX_InputMap(SDLX_KEYBOARDTYPE, SDL_SCANCODE_SPACE, SDL_SCANCODE_SPACE);
	SDLX_InputMap(SDLX_KEYBOARDTYPE, SDL_SCANCODE_P, SDL_SCANCODE_SPACE);

	while (1)
	{
		SDLX_RenderReset(display);
		SDLX_InputLoop();
		SDLX_InputUpdate();
		input = SDLX_InputGet();
		SDL_RenderPresent(display->renderer);
	}
}
	// while (1)
	// {
	// 	SDLX_RenderReset(display);
	// 	SDLX_InputLoop();
	// 	SDLX_InputUpdate();
	// 	input = SDLX_InputGet();
	// 	SDL_RenderPresent(display->renderer);
