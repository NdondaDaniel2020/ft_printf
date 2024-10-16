# **************************************************************************** #                                   
#                                                                              #                                   
#                                                         :::      ::::::::    #                                   
#    Makefile                                           :+:      :+:    :+:    #                                   
#                                                     +:+ +:+         +:+      #                                   
#    By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+         #                                   
#                                                 +#+#+#+#+#+   +#+            #                                   
#    Created: 2024/07/06 01:32:20 by nmatondo          #+#    #+#              #                                   
#    Updated: 2024/08/07 16:44:49 by nmatondo         ###   ########.fr        #                                   
#                                                                              #                                   
# **************************************************************************** #                                   

CC = cc
NAME = libftprintf.a
DIR_LIBFT = ./libft/
INCLUDE = ./include/
LIBFT = $(DIR_LIBFT)libft.a
SRC = ./src/
FILES = ft_nblen.c \
		ft_printf.c \
		ft_putchar.c \
		ft_put_end_mem.c \
		ft_putnbr_base.c \
		ft_putstr.c \
		ft_put_unsigned.c

FLAGS = -Wall -Wextra -Werror
SRC_FILES = $(addprefix $(SRC),$(FILES))
OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS): $(LIBFT)
	@$(CC) $(FLAGS) -c $(SRC_FILES) -L $(LIBFT) -I $(INCLUDE) -I $(DIR_LIBFT)

$(LIBFT):
	@$(MAKE) bonus -C $(DIR_LIBFT)

clean:
	@/bin/rm -f $(OBJS)

fclean:	clean
	@$(MAKE) fclean -C $(DIR_LIBFT)
	@/bin/rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re