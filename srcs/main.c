#include "../includes/SDLX/SDLX.h"

int main()
{
	SDLX_Display *display;
	SDLX_Input	input;
	SDL_Rect rect;
	SDLX_Button button;

	SDLX_InitDefault();
	display = SDLX_DisplayGet();

	// RunInputTests();
	SDLX_InputMap(SDLX_KEYBOARDTYPE, SDL_SCANCODE_LEFT, SDL_SCANCODE_LEFT);
	SDLX_InputMap(SDLX_KEYBOARDTYPE, SDL_SCANCODE_A, SDL_SCANCODE_LEFT);
	SDLX_InputMap(SDLX_KEYBOARDTYPE, SDL_SCANCODE_RIGHT, SDL_SCANCODE_RIGHT);
	SDLX_InputMap(SDLX_KEYBOARDTYPE, SDL_SCANCODE_D, SDL_SCANCODE_RIGHT);
	SDLX_InputMap(SDLX_KEYBOARDTYPE, SDL_SCANCODE_SPACE, SDL_SCANCODE_SPACE);
	SDLX_InputMap(SDLX_KEYBOARDTYPE, SDL_SCANCODE_P, SDL_SCANCODE_SPACE);

	SDLX_ButtonCreate(&button, &rect, NULL);

	rect.w = DEFAULT_WIN_W  / 4;
	rect.h = DEFAULT_WIN_H  / 4;
	rect.x = (DEFAULT_WIN_W / 2)- (rect.w / 2);
	rect.y = (DEFAULT_WIN_H / 2)- (rect.h / 2);

	while (1)
	{
		SDLX_RenderReset(display);
		SDLX_InputLoop();
		SDLX_InputUpdate();
		input = SDLX_InputGet();
		SDLX_ButtonUpdate();

		SDL_SetRenderDrawColor(display->renderer,
		255 * (button.triggered),
		255 * (button.state == SDLX_FOCUS_STAY),
		255 * (button.state == SDLX_NONE),
		255);
		// SDL_Log("button state %d %d", button.state, button.triggered);
		SDL_RenderFillRect(display->renderer, &rect);
		SDL_SetRenderDrawColor(display->renderer, 0, 0, 0, 255);
		SDL_RenderPresent(display->renderer);
	}
}
