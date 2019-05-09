CHECK = checker

PUSH = push_swap

arg =

SRC = srcs/%.c

OBJ_CHECKER =	objets/checker.o\
				objets/ft_intsplit.o

OBJ_PUSH = objets/push_swap.o

OBJ = objets/%.o

LIB = libft/libft.a

INCL = includes

CC = @gcc

CFLAGS = -Wall -Wextra -Werror -I includes -I libft/includes

all : lib $(CHECK) $(PUSH)

objets :
	@mkdir objets

lib : Makefile objets
	@make -C libft

$(OBJ) : $(SRC) $(LIB) Makefile includes/push_swap.h
	@$(CC) $(CFLAGS) $< -c -o $@
	@echo "Creation objets		Done !"

$(CHECK) : $(OBJ_CHECKER)
	@$(CC) $(CFLAGS) $(LIB) $(OBJ_CHECKER) -o $@
	@echo "Compilation checker	Done !"
	@echo "-------------------------------"

$(PUSH) : $(OBJ_PUSH)
	@$(CC) $(CFLAGS) $(LIB) $(OBJ_PUSH) -o $@
	@echo "Compilation push_swap	Done !"
	@echo "-------------------------------"


exe_check : $(CHECK)
	@./$(CHECK) $(arg)

exe_push : $(PUSH)
	@./$(PUSH) $(arg)


clean :
	@make clean -C libft
	@rm -rf $(OBJ_CHECKER)
	@rm -rf $(OBJ_PUSH)

fclean : clean
	@make fclean -C libft
	@rm -rf $(CHECK)
	@rm -rf $(PUSH)
	@rm -rf objets

re : fclean all

.PHONY = objets exe clean fclean re