
SRC = *.c
NAME = libftprintf.a
OBJS = $(SRC:%.c=%.o)
GCC = gcc
RM = rm -rf
HEADER = include
LIBFT = libft
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

$(OBJS): $(SRC)
	$(GCC) -c $(SRC)

$(NAME): ${OBJS}
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	${RM} ${OBJS}
	make clean -C $(LIBFT)

fclean: clean
	${RM} ${NAME}
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all fclean clean re
