# SDL_Tools

This is the new version which does not yet have documentation, the old version is located at https://github.com/FlavorlessQuark/old_SDL_Tools

## Containers

Containers are my (small) version of a CSS like positionning and alignment system. I mostly use it to create and update UI layouts


Usage :

```c
int main()
{
	SDLX_RectContainer *root;
	SDLX_Display *display;

	SDLX_InitDefault();
	display = SDLX_DisplayGet();
	root = SDLX_LoadConfig("examples/simple_container_config");


	while (1)
	{
		SDLX_RenderReset(display->renderer);
		SDLX_InputLoop();
		SDLX_DisplayConfig(display->renderer ,root);
		SDL_RenderPresent(display->renderer);
	}
	SDLX_RenderQueuesCleanup();
	SDLX_CleanupConfig(root);
}
```

The config format is as follows

```c

// Container config format :
//  1 line per object
// Objects can be elements or containers
// Containers are objects within which elements can be arranged
// A container can have 0+ children and those children can be containers or elements
// Elements are leaf node, they have no children
//
//  First line MUST describes a container
//  Container: x,y,w%,h%|wType,hType,margin|alignDir,alignType
//  Element:   x,y,w%,h%|wType,hType,margin
//  c[amount] : container x amount
//  e[amount] : elem x amount
//
// Where :
// x , y : x and y offset in pixels
// w% , h% : width and height, specified as a % of the respective dimension of the parent object
// wType,hType: irrelevant for now, ignore
// margin: margin around the object
// alignDir : SDLX_ALIGN_VERTICAL or SDLX_ALIGN_HORIZONAL Direction of the container, the children elements will be aligned following this direction
// alignType : How the elements in the container are spaced and positionned
//      SDLX_RIGHT_ALIGN  = |o o _ _|
//      SDLX_CENTER_ALIGN = |_ o o _|
//      SDLX_LEFT_ALIGN   = |_ _ o o|
//      SDLX_TOP_ALIGN
//      SDLX_BOTTOM_ALIGN,
//      SDLX_SPACE_EVEN   = |_ o _ o _|
//      SDLX_SPACE_BETWEEN= |o _ _ _ o|
//      SDLX_ALIGN_VERTICAL,
//      SDLX_ALIGN_HORIZONTAL




// You may use tabs to align children with their parent
//  containers and elements will be parented to the container that came before
```
