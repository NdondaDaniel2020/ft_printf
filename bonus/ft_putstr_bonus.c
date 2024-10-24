/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:39:59 by nmatondo          #+#    #+#             */
/*   Updated: 2024/06/07 13:49:52 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putstr(char *s, int count)
{
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		count += 6;
	}
	else
	{
		count += ft_strlen(s);
		while (*s)
		{
			ft_putchar_fd(*s, 1);
			++s;
		}
	}
	return (count);
}

int	ft_putstr_format(char *s, int count, int number_printed)
{
	int	len;

	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		count += 6;
	}
	else
	{
		len = ft_strlen(s);
		if (number_printed < len)
			len = number_printed;
		count += len;
		while (*s && number_printed)
		{
			ft_putchar_fd(*s, 1);
			number_printed--;
			++s;
		}
	}
	return (count);
}

void	init_data(t_data *data)
{
	data->negative = false;
	data->zero = false;
	data->point = false;
	data->hastag = false;
	data->space = false;
	data->plas = false;
	data->number = 0;
	data->number_str = 0;
	data->len_caraters = 0;
	data->str = NULL;
}
