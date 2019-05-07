CHECK = checker

PUSH = push_swap

SRC = srcs/push_swap.c

OBJ = objets/push_swap.o

LIB = libft/libft.a

INCL = includes

CC = @gcc

CFLAGS = -Wall -Wextra -Werror -I includes -I libft/includes

all : lib $(CHECK)

objets :
	@mkdir objets

lib : Makefile objets
	@make -C libft

$(OBJ) : $(LIB) $(SRC) Makefile includes/push_swap.h
	@$(CC) $(CFLAGS) $(SRC) -c -o $@
	@echo "Creation objets Done !"

$(CHECK) : $(OBJ)
	@$(CC) $(CFLAGS) $(LIB) $(OBJ) main.c -o $@
	@echo "Compilation checker done !"
	@echo "--------------------------"

exe : all
	@./$(CHECK)

clean :
	@make clean -C libft
	@rm -rf $(OBJ)

fclean : clean
	@make fclean -C libft
	@rm -rf $(CHECK)
	@rm -rf objets

re : fclean all

.PHONY = objets exe clean fclean re