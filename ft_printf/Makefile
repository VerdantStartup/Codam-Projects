NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c ft_printf_utils2.c ft_base_itoa.c

OFILES = $(SRCS:.c=.o)

INCLUDES = ft_printf.h


all: $(NAME)

$(NAME): $(OFILES) $(INCLUDES)
	ar rcs $(NAME) $?
	@echo "\033[92mCompiling library\033[0m"

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c -o $@ $^

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean