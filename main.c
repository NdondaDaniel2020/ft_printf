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

	//    printf("'%#-8x'\n", 123);   // Saída: "     0x7b"
	// ft_printf("'%#-8x'\n", 123);   // Saída: "     0x7b"
	
	//    printf("'%#-8X'\n", 123);   // Saída: "     0X7B"
	// ft_printf("'%#-8X'\n", 123);   // Saída: "     0X7B"

	//    printf("'%-#8x'\n", 123);  // Saída: "0x7b    "
	// ft_printf("'%-#8x'\n", 123);  // Saída: "0x7b    "
	
	//    printf("'%-#8X'\n", 123);  // Saída: "0X7B    "
	// ft_printf("'%-#8X'\n", 123);  // Saída: "0X7B    "

	//    printf("'%-#10.5x'\n", 123); // Saída: "0x0007b   "
	// ft_printf("'%-#10.5x'\n", 123); // Saída: "0x0007b   "
	
	//    printf("'%-#10.5X'\n", 123); // Saída: "0X0007B   "
	// ft_printf("'%-#10.5X'\n", 123); // Saída: "0X0007B   "

	//    printf("'%-#10.4x'\n", 123); // Saída: "0x007b    "
	// ft_printf("'%-#10.4x'\n", 123); // Saída: "0x007b    "
	
	//    printf("'%-#10.4X'\n", 123); // Saída: "0X007B    "
	// ft_printf("'%-#10.4X'\n", 123); // Saída: "0X007B    "
	
	//    printf("'%-#10.4x'\n", 123); // Saída: "0x007b    "
	// ft_printf("'%-#10.4x'\n", 123); // Saída: "0x007b    "
	
	//    printf("'%-#10.4X'\n", 123); // Saída: "0X007B    "
	// ft_printf("'%-#10.4X'\n", 123); // Saída: "0X007B    "
	
	//    printf("'%-#10x'\n", 123);   // Saída: "0x7b      "
	// ft_printf("'%-#10x'\n", 123);   // Saída: "0x7b      "
	
	//    printf("'%-#10X'\n", 123);   // Saída: "0X7B      "
	// ft_printf("'%-#10X'\n", 123);   // Saída: "0X7B      "
	
	//    printf("'%-#08.5x'\n", 123);  // Saída: "0x0007b  "
	// ft_printf("'%-#08.5x'\n", 123);  // Saída: "0x0007b  "
	
	//    printf("'%-#08.5X'\n", 123);  // Saída: "0X0007B  "
	// ft_printf("'%-#08.5X'\n", 123);  // Saída: "0X0007B  "
	
	//    printf("'%-#10.3x'\n", 123); // Saída: "0x07b     "
	// ft_printf("'%-#10.3x'\n", 123); // Saída: "0x07b     "
	
	//    printf("'%-#10.3X'\n", 123); // Saída: "0X07B     "
	// ft_printf("'%-#10.3X'\n", 123); // Saída: "0X07B     "
	
	//    printf("'%-#15.3x'\n", 123); // Saída: "0x07b           "
	// ft_printf("'%-#15.3x'\n", 123); // Saída: "0x07b           "
	
	//    printf("'%-#15.3X'\n", 123); // Saída: "0X07B           "
	// ft_printf("'%-#15.3X'\n", 123); // Saída: "0X07B           "
	
	//    printf("'%-#15.6x'\n", 123); // Saída: "0x00007b       "
	// ft_printf("'%-#15.6x'\n", 123); // Saída: "0x00007b       "
	
	//    printf("'%-#15.6X'\n", 123); // Saída: "0X00007B       "
	// ft_printf("'%-#15.6X'\n", 123); // Saída: "0X00007B       "


	   printf("'%08x'\n", 123);   // Saída: "0000007b"
	ft_printf("'%08x'\n", 123);   // Saída: "0000007b"
	   printf("'%08X'\n", 123);   // Saída: "0000007B"
	ft_printf("'%08X'\n", 123);   // Saída: "0000007B"
	   printf("'%-8x'\n", 123);   // Saída: "7b      "
	ft_printf("'%-8x'\n", 123);   // Saída: "7b      "
	   printf("'%-8X'\n", 123);   // Saída: "7B      "
	ft_printf("'%-8X'\n", 123);   // Saída: "7B      "
	   printf("'%#8x'\n", 123);   // Saída: "     0x7b"
	ft_printf("'%#8x'\n", 123);   // Saída: "     0x7b"
	   printf("'%#8X'\n", 123);   // Saída: "     0X7B"
	ft_printf("'%#8X'\n", 123);   // Saída: "     0X7B"
	   printf("'%-#8x'\n", 123);  // Saída: "0x7b    "
	ft_printf("'%-#8x'\n", 123);  // Saída: "0x7b    "
	   printf("'%-#8X'\n", 123);  // Saída: "0X7B    "
	ft_printf("'%-#8X'\n", 123);  // Saída: "0X7B    "
	   printf("'%#08x'\n", 123);  // Saída: "0x00007b"
	ft_printf("'%#08x'\n", 123);  // Saída: "0x00007b"
	   printf("'%#08X'\n", 123);  // Saída: "0X00007B"
	ft_printf("'%#08X'\n", 123);  // Saída: "0X00007B"
	   printf("'%.5x'\n", 123);   // Saída: "0007b"
	ft_printf("'%.5x'\n", 123);   // Saída: "0007b"
	   printf("'%.5X'\n", 123);   // Saída: "0007B"
	ft_printf("'%.5X'\n", 123);   // Saída: "0007B"
	   printf("'%#.5x'\n", 123);  // Saída: "0x0007b"
	ft_printf("'%#.5x'\n", 123);  // Saída: "0x0007b"
	   printf("'%#.5X'\n", 123);  // Saída: "0X0007B"
	ft_printf("'%#.5X'\n", 123);  // Saída: "0X0007B"
	   printf("'%#10.5x'\n", 123); // Saída: "   0x0007b"
	ft_printf("'%#10.5x'\n", 123); // Saída: "   0x0007b"
	   printf("'%#10.5X'\n", 123); // Saída: "   0X0007B"
	ft_printf("'%#10.5X'\n", 123); // Saída: "   0X0007B"
	   printf("'%-#10.5x'\n", 123); // Saída: "0x0007b   "
	ft_printf("'%-#10.5x'\n", 123); // Saída: "0x0007b   "
	   printf("'%-#10.5X'\n", 123); // Saída: "0X0007B   "
	ft_printf("'%-#10.5X'\n", 123); // Saída: "0X0007B   "
	   printf("'%#010.5x'\n", 123); // Saída: "   0x0007b"
	ft_printf("'%#010.5x'\n", 123); // Saída: "   0x0007b"
	   printf("'%#010.5X'\n", 123); // Saída: "   0X0007B"
	ft_printf("'%#010.5X'\n", 123); // Saída: "   0X0007B"
	   printf("'%010.5x'\n", 123);  // Saída: "     0007b"
	ft_printf("'%010.5x'\n", 123);  // Saída: "     0007b"
	   printf("'%010.5X'\n", 123);  // Saída: "     0007B"
	ft_printf("'%010.5X'\n", 123);  // Saída: "     0007B"
	   printf("'%#0.5x'\n", 123);   // Saída: "0x0007b"
	ft_printf("'%#0.5x'\n", 123);   // Saída: "0x0007b"
	   printf("'%#0.5X'\n", 123);   // Saída: "0X0007B"
	ft_printf("'%#0.5X'\n", 123);   // Saída: "0X0007B"
	   printf("'%#12.6x'\n", 123);   // Saída: "    0x00007b"
	ft_printf("'%#12.6x'\n", 123);   // Saída: "    0x00007b"
	   printf("'%#12.6X'\n", 123);   // Saída: "    0X00007B"
	ft_printf("'%#12.6X'\n", 123);   // Saída: "    0X00007B"
	   printf("'%-#10x'\n", 123);   // Saída: "0x7b      "
	ft_printf("'%-#10x'\n", 123);   // Saída: "0x7b      "
	   printf("'%-#10X'\n", 123);   // Saída: "0X7B      "
	ft_printf("'%-#10X'\n", 123);   // Saída: "0X7B      "
	   printf("'%-10.6x'\n", 123);  // Saída: "00007b    "
	ft_printf("'%-10.6x'\n", 123);  // Saída: "00007b    "
	   printf("'%-10.6X'\n", 123);  // Saída: "00007B    "
	ft_printf("'%-10.6X'\n", 123);  // Saída: "00007B    "
	   printf("'%8.5x'\n", 123);    // Saída: "   0007b"
	ft_printf("'%8.5x'\n", 123);    // Saída: "   0007b"
	   printf("'%8.5X'\n", 123);    // Saída: "   0007B"
	ft_printf("'%8.5X'\n", 123);    // Saída: "   0007B"
	   printf("'%-#08.5x'\n", 123);  // Saída: "0x0007b  "
	ft_printf("'%-#08.5x'\n", 123);  // Saída: "0x0007b  "
	   printf("'%-#08.5X'\n", 123);  // Saída: "0X0007B  "
	ft_printf("'%-#08.5X'\n", 123);  // Saída: "0X0007B  "
	   printf("'%-#10.3x'\n", 123); // Saída: "0x07b     "
	ft_printf("'%-#10.3x'\n", 123); // Saída: "0x07b     "
	   printf("'%-#10.3X'\n", 123); // Saída: "0X07B     "
	ft_printf("'%-#10.3X'\n", 123); // Saída: "0X07B     "
	   printf("'%010x'\n", 123);     // Saída: "00000007b"
	ft_printf("'%010x'\n", 123);     // Saída: "00000007b"
	   printf("'%010X'\n", 123);     // Saída: "00000007B"
	ft_printf("'%010X'\n", 123);     // Saída: "00000007B"
	   printf("'%#10x'\n", 123);    // Saída: "     0x7b"
	ft_printf("'%#10x'\n", 123);    // Saída: "     0x7b"
	   printf("'%#10X'\n", 123);    // Saída: "     0X7B"
	ft_printf("'%#10X'\n", 123);    // Saída: "     0X7B"
	   printf("'%#15.8x'\n", 123);  // Saída: "      0x0000007b"
	ft_printf("'%#15.8x'\n", 123);  // Saída: "      0x0000007b"
	   printf("'%#15.8X'\n", 123);  // Saída: "      0X0000007B"
	ft_printf("'%#15.8X'\n", 123);  // Saída: "      0X0000007B"
	   printf("'%-#15.3x'\n", 123); // Saída: "0x07b           "
	ft_printf("'%-#15.3x'\n", 123); // Saída: "0x07b           "
	   printf("'%-#15.3X'\n", 123); // Saída: "0X07B           "
	ft_printf("'%-#15.3X'\n", 123); // Saída: "0X07B           "
	   printf("'%#5.8x'\n", 123);   // Saída: "0x0000007b"
	ft_printf("'%#5.8x'\n", 123);   // Saída: "0x0000007b"
	   printf("'%#5.8X'\n", 123);   // Saída: "0X0000007B"
	ft_printf("'%#5.8X'\n", 123);   // Saída: "0X0000007B"
	   printf("'%08.8x'\n", 123);   // Saída: "0000007b"
	ft_printf("'%08.8x'\n", 123);   // Saída: "0000007b"
	   printf("'%08.8X'\n", 123);   // Saída: "0000007B"
	ft_printf("'%08.8X'\n", 123);   // Saída: "0000007B"
	   printf("'%-#15.6x'\n", 123); // Saída: "0x00007b       "
	ft_printf("'%-#15.6x'\n", 123); // Saída: "0x00007b       "
	   printf("'%-#15.6X'\n", 123); // Saída: "0X00007B       "
	ft_printf("'%-#15.6X'\n", 123); // Saída: "0X00007B       "
	   printf("'%#0x'\n", 123);     // Saída: "0x7b"
	ft_printf("'%#0x'\n", 123);     // Saída: "0x7b"
	   printf("'%#0X'\n", 123);     // Saída: "0X7B"
	ft_printf("'%#0X'\n", 123);     // Saída: "0X7B"
	   printf("'%#10.1x'\n", 123);  // Saída: "     0x7b"
	ft_printf("'%#10.1x'\n", 123);  // Saída: "     0x7b"
	   printf("'%#10.1X'\n", 123);  // Saída: "     0X7B"
	ft_printf("'%#10.1X'\n", 123);  // Saída: "     0X7B"
	   printf("'%-#10.4x'\n", 123); // Saída: "0x007b    "
	ft_printf("'%-#10.4x'\n", 123); // Saída: "0x007b    "
	   printf("'%-#10.4X'\n", 123); // Saída: "0X007B    "
	ft_printf("'%-#10.4X'\n", 123); // Saída: "0X007B    "
	   printf("'%#8.10x'\n", 123);  // Saída: "0x000000007b"
	ft_printf("'%#8.10x'\n", 123);  // Saída: "0x000000007b"
	   printf("'%#8.10X'\n", 123);  // Saída: "0X000000007B"
	ft_printf("'%#8.10X'\n", 123);  // Saída: "0X000000007B"
	   printf("'%5x'\n", 123);      // Saída: "   7b"
	ft_printf("'%5x'\n", 123);      // Saída: "   7b"
	   printf("'%5X'\n", 123);      // Saída: "   7B"
	ft_printf("'%5X'\n", 123);      // Saída: "   7B"


	// printf("(%i %i)\n", i1, i2);

    return 0;
}
