NAME = libftprintf.a
S_DIR = srcs/
SRCS = ft_printf.c parse_conv.c ft_printf_utils.c set_conv.c \
	   write_c_s.c write_num.c
S_PATH = $(addprefix $(S_DIR), $(SRCS))
INCS = -I includes/
OBJS = $(S_PATH:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB_DIR = lib/
LIBNAME = libft.a
LIB = lib/libft.a

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCS) -c $< -o $(<:.c=.o)

$(LIBNAME): $(LIB_DIR)
	make -C $(LIB_DIR)

$(NAME): $(OBJS) $(LIBNAME)
	cp $(LIB) $(NAME)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)
	make clean -C $(LIB_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIB_DIR)

re: fclean all

.PHONY: all clean fclean re
