NAME = push_swap

SRCS = 	push_swap_big.c\
		push_swap_error.c\
		push_swap_init.c\
		push_swap_oper.c\
		push_swap_sort.c\
		push_swap_utils.c\
		push_swap.c\

OFILES = $(SRCS:%.c=%.o)

INCLUDES = push_swap.h

CFLAGS = -Wall -Wextra -Werror 

C_RESET = "\033[0m"

C_GREEN = "\033[92m"

all: $(NAME)

$(NAME): $(OFILES) $(INCLUDES)
	@ $(CC) $(CFLAGS) $(OFILES) -o $(NAME)
	@echo $(C_GREEN)"Compiling library"$(C_RESET)

%.o: %.c
	@ $(CC) $(CFLAGS) -o $@ -c $^

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
