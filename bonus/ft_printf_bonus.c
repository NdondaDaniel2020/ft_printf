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

int	format_specifiers(const char *str, int *i, va_list args, int len)
{
	if (str[*i] == '#')
	{
		len = add_prefix(str, *i, len);
		(*i)++;
		len = ft_print_pars(str[*i], args, len);
	}
	else
		len = ft_print_pars(str[*i], args, len);
	return (len);
}

static int	ft_print_args(const char *str, va_list args)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			len = format_specifiers(str, &i, args, len);
			// len = ft_print_pars(str[i], args, len);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len++;
			i++;
		}
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int			len;
	va_list		args;
	const char	*str;

	if (!*format || !format)
		return (0);
	len = 0;
	str = format;
	va_start(args, format);
	len = ft_print_args(str, args);
	va_end(args);
	return (len);
}
