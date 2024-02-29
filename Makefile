CC = cc
FLAG = -g3 -Werror -Wall -Wextra
NAME = so_long
SRC = main.c $(PARS_OBJ)
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
OBJ_DIR = obj
PARS_SRC= test_map.c map_generator.c path_finder.c
PARS_OBJ = $(addprefix parsing/,$(PARS_SRC))
ARCH = libft/libft.a

GREEN="\033[0;32m"
RED="\033[0;31m"
BLUE="\033[0;34m"
END_COLOUR="\033[0m"

.PHONY: all clean fclean re parsing

$(NAME) : compil $(OBJ)
	@make -C libft
	@make -C minilibx-linux

	@echo $(GREEN) Done $(END_COLOUR)

compil :
	@echo $(RED) Object Compilation... $(END_COLOUR)

all : $(NAME)

clean :
	rm -rf obj
	cd libft && make fclean

fclean : clean
	rm -f $(NAME)

.SILENT:
%.o : %.c so_long.h Makefile
	$(CC) $(FLAG) -c $< -o $@ libft/libft.a -Lminilibx-linux -lmlx_Linux -lX11 -lXext -g3

re :
	$(MAKE) fclean
	$(MAKE) all

parsing :
	cd parsing/ && cc -Wall -Wextra -Werror main_tester.c test_map.c map_generator.c path_finder.c ../libft/get_next_line/*.c -L ../so_long.h ../libft/get_next_line/get_next_line.h ../libft/libft.h  ../libft/ft_printf/*.c ../libft/ft_printf/*.h -g3 && ./a.out

