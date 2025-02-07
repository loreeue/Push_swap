NAME = push_swap

SRC = big_small.c cheapest.c frees.c handle_errors.c push_cheapest.c\
push_swap.c sort_utils.c sort.c target.c stack_utils.c validate_input.c\
movements/pa.c movements/pb.c movements/ra.c movements/rb.c movements/rr.c\
movements/rra.c movements/rrb.c movements/rrr.c movements/sa.c movements/sb.c movements/ss.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

PURPLE = \033[1;35m
RESET = \033[0m

HEADER = "\n$(PURPLE)\
██████╗ ██╗   ██╗███████╗██╗  ██╗    ███████╗██╗    ██╗ █████╗ ██████╗ \n\
██╔══██╗██║   ██║██╔════╝██║  ██║    ██╔════╝██║    ██║██╔══██╗██╔══██╗\n\
██████╔╝██║   ██║███████╗███████║    ███████╗██║ █╗ ██║███████║██████╔╝\n\
██╔═══╝ ██║   ██║╚════██║██╔══██║    ╚════██║██║███╗██║██╔══██║██╔═══╝ \n\
██║     ╚██████╔╝███████║██║  ██║    ███████║╚███╔███╔╝██║  ██║██║     \n\
╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     \n\
$(RESET)\n"

$(NAME): $(OBJ)
	@printf $(HEADER)
	@cd libft && $(MAKE) > /dev/null
	@$(CC) $(CFLAGS) $(OBJ) -L ./libft -lft -o $(NAME)
	@echo "Compilation complete!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@cd libft && $(MAKE) clean > /dev/null
	@rm -f $(OBJ)
	@echo "Clean complete!"

fclean: clean
	@cd libft && $(MAKE) fclean > /dev/null
	@rm -f $(NAME)
	@echo "Full clean complete!"

all: $(NAME)

re: fclean all

.PHONY: clean fclean all re
