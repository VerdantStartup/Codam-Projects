# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: verdant <verdant@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 11:34:35 by verdant           #+#    #+#              #
#    Updated: 2022/12/22 12:33:57 by verdant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Marcos #

NAME			= libftprintf.a
INCLUDE		= include/
LIBFT			= libft
SRC_DIR		= src/
OBJ_DIR		= obj/
CC				= gcc
CFLAGS		= -Wall -Wextra -Werror -I
RM				= rm -f
AR				= ar rcs

# Colors #

C_RESET		=	"\033[0m"
C_GREEN		=	"\033[92m"

# Sources #

SRC_FILES	=	ft_printf ft_printf_utils ft_base_itoa\

SRC				= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ				= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF			= test

all: $(NAME)

$(NAME): $(OBJ)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(AR) $(NAME) $(OBJ)
			@echo $(C_GREEN)"ft_printf complied"$(C_RESET)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -rf $(OBJ_DIR)
			@make clean -C $(LIBFT)

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(LIBFT)/libft.a


re: fclean all

.PHONY: all clean fclean