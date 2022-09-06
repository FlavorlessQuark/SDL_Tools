#ifndef SDLX_MACRO
# define SDLX_MACRO

// Render queue macros
# define DEFAULT_QUEUES_COUNT 2
# define DEFAULT_QUEUE_SIZE 5

// Frame and update macros
# define FPS 60
# define FRAME_TIME 1000 / FPS
# define UPDATE_LEN_MS 10
# define MAX_UPDATE_PER_FRAME 30


// Text macros
# define DEFAULT_FONT_SIZE 20
# define DEFAULT_FONT_COLOR (SDL_Color){255, 255, 255}
# define DEFAULT_FONT_PATH "./srcs/SDLX/default.ttf"

enum {
	SDLX_RIGHT_ALIGN = 1,
	SDLX_CENTER_ALIGN,
	SDLX_LEFT_ALIGN,
	SDLX_TOP_ALIGN,
	SDLX_BOTTOM_ALIGN
};


# ifndef MAX
#  define MAX(a, b)\
	({ 	__typeof__ (a) _a = (a);\
		__typeof__ (b) _b = (b);\
		(_a > _b) ? (a) : (b);})\

# endif

# ifndef MIN
#  define MIN(a, b)			\
({ 	__typeof__ (a) _a = (a);\
	__typeof__ (b) _b = (b);\
	(_a < _b) ? (a) : (b);})\

# endif

#endif
