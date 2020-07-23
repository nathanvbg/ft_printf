NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
LFT_SRC = libft
LIBFT = $(LFT_SRC)/libft.a
SRCS =	ft_printf.c\
		specifier_int.c\
		specifier_rest.c\
		specifier_str.c\
		check_flags.c\
		utils.c
OBJS = $(SRCS:.c=.o)
all: $(LIBFT) $(NAME)
$(NAME): $(OBJS)
	@echo "Compilation ft_printf..."
	@cp $(LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJS)
	@echo "Compilation ft_printf\t\t\033[0;32m[OK]\033[0m"
$(LIBFT):
	@(cd $(LFT_SRC) && $(MAKE))
clean:
	@rm -f $(OBJS)
	@(cd $(LFT_SRC) && $(MAKE) $@)
	@echo "Cleaning Objects ft_printf\t\033[0;32m[OK]\033[0m"
fclean: clean
	@rm -f $(NAME)
	@(cd $(LFT_SRC) && $(MAKE) $@)
	@echo "Cleaning libftprintf.a\t\t\033[0;32m[OK]\033[0m"
re: fclean all
.PHONY:all fclean re
