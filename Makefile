NAME = test

DEBUG_FLAGS = -fsanitize=address
FLAGS = $(DEBUG_FLAGS)
INCLUDES = -I includes/ -I includes/SDL2/ -I includes/SDLX/ -I includes/MT/

LIB_DIR = libs/
STATIC_LIB = -l SDL2 -l SDL2_image -l SDL2_ttf -lm

SDLX_DIR = SDLX/
SRCS_DIR = srcs/

BIN_DIR = bin/

SDLX_NAMES = 			\
	SDLX_button_config	\
	SDLX_buttons		\
	SDLX_containers		\
	SDLX_init			\
	SDLX_input			\
	SDLX_render			\
	SDLX_utils			\

SRCS_NAMES =								\
	$(addprefix $(SDLX_DIR), $(SDLX_NAMES))	\
	test 				\

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_NAMES)))
OBJS = $(addprefix $(BIN_DIR), $(SRCS:.c=.o))

all: $(NAME)
# all:
# 	echo $(SRCS)

$(NAME): $(BIN_DIR) $(OBJS)
	gcc $(FLAGS) $(INCLUDES) -o $(NAME) $(OBJS)  $(STATIC_LIB)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)%.o: %.c
	mkdir -p $(BIN_DIR)$(dir $<)
	gcc $(FLAGS) $(INCLUDES) -c $< -o $@

run: re clean
	./$(NAME)

clean:
	rm -rf $(BIN_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
