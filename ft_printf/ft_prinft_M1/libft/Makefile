# Marco #

NAME			= libft.a
INCLUDE		= ../include
SRC_DIR		= src/
OBJ_DIR		= obj/
CC				= gcc
CFLAGS		= -Wall -Wextra -Werror -I
RM				= rm -rf
AR				= ar rcs

# Colors #

C_RESET		=	"\033[0m"
C_GREEN		=	"\033[92m"

# Sources #

FT_IS_DIR			=	ft_is/
FT_IS					=	ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint

FT_MEM_DIR		=	ft_mem/
FT_MEM				= ft_bzero ft_calloc ft_memchr ft_memcmp ft_memmove ft_memset ft_memcpy

FT_PUT_DIR		=	ft_put/
FT_PUT				=	ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd

FT_TO_DIR			=	ft_to/
FT_TO					=	ft_atoi ft_itoa ft_tolower ft_toupper

FT_STR_DIR		=	ft_str/
FT_STR				=	ft_split ft_strchr ft_strclen ft_strdup ft_striteri ft_strjoin\
								ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp\
								ft_strnstr ft_strrchr ft_strtrim ft_substr

FT_LST_DIR		=	ft_lst/
FT_LST				=	ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone \
								ft_lstiter ft_lstlast ft_lstmap ft_lstnew ft_lstsize

SRC_FILES+=$(addprefix $(FT_IS_DIR),$(FT_IS))
SRC_FILES+=$(addprefix $(FT_MEM_DIR),$(FT_MEM))
SRC_FILES+=$(addprefix $(FT_PUT_DIR),$(FT_PUT))
SRC_FILES+=$(addprefix $(FT_TO_DIR),$(FT_TO))
SRC_FILES+=$(addprefix $(FT_STR_DIR),$(FT_STR))
SRC_FILES+=$(addprefix $(FT_LST_DIR),$(FTLST))

SRC					=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ					=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

# Logic #

OBJF		= test

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)
			@ranlib $(NAME)
			@echo $(C_GREEN)"LIBFT Complied"$(C_RESET)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJF)
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)$(FT_IS_DIR)
			@mkdir -p $(OBJ_DIR)$(FT_MEM_DIR)
			@mkdir -p $(OBJ_DIR)$(FT_PUT_DIR)
			@mkdir -p $(OBJ_DIR)$(FT_TO_DIR)
			@mkdir -p $(OBJ_DIR)$(FT_STR_DIR)
			@mkdir -p $(OBJ_DIR)$(FT_LST_DIR)

clean:
			@$(RM) -r $(OBJ_DIR)
			@$(RM) $(OBJF)

fclean:		clean
			@$(RM) $(NAME)
			@echo $(C_GREEN)"LIBFT cleaned"$(C_RESET)

re:			fclean all

.PHONY:		all clean fclean re