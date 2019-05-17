CHECK = checker

PUSH = push_swap

arg =

SRC = srcs/%.c

OBJ_CHECKER =	objets/check_arg.o\
				objets/check_ope.o\
				objets/checker.o\
				objets/error.o\
				objets/files.o\
				objets/ft_intsplit.o\
				objets/operation.o\
				objets/parsing.o\
				objets/print_messages.o\
				objets/print_pattern.o\
				objets/read_enter.o\
				objets/utils.o
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


exe_check : all $(CHECK)
	@./$(CHECK) $(arg) < test

exe_push : all $(PUSH)
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

.PHONY: objets exe clean fclean re