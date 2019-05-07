CHECK = checker

PUSH = push_swap

SRC = srcs/main.c

OBJ = objets/main.o

objets = 0

LIB = libft/libft.a

INCL = includes

CC = @gcc

CFLAGS = -Wall -Wextra -Werror


all : lib $(CHECK)

lib : Makefile
	@make -C libft
ifneq (objets, 0)
	@mkdir objets/
objets = 1
endif

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
	@rm -rf objets
objets = 0

re : fclean all
