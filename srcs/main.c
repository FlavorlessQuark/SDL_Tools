#include "../includes/SDLX/SDLX.h"

int main()
{
	SDLX_Display *display;
	SDLX_Input	input;
	SDL_Rect rect;
	SDL_Rect rect2;
	SDLX_Button button;
	SDLX_Button button2;

	SDLX_InitDefault();
	display = SDLX_DisplayGet();

	// RunInputTests();
	SDLX_InputMap(SDLX_KEYBOARDTYPE, SDL_SCANCODE_UP, SDL_SCANCODE_UP);
	SDLX_InputMap(SDLX_KEYBOARDTYPE, SDL_SCANCODE_W, SDL_SCANCODE_UP);
	SDLX_InputMap(SDLX_KEYBOARDTYPE, SDL_SCANCODE_DOWN, SDL_SCANCODE_DOWN);
	SDLX_InputMap(SDLX_KEYBOARDTYPE, SDL_SCANCODE_S, SDL_SCANCODE_DOWN);
	SDLX_InputMap(SDLX_KEYBOARDTYPE, SDL_SCANCODE_LEFT, SDL_SCANCODE_LEFT);
	SDLX_InputMap(SDLX_KEYBOARDTYPE, SDL_SCANCODE_A, SDL_SCANCODE_LEFT);
	SDLX_InputMap(SDLX_KEYBOARDTYPE, SDL_SCANCODE_RIGHT, SDL_SCANCODE_RIGHT);
	SDLX_InputMap(SDLX_KEYBOARDTYPE, SDL_SCANCODE_D, SDL_SCANCODE_RIGHT);
	SDLX_InputMap(SDLX_KEYBOARDTYPE, SDL_SCANCODE_SPACE, SDL_SCANCODE_SPACE);
	SDLX_InputMap(SDLX_KEYBOARDTYPE, SDL_SCANCODE_P, SDL_SCANCODE_SPACE);

	SDLX_ButtonCreate(&button, &rect);
	SDLX_ButtonCreate(&button2, &rect2);
	SDLX_ButtonSet_Keys(
		SDL_SCANCODE_LEFT,
		SDL_SCANCODE_RIGHT,
		SDL_SCANCODE_UP,
		SDL_SCANCODE_DOWN,
		SDL_SCANCODE_SPACE
		);

	rect.w = DEFAULT_WIN_W  / 4;
	rect.h = DEFAULT_WIN_H  / 4;
	rect.x = (DEFAULT_WIN_W / 2) - (rect.w / 2) ;
	rect.y = (DEFAULT_WIN_H / 2)- (rect.h / 2) - rect.h;

	rect2.w = DEFAULT_WIN_W  / 4;
	rect2.h = DEFAULT_WIN_H  / 4;
	rect2.x = (DEFAULT_WIN_W / 2) - (rect2.w / 2) ;
	rect2.y = (DEFAULT_WIN_H / 2)- (rect2.h / 2) + rect2.h;

	SDLX_ButtonSet_Neighbours(&button, NULL, NULL, &button2, &button2);
	SDLX_ButtonSet_Neighbours(&button2, NULL, NULL, &button, &button);


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
		255,
		255);
		SDL_RenderFillRect(display->renderer, &rect);

		SDL_SetRenderDrawColor(display->renderer,
		255 * (button2.triggered),
		255 * (button2.state == SDLX_FOCUS_STAY),
		255,
		255);
		SDL_RenderFillRect(display->renderer, &rect2);
		// SDL_Log("button state %d %d", button.state, button.triggered);
		SDL_SetRenderDrawColor(display->renderer, 0, 0, 0, 255);
		SDL_RenderPresent(display->renderer);
	}
}
