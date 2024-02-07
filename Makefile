CC = cc
FLAG = -g3 -Werror -Wall -Wextra
NAME = libFdF.a
SRC = main.c
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
OBJ_DIR = obj
GNL_SRC = get_next_line.c get_next_line_utils.c
GNL_OBJ = $(addprefix $(OBJ_DIR)/,$(GNL_SRC:.c=.o))
ARCH = libft/libft.a

GREEN="\033[0;32m"
RED="\033[0;31m"
BLUE="\033[0;34m"
END_COLOUR="\033[0m"

.PHONY: all clean fclean re parsing

$(NAME) : compil $(OBJ)
	@cd ./libft && make && cd ..
	ar -rc $@ $(OBJ) $(ARCH)
	@echo $(GREEN) Done $(END_COLOUR)

compil :
	@echo $(RED) Object Compilation... $(END_COLOUR)

all :  $(NAME)


clean :
	rm -rf obj
	cd libft && make clean

fclean : clean
	rm -f $(NAME)

.SILENT:
$(OBJ_DIR)/%.o : %.c FdF.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAG) -c $< -o $@ -Lminilibx-linux -lmlx_Linux -lX11 -lXext -g3

$(OBJ_DIR)/%.o : %.c get_next_line/get_next_line.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAG) -c $< -o $@ -Lminilibx-linux -lmlx_Linux -lX11 -lXext -g3

re :
	$(MAKE) fclean
	$(MAKE) all

parsing :
	cd parsing/ && cc -Wall -Wextra -Werror  main_tester.c test_map.c way_checker.c ../get_next_line/*.c -L ../so_long.h ../get_next_line/get_next_line.h ../libft/libft.h -g3 && ./a.out
