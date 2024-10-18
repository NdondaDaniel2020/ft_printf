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

int main(void)
{
	int num = 42;
    unsigned int unum = 123456;
    char ch = 'A';
    char str[] = "OpenAI";
    void *ptr = &num;
    
    // ft_printf("\n\nNúmero: %d\n", num);
    // ft_printf("String: %s\n", str);
    // ft_printf("Caractere: %c\n", 'A');
    // ft_printf("Hexadecimal: %#x\n\n", num);

    ft_printf("'%20c'\n", ch);
	printf("'%20c'\n", ch);

    ft_printf("'%20i'\n", ch);
	printf("'%20i'\n", ch);

    ft_printf("'%20s'\n", str);
	printf("'%20s'\n", str);

	ft_printf("'%20p'\n", ptr);
	printf("'%20p'\n", ptr);

	ft_printf("'%20x'\n", num);
	   printf("'%20x'\n", num);
		
	// ft_printf("'%#20X'\n", num);
	// printf("'%#20X'\n", num);

	// ft_printf("'%20u'\n", unum);
	// printf("'%20u'\n", unum);

    return 0;
}
