##
NAME			= client
NAMESV		= server
LIBFT			= libft
INC				= include
HEADER		= -I include
SRC_DIR		= src/
OBJ_DIR		= obj/
CC				= gcc
CFLAGS		= -Wall -Wextra -Werror
RM				= rm -rf
##
C_RESET = "\033[0m"
C_GREEN = "\033[92m"
###
SRCCL_FILES	=	client
SRCSV_FILES	=	server
##
SRCCL 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCCL_FILES)))
OBJCL 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCCL_FILES)))
##
SRCSV 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCSV_FILES)))
OBJSV 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCSV_FILES)))

###

OBJF		=	nothing

start:
			@make -C $(LIBFT)
			@echo $(C_GREEN)"Libft complied"$(C_RESET)
			@cp $(LIBFT)/libft.a .
			@make all

all:			$(NAME) $(NAMESV)

$(NAME):	$(OBJCL) $(OBJF)
			@$(CC) $(CFLAGS) $(OBJCL) $(HEADER) libft.a -o $(NAME)
			@echo $(C_GREEN)"minitalk complied"$(C_RESET)

$(NAMESV):	$(OBJSV) $(OBJF)
			@$(CC) $(FLAGS) $(OBJSV) $(HEADER) libft.a -o $(NAMESV)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(OBJF)
			@$(CC) $(FLAGS) $(HEADER) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(OBJF)
	@make clean -C $(LIBFT)

fclean: clean
	@$(RM) $(NAME) $(NAMESV)
	@$(RM) $(LIBFT)/libft.a
	@$(RM) libft.a
	@find . -name ".DS_Store" -delete

re:			fclean start

.PHONY:	start all clean fclean re