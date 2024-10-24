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

int	ft_print_pars(const char c, va_list args, int len, int number_printed)
{
	if (c == 'd' || c == 'i')
		len = ft_putnbr_base(va_arg(args, int), 10, 0, len);
	else if (c == 'c')
		len = ft_putchar(va_arg(args, int), len);
	else if (c == '%')
		len = ft_putchar('%', len);
	else if (c == 's')
		len = ft_putstr_format(va_arg(args, char *), len, number_printed);
	else if (c == 'x')
		len = ft_putnbr_base(va_arg(args, unsigned int), 16, 0, len);
	else if (c == 'X')
		len = ft_putnbr_base(va_arg(args, unsigned int), 16, 1, len);
	else if (c == 'p')
		len = ft_put_end_mem(va_arg(args, unsigned long long), len);
	else if (c == 'u')
		len = ft_put_unsigned(va_arg(args, unsigned int), len);
	return (len);
}

static int	ft_print_args(t_data *data)
{
	int	i;

	i = 0;
	while (data->str[i] != '\0')
	{
		if (data->str[i] == '%')
		{
			i++;
			get_formatting_data(data, &i);
			print_format(data, &i);
			i++;
		}
		else
		{
			ft_putchar_fd(data->str[i], 1);
			data->len_caraters++;
			i++;
		}
	}
	return (data->len_caraters);
}

int	ft_printf(const char *format, ...)
{
	t_data		data;

	init_data(&data);
	if (!*format || !format)
		return (0);
	data.str =  ft_strdup(format);
	va_start(data.args, format);
	data.len_caraters = ft_print_args(&data);
	va_end(data.args);
	return (data.len_caraters);
}
