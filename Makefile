CC = cc
FLAG = -g3 -Werror -Wall -Wextra
NAME = so_long
SRC = main.c movement/movement.c images_gestionnary/image_utils.c images_gestionnary/image_dictionnary.c images_gestionnary/image_map.c $(PARS_OBJ) utils.c
OBJ = $(SRC:.c=.o)
OBJ_DIR = obj/
PARS_SRC= test_map.c mapper_utilities.c map_adjustement.c map_initializer.c path_finder.c
PARS_OBJ = $(addprefix $(PARS_DIR)/,$(PARS_SRC))
PARS_DIR = parsing
ARCH = libft/libft.a
INCLUDE = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm -L so_long.h

GREEN="\033[0;32m"
RED="\033[0;31m"
BLUE="\033[0;34m"
END_COLOUR="\033[0m"

.PHONY: all clean fclean re parsing

$(NAME) : $(ARCH) $(OBJ)
	@make all -C minilibx-linux
	$(CC) $(FLAG) -o so_long $(OBJ) $(ARCH) $(INCLUDE)
	@echo $(GREEN) Done $(END_COLOUR)

all : $(NAME)

clean :
	rm -rf $(OBJ)
	make fclean -C libft
	make clean -C minilibx-linux

fclean : clean
	rm -f $(NAME)

%.o : %.c $(ARCH)
	$(CC) $(FLAG) -c $< -o $@ $(ARCH) $(INCLUDE)

re :
	$(MAKE) fclean
	$(MAKE) all

$(ARCH) :
	@make -C libft
