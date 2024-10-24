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
	va_list 	cpy_arg;

	va_copy(cpy_arg, data->args);
	value = va_arg(cpy_arg, int);
	len = ft_nblen(value, 10);
	if (data->zero)
		chr = '0';
	else
		chr = ' ';
	if (data->plas && value >= 0 && data->str[*i] != 'u')
	{
		len++;
		data->len_caraters++;
		if (data->zero)
			ft_putchar_fd('+', 1);
	}
	data->number -= len;
	while (data->number--)
	{
		data->len_caraters++;
		ft_putchar_fd(chr, 1);
	}
	if (data->plas && value >= 0  && data->str[*i] != 'u')
	{
		if (!data->zero && data->str[*i] != 'u')
			ft_putchar_fd('+', 1);
	}
	data->len_caraters = ft_print_pars(data->str[*i], data->args, data->len_caraters, 0);
	va_end(cpy_arg);
}

static void add_format_comb_number_reverse(t_data *data, int *i)
{
	int			len;
	int			value;
	va_list 	cpy_arg;

	va_copy(cpy_arg, data->args);
	
	value = va_arg(cpy_arg, int);
	len = ft_nblen(value, 10);
	if (data->plas && value >= 0)
	{
		len++;
		data->len_caraters++;
		ft_putchar_fd('+', 1);
	}
	data->len_caraters = ft_print_pars(data->str[*i], data->args, data->len_caraters, 0);
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

void	print_format(t_data *data, int *i)
{
	// '-', '0', '.', '#', ' ', '+'
	if (data->space && !data->plas &&
	   !data->negative && !data->zero &&
	   !data->point && !data->hastag && !data->number)
	{
		data->len_caraters++;
		ft_putchar_fd(' ', 1);
	}
	else if (data->plas && !data->space &&
			!data->negative && !data->zero &&
			!data->point && !data->hastag && !data->number && 
			(data->str[*i] == 'i' || data->str[*i] == 'd' || data->str[*i] == 'p'))
		add_format_plus(data, i);
	else if (data->number && !data->negative &&
			!data->point && !data->hastag && data->str[*i] != 's' && data->str[*i] != 'c')
		add_format_comb_number(data, i);
	else if (data->number && data->negative && !data->point && !data->hastag && data->str[*i] != 's' && data->str[*i] != 'c')
		add_format_comb_number_reverse(data, i);
	else if ((data->number || data->number_str) && !data->negative && !data->hastag && (data->str[*i] == 's' || data->str[*i] == 'c'))
		add_format_comb_str(data, i);
	else if ((data->number || data->number_str) && data->negative && !data->hastag && (data->str[*i] == 's' || data->str[*i] == 'c'))
		add_format_comb_str_reverse(data, i);
}
