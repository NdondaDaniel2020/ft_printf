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

# cc main.c -L. -lftprintf -L. ./libft/libft.a -I ./include -I ./libft -o main

CC = cc
NAME = libftprintf.a
BNAME = libftprintf_bonus.a
DIR_LIBFT = ./libft/
INCLUDE = ./include/
LIBFT = $(DIR_LIBFT)libft.a
SRC = ./src/
SRC_BONUS = ./bonus/
FILES = ft_nblen.c \
		ft_printf.c \
		ft_putchar.c \
		ft_put_end_mem.c \
		ft_putnbr_base.c \
		ft_putstr.c \
		ft_put_unsigned.c

SRC_FILES = $(addprefix $(SRC),$(FILES))
OBJS = $(FILES:.c=.o)
BFILES = ft_nblen_bonus.c \
		 ft_printf_bonus.c \
		 ft_putchar_bonus.c \
		 ft_put_end_mem_bonus.c \
		 ft_putnbr_base_bonus.c \
		 ft_putstr_bonus.c \
		 ft_put_unsigned_bonus.c \
		 ft_format_bonus.c

SRC_BFILES = $(addprefix $(SRC_BONUS),$(BFILES))
BOBJS = $(BFILES:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: $(BNAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS): $(LIBFT)
	@$(CC) $(FLAGS) -c $(SRC_FILES) -L $(LIBFT) -I $(INCLUDE) -I $(DIR_LIBFT)

$(BNAME): $(BOBJS)
	ar rc $(BNAME) $(BOBJS)

$(BOBJS): $(LIBFT)
	@$(CC) $(FLAGS) -c $(SRC_BFILES) -L $(LIBFT) -I $(INCLUDE) -I $(DIR_LIBFT)

$(LIBFT):
	@$(MAKE) bonus -C $(DIR_LIBFT)

main: fclean $(BNAME)
	cc main.c -L. -lftprintf_bonus -L. ./libft/libft.a -I ./include -I ./libft -o main
	make clean

clean:
	@/bin/rm -f $(OBJS) $(BOBJS)

fclean:	clean
	@$(MAKE) fclean -C $(DIR_LIBFT)
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(BNAME)

re: fclean all
.PHONY: all clean fclean re bonus main