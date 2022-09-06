#include "SDLX/SDLX.h"
#include <time.h>

static SDLX_Input _intern_input;

void SDLX_InputLoop(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			exit(0);
		if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			exit(0);
	}
}

void SDLX_Input_Update()
{
	// SDL_Event	events[3];
	Uint32		newMouseState;
	// int e;

	newMouseState = SDL_GetMouseState(&_intern_input.mouse.x, &_intern_input.mouse.y);
	// SDL_PumpEvents();
	// This should work in theory but not in pratice, not registering any events :((
	// e =SDL_PeepEvents(events, 3, SDL_PEEKEVENT, SDL_FIRSTzEVENT, SDL_LASTEVENT + 1);

	// SDL_Log("Events %d %d", e, events[0].button.type);
	// if (events[0].button.type == SDL_MOUSEBUTTONUP || events[0].button.type == SDL_MOUSEBUTTONDOWN)
	// 	_intern_input.mouse_state = events[0].button.type;

	// State is 0 if nothing pressed or 1 if pressed
	// If was 0 and is 1, Down 	return	(1) 
	// If was 1 and is 1, Held 	return	(3) 
	// If was 1 and is 0, Up	return	(2)
	// If was 0 and is 0, None	return	(0)
	// f = (prev & 1) << 1 & new;

	_intern_input.mouse_state = ((_intern_input.mouse_state & 1) << 1) + newMouseState;
}

SDLX_Input SDLX_Input_Get() { return _intern_input; }