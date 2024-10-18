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

static int	digit_counter(long int n)
{
	long int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int add_prefix(const char *str, int i, int len)
{
	if (str[i + 1] == 'x' || str[i + 1] == 'X')
	{
		len += 2;
		ft_putchar_fd('0', 1);
		if (str[i + 1] == 'x')
			ft_putchar_fd('x', 1);
		if (str[i + 1] == 'X')
			ft_putchar_fd('X', 1);
	}
	return (len);
}

int add_space(const char *str, int i, va_list args, int len)
{
	int			re;
	int			len_arg;
	char		chr_arg;
	char		*str_arg;
	long long	value_arg;

	value_arg = 0;
	str_arg = NULL;
	re = str[i] - '0';
	while (ft_isdigit(str[i + 1]))
	{
		re = (re * 10) + (str[i + 1] - '0');
		i++;
	}
	if (str[i + 1] == 'c')
	{
		chr_arg = va_arg(args, int);
		len_arg = 1;
	}
	if (str[i + 1] == 'i' || str[i + 1] == 'd' || str[i + 1] == 'p'
	 || str[i + 1] == 'x' || str[i + 1] == 'X' || str[i + 1] == 'u')
	{
		value_arg = va_arg(args, unsigned long long);
		len_arg = digit_counter(value_arg);
		if (str[i + 1] == 'p')
			len_arg--;
	}
	if (str[i + 1] == 's')
	{
		str_arg = va_arg(args, char *);
		len_arg = ft_strlen(str_arg);
	}

	len_arg = re - len_arg;
	while (len_arg > 0)
	{
		ft_putchar_fd(' ', 1);
		len_arg--;
	}

	if (str[i + 1] == 'c')
		len = ft_putchar(chr_arg, len);
	if (str[i + 1] == 's')
		len = ft_putstr(str_arg, len);
	if (str[i + 1] == 'u')
		len = ft_put_unsigned(value_arg, len);
	if (str[i + 1] == 'i' || str[i + 1] == 'd')
		len = ft_putnbr_base(value_arg, 10, 0, len);
	if (str[i + 1] == 'p')
		len = ft_put_end_mem(value_arg, len);
	if (str[i + 1] == 'x')
		len = ft_putnbr_base(value_arg, 16, 0, len);
	if (str[i + 1] == 'X')
		len = ft_putnbr_base(value_arg, 16, 1, len);

	return ((re -1) + len);
}

int	format_specifiers(const char *str, int *i, va_list args, int len)
{
	if (str[*i] == '#')
	{
		len = add_prefix(str, *i, len);
		(*i)++;
		len = ft_print_pars(str[*i], args, len);
	}
	if (ft_isdigit(str[*i]) && str[*i] != '0')
	{
		len = add_space(str, *i, args, len);
		while (ft_isdigit(str[*i + 1]))
			(*i)++;
		(*i)++;
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
