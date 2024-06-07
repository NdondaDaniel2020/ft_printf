
NAME = libftprintf.a
LIBFT = ./Libft/
FILES =  *.c */*.c
FLAGS = -Wall -Wextra -Werror
OBJS = *.o

all: $(NAME)

bonus:	all

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS):
	gcc $(FLAGS) -c $(FILES) -I $(LIBFT)

clean:
	/bin/rm -f $(OBJS)

fclean:	clean
	/bin/rm -f $(NAME)

re: fclean all