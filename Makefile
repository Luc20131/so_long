CC = cc
FLAG = -g3 -Werror -Wall -Wextra -g3
NAME = so_long
SRC = main.c movement/movement.c images_gestionnary/image_utils.c images_gestionnary/image_dictionnary.c images_gestionnary/image_map.c $(PARS_OBJ) utils.c
OBJ = $(SRC:.c=.o)
OBJ_DIR = obj/
PARS_SRC= test_map.c mapper_utilities.c map_adjustement.c map_initializer.c path_finder.c
PARS_OBJ = $(addprefix $(PARS_DIR)/,$(PARS_SRC))
PARS_DIR = parsing
ARCH = libft/libft.a
INCLUDE = -I. -Ilibft
LIB = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm -L libft -l ft

GREEN="\033[0;32m"
END_COLOUR="\033[0m"

NB_FILES=$(words $(SRC))

define percent
	@echo -n $(GREEN)"[$$(echo "scale=2; $$(find . -maxdepth 1 -name '*.o' | wc -l) / $(NB_FILES) * 100" | bc)%]" $(END_COLOUR)
endef

.PHONY: all clean fclean re

all :
	@echo $(BLUE)Test norminette...$(END_COLOUR)
	@if norminette $(SRC)| grep Error; then \
		echo $(RED)"\no------------------------------------------o\n|              norminette KO               |\no------------------------------------------o\n"$(END_COLOUR); \
	else \
		echo $(GREEN)"\no------------------------------------------o\n|              norminette OK               |\no------------------------------------------o\n"$(END_COLOUR); \
	fi
	@echo $(BLUE)Creating $(NAME)...$(END_COLOUR)
	@$(MAKE) $(NAME)

%.o : %.c $(ARCH) $(HEADER)
	@$(call percent)
	$(CC) $(FLAG) -c $< -o $@ $(LIB)

$(NAME) : $(ARCH) $(OBJ)
	@make all -C minilibx-linux
	@$(call percent)
	$(CC) $(FLAG) -o $@ $(OBJ) $(INCLUDE) $(LIB)
	@echo $(GREEN)"\no------------------------------------------o\n|\t     $(NAME) compiled\t\t   |\no------------------------------------------o\n"$(END_COLOUR)

$(ARCH) : $(LIBFT_SRC_FULL) libft/libft.h
	@echo $(BLUE)Libft Compilation...$(END_COLOUR)
	@make -C libft

clean :
	@echo $(BLUE)Cleaning...$(END_COLOUR)
	@make fclean -C libft
	@rm -rf $(OBJ)

fclean : clean
	@rm -f $(NAME)
	@echo $(GREEN)"\no------------------------------------------o\n|           All Compiled Removed\t   |\no------------------------------------------o\n"$(END_COLOUR); \

re :
	@make fclean
	@make all
