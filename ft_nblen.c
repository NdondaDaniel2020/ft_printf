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

#include "ft_printf.h"

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
