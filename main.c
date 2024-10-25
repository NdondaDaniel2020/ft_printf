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

    
	// %-10c: Caractere alinhado à esquerda com largura mínima de 10.
    //    printf("'% 1c'\n", ch);
	// ft_printf("'% 1c'\n", ch);

	// int i1 =    printf("'%-10.10d'\n", num);
	// int i2 = ft_printf("'%-10.d'\n", num);


	//    printf("'%10.5d'\n", 123);   // Saída: "     00123"
	// ft_printf("'%10.5d'\n", 123);   // Saída: "     00123"
 
	//    printf("'%10.5d'\n", -123);  // Saída: "    -00123"
	// ft_printf("'%10.5d'\n", -123);  // Saída: "    -00123"
	
	//    printf("'%+10.5d'\n", 123);  // Saída: "    +00123"
	// ft_printf("'%+10.5d'\n", 123);  // Saída: "    +00123"

	//    printf("'%+10.5d'\n", -123); // Saída: "    -00123"
	// ft_printf("'%+10.5d'\n", -123); // Saída: "    -00123"
	
	//    printf("'%-10.5d'\n", 123);  // Saída: "+00123    "
	// ft_printf("'%-10.5d'\n", 123);  // Saída: "+00123    "

	//    printf("'%-10.5d'\n", -123); // Saída: "-00123    "
	// ft_printf("'%-10.5d'\n", -123); // Saída: "-00123    "
	
	//    printf("'%010.5d'\n", 123);   // Saída: "     00123"
	// ft_printf("'%010.5d'\n", 123);   // Saída: "     00123"
	
	//    printf("'%010.5d'\n", -123);  // Saída: "    -00123"
	// ft_printf("'%010.5d'\n", -123);  // Saída: "    -00123"
	
	//    printf("'%+010.5d'\n", 123);   // Saída: "    +00123"
	// ft_printf("'%+010.5d'\n", 123);   // Saída: "    +00123"
	
	//    printf("'%+010.5d'\n", -123);  // Saída: "    -00123"
	// ft_printf("'%+010.5d'\n", -123);  // Saída: "    -00123"
	
	//    printf("'% 010.5d'\n", 123);   // Saída: "     00123"
	// ft_printf("'% 010.5d'\n", 123);   // Saída: "     00123"
	
   	// printf("'% 010.5d'\n", -123);  // Saída: "    -00123"
	// ft_printf("'% 010.5d'\n", -123);  // Saída: "    -00123"

	// printf("(%i %i)\n", i1, i2);

    return 0;
}
