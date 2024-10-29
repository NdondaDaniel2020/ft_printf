/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:06:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/05/31 10:48:16 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

static void	add_format_one_space(t_data *data, int *i)
{
	int			len;
	long long	value;
	va_list		cpy_arg;

	va_copy(cpy_arg, data->args);
	if (data->str[*i] == 'd' || data->str[*i] == 'i' || data->str[*i] == 'p')
	{
		len = 0;
		value = 0;

		if (data->str[*i] == 'p')
			value = va_arg(cpy_arg, long long);		
		else
			value = va_arg(cpy_arg, int);
		if (value > 0)
		{
			data->len_caraters++;
			ft_putchar_fd(' ', 1);
		}
	}
	if (data->str[*i] == 's')
		len = ft_strlen(va_arg(cpy_arg, char *));
	va_end(cpy_arg);
	data->len_caraters = ft_print_pars(data->str[*i], data->args, data->len_caraters, len);
}

static void	add_format_plus(t_data *data, int *i)
{
	va_list 	cpy_arg;

	va_copy(cpy_arg, data->args);
	if (va_arg(cpy_arg, int) >= 0)
	{
		data->len_caraters++;
		ft_putchar_fd('+', 1);
	}
	va_end(cpy_arg);
	data->len_caraters = ft_print_pars(data->str[*i], data->args, data->len_caraters, 0);
}




static void add_format_comb_number(t_data *data, int *i)
{
	int			len;
	int			value;
	char		chr;
	bool		es_case;
	va_list 	cpy_arg;

	es_case = false;
	va_copy(cpy_arg, data->args);
	value = va_arg(cpy_arg, int);
	if (data->str[*i] == 'x' || data->str[*i] == 'X' || data->str[*i] == 'p')
	{
		len = ft_nblen(value, 16);
		data->number--;
	}
	else if (data->str[*i] == 'i' || data->str[*i] == 'd')
		len = ft_nblen(value, 10);
	if (data->zero)
		chr = '0';
	else
		chr = ' ';
	if (data->str[*i] == 'x' || data->str[*i] == 'X' || data->str[*i] == 'p')
	{
		es_case = true;
		data->number++;
	}	
	if (data->plas && !data->number_str && value >= 0 && data->str[*i] != 'u')
	{
		len++;
		data->len_caraters++;
		if (data->zero)
			ft_putchar_fd('+', 1);
	}
	if (data->zero && data->space && value >= 0)
	{
		ft_putchar_fd(' ', 1);
		len++;
	}
	data->number -= len;
	if (data->zero && !data->number_str && value < 0 && (data->str[*i] == 'i' || data->str[*i] == 'd'))
	{
		data->len_caraters++;
		va_arg(data->args, int);
		ft_putchar_fd('-', 1);
		value *= -1;
	}
	if (data->number && data->number_str)
	{
		data->number_str -= len;
		data->number -= data->number_str;
		if (data->number_str && value < 0 && (data->str[*i] == 'i' || data->str[*i] == 'd'))
			data->number--;
		if (data->number_str && data->plas && value >= 0 && (data->str[*i] == 'i' || data->str[*i] == 'd'))
			data->number--;
		if (data->space && value >= 0)
		{
			data->number_str++;
			data->number--;
		}
		while (data->number--)
		{
			data->len_caraters++;
			ft_putchar_fd(' ', 1);
		}
		if (data->number_str && data->plas && value >= 0 && (data->str[*i] == 'i' || data->str[*i] == 'd'))
			ft_putchar_fd('+', 1);
		if (data->number_str && value < 0 && (data->str[*i] == 'i' || data->str[*i] == 'd'))
		{
			data->number--;
			data->number_str++;
			data->len_caraters++;
			va_arg(data->args, int);
			ft_putchar_fd('-', 1);
			value *= -1;
		}
		while (data->number_str--)
		{
			data->len_caraters++;
			ft_putchar_fd('0', 1);
		}
	}
	else
	{
		while (data->number--)
		{
			data->len_caraters++;
			ft_putchar_fd(chr, 1);
		}
	}
	if (data->plas && value >= 0  && data->str[*i] != 'u')
	{
		if (!data->zero && data->str[*i] != 'u' && !data->number_str)
			ft_putchar_fd('+', 1);
	}
	if (es_case)
		data->len_caraters = ft_print_pars(data->str[*i], data->args, data->len_caraters, 0);
	else
		data->len_caraters = ft_putnbr_base(value, 10, 0, data->len_caraters);
	va_end(cpy_arg);
}

static void add_format_comb_number_reverse(t_data *data, int *i)
{
	int			len;
	int			value;
	bool		es_case;
	va_list 	cpy_arg;

	es_case = false;
	va_copy(cpy_arg, data->args);
	value = va_arg(cpy_arg, int);
	if (data->str[*i] == 'x' || data->str[*i] == 'X' || data->str[*i] == 'p')
	{
		len = ft_nblen(value, 16);
		data->number--;
	}
	else if (data->str[*i] == 'i' || data->str[*i] == 'd')
		len = ft_nblen(value, 10);
	if (data->str[*i] == 'x' || data->str[*i] == 'X' || data->str[*i] == 'p')
	{
		es_case = true;
		data->number++;
	}
	if (data->zero && data->space)
	{
		data->len_caraters++;
		ft_putchar_fd(' ', 1);
		len++;
	}
	if (data->plas && value >= 0)
	{
		len++;
		data->len_caraters++;
		ft_putchar_fd('+', 1);
		if (data->plas && data->number_str)
			data->number_str++;
	}
	if (data->space && data->zero && data->number_str)
		data->number_str++;
	if (data->number_str && value < 0 && (data->str[*i] == 'i' || data->str[*i] == 'd'))
	{
		data->number_str++;
		data->len_caraters++;
		va_arg(data->args, int);
		ft_putchar_fd('-', 1);
		value *= -1;
	}
	if (data->number_str)
	{
		data->number_str -= len;
		data->number -= data->number_str;
		while (data->number_str--)
		{
			data->len_caraters++;
			ft_putchar_fd('0', 1);
		}
	}
	if (es_case)
		data->len_caraters = ft_print_pars(data->str[*i], data->args, data->len_caraters, 0);
	else
		data->len_caraters = ft_putnbr_base(value, 10, 0, data->len_caraters);
	data->number -= len;
	while (data->number--)
	{
		data->len_caraters++;
		ft_putchar_fd(' ', 1);
	}
	va_end(cpy_arg);
}




static void add_format_comb_str(t_data *data, int *i)
{
	int			len;
	va_list 	cpy_arg;

	va_copy(cpy_arg, data->args);
	if (data->str[*i] == 's')
		len = ft_strlen(va_arg(cpy_arg, char *));
	else
		len = 1;
	if (data->point && data->str[*i] == 's')
		len = data->number_str;
	data->number -= len;
	while (data->number > 0)
	{
		data->len_caraters++;
		ft_putchar_fd(' ', 1);
		data->number--;
	}
	va_end(cpy_arg);
	data->len_caraters = ft_print_pars(data->str[*i], data->args, data->len_caraters, len);
}

static void add_format_comb_str_reverse(t_data *data, int *i)
{
	int			len;
	va_list 	cpy_arg;

	va_copy(cpy_arg, data->args);
	if (data->str[*i] == 's')
		len = ft_strlen(va_arg(cpy_arg, char *));
	else
		len = 1;
	if (data->point && data->str[*i] == 's')
		len = data->number_str;
	data->len_caraters = ft_print_pars(data->str[*i], data->args, data->len_caraters, len);
	data->number -= len;
	while (data->number > 0)
	{
		data->len_caraters++;
		ft_putchar_fd(' ', 1);
		data->number--;
	}
	va_end(cpy_arg);
}



static void	add_format_comb_point(t_data *data, int *i)
{
	int			len;
	int			value;
	va_list 	cpy_arg;

	va_copy(cpy_arg, data->args);
	value = va_arg(cpy_arg, int);
	if (data->str[*i] == 'x' || data->str[*i] == 'X' || data->str[*i] == 'p')
		len = ft_nblen(value, 16);
	else if (data->str[*i] == 'i' || data->str[*i] == 'd')
		len = ft_nblen(value, 10);
	if (value >= 0)
	{
		data->number_str -= len;
		if (data->number_str)
		{
			while (data->number_str--)
			{
				data->len_caraters++;
				ft_putchar_fd('0', 1);
			}
		}
	}
	data->len_caraters = ft_print_pars(data->str[*i], data->args, data->len_caraters, 0);
	va_end(cpy_arg);
}





void	print_format(t_data *data, int *i)
{
	// '-', '0', '.', '#', ' ', '+'
	if (data->space && !data->plas && !data->negative && !data->zero && !data->point && !data->hastag && !data->number)
		add_format_one_space(data, i);
	else if (data->plas && !data->space && !data->negative && !data->zero && !data->point && !data->hastag && !data->number && (data->str[*i] == 'i' || data->str[*i] == 'd' || data->str[*i] == 'p'))
		add_format_plus(data, i);
	
	
	else if (data->number && !data->negative && !data->hastag && data->str[*i] != 's' && data->str[*i] != 'c')
		add_format_comb_number(data, i);
	else if (data->number && data->negative && !data->hastag && data->str[*i] != 's' && data->str[*i] != 'c')
		add_format_comb_number_reverse(data, i);


	else if (data->point && data->number_str && !data->hastag)
		add_format_comb_point(data, i);


	else if ((data->number || data->number_str) && !data->negative && !data->hastag && (data->str[*i] == 's' || data->str[*i] == 'c'))
		add_format_comb_str(data, i);
	else if ((data->number || data->number_str) && data->negative && !data->hastag && (data->str[*i] == 's' || data->str[*i] == 'c'))
		add_format_comb_str_reverse(data, i);
	
	else if (data->hastag && !data->negative && (data->str[*i] == 'X' || data->str[*i] == 'x'))
	{
		int			len;
		int			len_cpy;
		int			value;
		bool		printed;
		va_list 	cpy_arg;
	
		printed = false;
		va_copy(cpy_arg, data->args);
		value = va_arg(cpy_arg, int);
		len = ft_nblen(value, 16);
		len_cpy = len;
		if (data->number && !data->number_str && !data->zero)
		{
			len += 2;
			printed = true;
			data->number -= len;
			while (data->number)
			{
				data->number--;
				data->len_caraters++;
				ft_putchar_fd(' ', 1);
			}
		}
		if (data->number && data->number_str && data->point)
		{
			if (data->number_str > len_cpy)
				data->number = (data->number - 2) - data->number_str;
			else
				data->number = (data->number - 2) - len_cpy;
			while (data->number > 0)
			{
				data->number--;
				data->len_caraters++;
				ft_putchar_fd(' ', 1);
			}
		}
		data->len_caraters += 2;
		if (data->str[*i] == 'x')
		{
			ft_putchar_fd('0', 1);
			ft_putchar_fd('x', 1);
		}
		else
		{
			ft_putchar_fd('0', 1);
			ft_putchar_fd('X', 1);
		}
		if (data->number && !printed && !data->number_str)
		{
			len += 2;
			data->number -= len;
			while (data->number > 0)
			{
				data->number--;
				data->len_caraters++;
				ft_putchar_fd('0', 1);
			}
		}
		if (data->number_str && data->point && !data->number)
		{	
			data->number_str -= len;
			while (data->number_str > 0)
			{
				data->number_str--;
				data->len_caraters++;
				ft_putchar_fd('0', 1);
			}
		}
		if (data->number_str && data->number && data->point)
		{
			data->number_str -= len;
			while (data->number_str > 0)
			{
				data->number_str--;
				data->len_caraters++;
				ft_putchar_fd('0', 1);
			}
		}
		data->len_caraters = ft_print_pars(data->str[*i], data->args, data->len_caraters, 0);
		va_end(cpy_arg);
	}
	/*else if (data->hastag && data->negative && (data->str[*i] == 'X' || data->str[*i] == 'x'))
	{
		'0x000000007b'
	'    0x000000007b'
		[7 1 7]      
		data->len_caraters += 2;
		if (data->str[*i] == 'x')
		{
			ft_putchar_fd('0', 1);
			ft_putchar_fd('x', 1);
		}
		else
		{
			ft_putchar_fd('0', 1);
			ft_putchar_fd('X', 1);
		}
		data->len_caraters = ft_print_pars(data->str[*i], data->args, data->len_caraters, 0);
	}*/
	else
		data->len_caraters = ft_print_pars(data->str[*i], data->args, data->len_caraters, 0);
}
