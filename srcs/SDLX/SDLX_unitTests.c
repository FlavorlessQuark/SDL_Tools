# include "SDLX.h"

int MouseButtonTest(int button, int *pressed)
{
	int bitShift;
	int buttonBits;

	memset(pressed, 0, 3);

	bitShift = SDL_BUTTON_RIGHT + 1;
	buttonBits = 1 << SDL_BUTTON(button);
	while (bitShift && buttonBits)
	{
		// SDL_Log("Shift %d value %d bits %d", bitShift, (1 << bitShift), buttonBits);
		if ((1 << bitShift) <= buttonBits)
		{
			// SDL_Log("Shift %d -> button %d", bitShift, bitShift - 1);
			pressed[bitShift - 1] = 1;
			buttonBits >>= bitShift;
		}
		bitShift--;
	}
}

int RunInputTests()
{
	int pressed[3];

	SDL_Log("------ Test Left Click ------");
	MouseButtonTest(SDL_BUTTON_LEFT, pressed);
	SDL_assert(pressed[0] == 1);

	SDL_Log("------ Test Middle Click -------");
	MouseButtonTest(SDL_BUTTON_MIDDLE, pressed);
	SDL_assert(pressed[1] == 1);

	SDL_Log("------ Test Rigth Click -------");
	MouseButtonTest(SDL_BUTTON_RIGHT, pressed);
	SDL_assert(pressed[3] == 1);

	SDL_Log("------ Test Left + Middle Click ------");
	MouseButtonTest(SDL_BUTTON_LEFT
	, pressed);
	SDL_assert(pressed[0] == 1);
}
