CC = cc
FLAG = -Werror -Wall -Wextra
NAME = libFdF.a
SRC = main.c
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
OBJ_DIR = obj
ARCH = libft/libft.a

GREEN="\033[0;32m"
RED="\033[0;31m"
BLUE="\033[0;34m"
END_COLOUR="\033[0m"

.PHONY: all clean fclean re bonus

$(NAME) : compil $(OBJ)
	ar -rc $@ $(OBJ) $(ARCH)
	@echo $(GREEN) Done $(END_COLOUR)

compil : 
	@echo $(RED) Object Compilation... $(END_COLOUR)

all :  $(NAME)
	$(CC) $(FLAG) -c $< -o a.out $(OBJ) 

clean :
	@echo $(RED) Object Cleaning... $(END_COLOUR)	
	rm -rf obj
	@echo $(GREEN) Object Cleaned $(END_COLOUR)	

fclean : clean
	rm -f $(NAME)

.SILENT: 
$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAG) -c $< -o $@ 

re :
	$(MAKE) fclean
	$(MAKE) all

bonus :

