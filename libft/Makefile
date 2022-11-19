NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_calloc.c ft_memcpy.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstmap_bonus.c ft_lstiter_bonus.c ft_lstclear_bonus.c

OFILES = $(SRCS:.c=.o)

BON_OFILES = ${BONUS:.c=.o}

INCLUDES = libft.h


all: $(NAME)

$(NAME): $(OFILES) $(INCLUDES)
	ar rcs $(NAME) $?
	@echo "\033[92mCompiling library\033[0m"

%.o: %.c
	$(CC) -Wall -Wextra -Werror -g -c -o $@ $^

clean:
	rm -rf $(OFILES) $(BON_OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(BON_OFILES)
	${MAKE} WITH_BONUS=1 all
	ar rcs $(NAME) $?

.PHONY: all clean fclean re bonus