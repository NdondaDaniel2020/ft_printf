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

int	ft_print_pars(const char c, va_list args, int len)
{
	if (c == 'd' || c == 'i')
		len = ft_putnbr_base(va_arg(args, int), 10, 0, len);
	else if (c == 'c')
		len = ft_putchar(va_arg(args, int), len);
	else if (c == '%')
		len = ft_putchar('%', len);
	else if (c == 's')
		len = ft_putstr(va_arg(args, char *), len);
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
