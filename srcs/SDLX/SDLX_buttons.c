#include "SDLX/SDLX.h"

static SDLX_Button **buttons;
static size_t capacity;
static size_t size;
static SDLX_Button *currentFocus;

void SDLX_ButtonCreate (SDLX_Button *dest, SDL_Rect *boundingBox, void *data)
{
	if (size >= capacity)
	{
		capacity = (capacity * 2) + 1;
		buttons = realloc(buttons, sizeof(SDLX_Button *) * capacity);
	}
	buttons[size] = dest;

	if (!boundingBox)
		dest->boundingBox = &dest->_boundingBox;
	else
		dest->boundingBox = boundingBox;

	dest->data = data;
	dest->state = SDLX_NONE;
	dest->enabled = SDL_TRUE;
	dest->triggered = SDL_FALSE;

	size++;
}

void SDLX_ButtonUpdate()
{
	size_t i;
	SDLX_Input input;

	i = 0;
	input = SDLX_InputGet();
	while (i < size)
	{
		buttons[i]->state = ((buttons[i]->state & 1) << 1);
		buttons[i]->triggered = ((buttons[i]->triggered & 1) << 1);
		if (SDL_PointInRect(&input.mouse, buttons[i]->boundingBox))
		{
			SDL_Log("tigerred %d %d", buttons[i]->triggered, input.mouse_buttons[SDL_BUTTON_LEFT]);
			buttons[i]->state += 1;

			if (currentFocus)
				currentFocus->triggered <<= 1;
			currentFocus = buttons[i];

			// I'm sure the below can be simplified into a single branchless statement
			if (!buttons[i]->triggered && input.mouse_buttons[SDL_BUTTON_LEFT] == SDLX_KEYHELD)
				buttons[i]->triggered = 0;
			else
				buttons[i]->triggered +=  (input.mouse_buttons[SDL_BUTTON_LEFT] & 1);
		}
		// else
		// 	buttons[i]->state = ((buttons[i]->state & 1) << 1) + 0;
		i++;
	}
}
