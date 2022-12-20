NAME = minitalk

SRCS = 	client.c\
				server.c\
				utils.c\

OFILES = $(SRCS:%.c=%.o)

INCLUDES = minitalk.h

LIBFT = libft/libft.a



CFLAGS = -Wall -Wextra -Werror

C_RESET = "\033[0m"

C_GREEN = "\033[92m"

all: $(NAME)

$(NAME): $(OFILES) $(INCLUDES)
	@ $(CC) $(CFLAGS) $(OFILES) $(LIBFT) -o $(NAME)
	@echo $(C_GREEN)"Compiling library"$(C_RESET)

$(LIBFT)
	@ $(MAKE) -C libft

%.o: %.c
	@ $(CC) $(CFLAGS) -o $@ -c $^

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re