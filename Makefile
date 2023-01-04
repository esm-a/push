CC := cc
CFLAGS := -Wall -Werror -Wextra
RM := rm -rf

INCLUDE := -I includes/
HEADERS := includes/push_swap.h		\
			includes/libft.h		\
			includes/ft_fprintf.h

OBJ_DIR := obj/
SRC_DIR := src/
LIB_DIR := lib/

SRCS = push_swap.c			\
		swap.c				\
		push.c				\
		rotate.c			\
		reverse_rotate.c
LIBFT_SRCS = libft/*.c
FPRINTF_SRCS = ft_fprintf/*.c

OBJS = $(addprefix $(OBJ_DIR),$(SRCS:%.c=%.o))

NAME := push_swap
LIBS = $(LIB_DIR)*.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@make -C ft_fprintf
	$(CC) $^ $(LIBS) -o $@

$(OBJ_DIR)%.o: %.c $(LIBFT_SRCS) $(FPRINTF_SRCS) $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(LIB_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
fclean: clean
	$(RM) $(LIB_DIR)
re: fclean all
