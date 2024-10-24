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

	int i1 =    printf("'%5.1s'\n", str);
	int i2 = ft_printf("'%5.1s'\n", str);

	// printf("(%i %i)\n", i1, i2);

    // // %+10d: Número com sinal positivo ou negativo, largura mínima de 10.
    ft_printf("'%+10d'\n", num);
	   printf("'%+10d'\n", num);

    // // % 10d: Número com espaço antes de números positivos, largura mínima de 10.
    // ft_printf("'% 10d'\n", num);
	//    printf("'% 10d'\n", num);

    // // %010d: Número com zeros à esquerda, largura mínima de 10.
    // ft_printf("'%010d'\n", num);
	//    printf("'%010d'\n", num);

    // // %#x: Número hexadecimal com prefixo "0x".
    // ft_printf("'%#x'\n", num);
	//    printf("'%#x'\n", num);

    // // %#X: Número hexadecimal com prefixo "0X" (maiúsculas).
    // ft_printf("'%#X'\n", num);
	//    printf("'%#X'\n", num);

    // // %-10s: String alinhada à esquerda com largura mínima de 10.
    // ft_printf("'%-10s'\n", str);
	//    printf("'%-10s'\n", str);

    // // %.3s: String com precisão de 3 caracteres.
    // ft_printf("'%.3s'\n", str);
	//    printf("'%.3s'\n", str);

    // %10u: Número sem sinal, com largura mínima de 10.
    // ft_printf("'%10u'\n", unum);
	//    printf("'%10u'\n", unum);

    // // %+10i: Número inteiro com sinal positivo ou negativo, largura mínima de 10.
    // ft_printf("'%+10i'\n", num);
	//    printf("'%+10i'\n", num);

    // // %%: Imprime o sinal de porcentagem.
    // ft_printf("'%%'\n");
	//    printf("'%%'\n");

    return 0;
}


/*
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
*/