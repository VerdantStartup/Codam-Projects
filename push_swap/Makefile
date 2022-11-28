NAME = push_swap.a

SCRS = push_swap.c push_swap_utils.c \
push_swap_oper_b.c push_swap_oper_a  \
push_swap_init.c push_swap_error.c   \

OFILES = $(SRCS:c=o)

INCLUDES = push_swap.h

all: $(NAME)

$(NAME): $(OFILES) $(INCLUDES)
	ar rcs $(NAME) $?

%.c: %.c
	$(CC)
