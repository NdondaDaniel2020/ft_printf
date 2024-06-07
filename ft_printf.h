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
# include "libft.h"

int	ft_putnbr_base(long int nb, int base, int tan, int count);
int	ft_put_end_mem(unsigned long long nb, int count);
int	ft_put_unsigned(unsigned int nb, int count);
int	ft_printf(const char *format, ...);
int	ft_nblen(long long nb, int base);
int	ft_putchar(char c, int count);
int	ft_putstr(char *s, int count);

#endif
