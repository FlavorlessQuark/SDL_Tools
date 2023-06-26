#include "../includes/SDLX/SDLX.h"

int main()
{
	SDLX_RectContainer *root;
	SDLX_Display *display;

	SDLX_InitDefault();
	root = SDLX_LoadConfig("examples/simple_container_config");

	// cleanupUIConfig(root);
	display = SDLX_DisplayGet();

	while (1)
	{
		SDLX_RenderReset(display);
		SDLX_InputLoop();
		SDLX_DisplayConfig(display->renderer ,root);
		SDL_RenderPresent(display->renderer);
	}
	SDLX_RenderQueuesCleanup();
}
