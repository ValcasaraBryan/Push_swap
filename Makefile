CHECK = checker

PUSH = push_swap

SRC = srcs/main.c

OBJ = objets/main.o

LIB = libft/libft.a

INCL = includes

CC = @gcc

CFLAGS = -Wall -Wextra -Werror


all : lib $(CHECK)

lib : Makefile
	@make -C libft

$(OBJ) : $(LIB) $(SRC) Makefile
	@$(CC) $(CFLAGS) $(SRC) -c -o $@
	@echo "Creation objets Done !"

$(CHECK) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo "Compilation checker done !"

clean :
	@make clean -C libft
	@rm -rf $(OBJ)

fclean : clean
	@make fclean -C libft
	@rm -rf $(CHECK)

re : fclean all
