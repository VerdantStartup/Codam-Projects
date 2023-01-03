# Marcos #

NAME = push_swap
LIBFT		= libft
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= gcc
CFLAGS		=  -g -I include
RM			= rm -f
AR			= ar rcs

SRC_FILES	=	push_swap_big\
				push_swap_error\
				push_swap_init\
				push_swap_oper\
				push_swap_sort\
				push_swap_utils\
				push_swap\

SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF			= test

# Colors #

C_RESET = "\033[0m"
C_GREEN = "\033[92m"


all: $(NAME)

$(NAME): $(OBJ)
	@ $(CC) $(CFLAGS) $(INCLUDE) $(OBJ) -o $(NAME)
	@echo $(C_GREEN)"Push_swap compilied"$(C_RESET)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@$(CC) $(CFLAGS) -c $< $(INCLUDE) -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) -r $(OBJ_DIR)
	@echo "$(Red)All libs cleaned$(Reset)"

re: fclean all
	@echo "$(Yellow)Recomplied everything$(Reset)"

.PHONY: all clean fclean re
