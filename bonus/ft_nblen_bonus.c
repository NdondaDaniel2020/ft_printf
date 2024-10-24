/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:42:03 by nmatondo          #+#    #+#             */
/*   Updated: 2024/05/28 12:43:04 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

int	ft_nblen(long long nb, int base)
{
	long int	i;

	i = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	if (nb == 0)
		i++;
	while (nb)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

static int condition_move(char c)
{
	if (c == 'c')
		return (0);
	if (c == 's')
		return (0);
	if (c == 'p')
		return (0);
	if (c == 'd')
		return (0);
	if (c == 'i')
		return (0);
	if (c == 'u')
		return (0);
	if (c == 'x')
		return (0);
	if (c == 'X')
		return (0);
	if (c == '%')
		return (0);
	return (1);
}

static void	get_number(t_data *data, int *i)
{
	if (data->str[*i] == '0')
		data->zero = true;
	else
	{
		data->number = data->str[*i] - '0';
		if (ft_isdigit(data->str[*i + 1]))
		{
			while (ft_isdigit(data->str[*i + 1]))
			{
				data->number = (data->number * 10) + (data->str[*i + 1] - '0');
				(*i)++;
			}
		}
	}
}

static void	get_number_str(t_data *data, int *i)
{
	data->number_str = data->str[*i] - '0';
	if (ft_isdigit(data->str[*i + 1]))
	{
		while (ft_isdigit(data->str[*i + 1]))
		{
			data->number_str = (data->number_str * 10) + (data->str[*i + 1] - '0');
			(*i)++;
		}
	}
}

void	get_formatting_data(t_data *data, int *i)
{
	while (data->str[*i] != '\0' && condition_move(data->str[*i]))
	{
		if (data->str[*i] == ' ')
			data->space = true;
		else if (data->str[*i] == '#')
			data->hastag = true;
		else if (data->str[*i] == '+')
			data->plas = true;
		else if (data->str[*i] == '-')
			data->negative = true;
		else if (data->str[*i] == '.')
			data->point = true;
		else if (ft_isdigit(data->str[*i]) && data->str[*i - 1] != '.')
			get_number(data, i);
		else if (ft_isdigit(data->str[*i]) && data->str[*i - 1] == '.')
			get_number_str(data, i);
		(*i)++;
	}
}
