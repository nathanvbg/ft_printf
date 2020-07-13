
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
LFT_SRC = libft
LIBFT = $(LFT_SRC)/libft.a
HEADERS_GCH = ft_printf.h.gch
SRCS =	ft_printf.c \
		check_flags.c \
		check_specifier.c \
		specifier_int.c \
		specifier_str.c \
		specifier_rest.c \
		main.c
OBJS = $(SRCS:.c=.o)
all: $(LIBFT) $(NAME)
$(NAME): $(OBJS)
	@echo "Compilation ft_printf..."
	@cp $(LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJS)
	@gcc  $(FLAGS) $(SOURCES) $(LIBFT) $(NAME)
	@echo "Compilation ft_printf\t\t\033[0;32m[OK]\033[0m"
$(LIBFT):
	@(cd $(LFT_SRC) && $(MAKE))
clean:
	@rm -f $(OBJS)
	@(cd $(LFT_SRC) && $(MAKE) $@)
	@echo "Cleaning Objects ft_printf\t\033[0;32m[OK]\033[0m"
fclean: clean
	@rm -f $(NAME)
	@rm -f $(HEADERS_GCH)
	@rm -f ./a.out
	@(cd $(LFT_SRC) && $(MAKE) $@)
	@echo "Cleaning libftprintf.a\t\t\033[0;32m[OK]\033[0m"
re: fclean all
.PHONY:all fclean re
