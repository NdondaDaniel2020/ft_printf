/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:03:23 by nmatondo          #+#    #+#             */
/*   Updated: 2024/05/31 10:49:13 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"

typedef struct s_data
{
	bool	negative;
	bool	zero;
	bool	point;
	bool	hastag;
	bool	space;
	bool	plas;
	int		number;
	int		number_str;
	int		len_caraters;
	char	*str;
	va_list	args;
}			t_data;

int		ft_putnbr_base(long int nb, int base, int tan, int count);
int		ft_put_end_mem(unsigned long long nb, int count);
int		ft_put_unsigned(unsigned int nb, int count);
int		ft_printf(const char *format, ...);
int		ft_nblen(long long nb, int base);
int		ft_putchar(char c, int count);
int		ft_putstr(char *s, int count);

int		ft_putstr_format(char *s, int count, int number_printed);
int		ft_print_pars(const char c, va_list args, int len, int number_printed);

void	print_format(t_data *data, int *i);
void	init_data(t_data *data);
void	get_formatting_data(t_data *data, int *i);

#endif
