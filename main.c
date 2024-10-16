#include "ft_printf_bonus.h"
#include <stdio.h>

int main(void)
{
    int num = 42;
    char *str = "Hello, world!";
    
    ft_printf("Número: %d\n", num);
    ft_printf("String: %s\n", str);
    ft_printf("Caractere: %c\n", 'A');
    ft_printf("Hexadecimal: %x\n\n", num);

    return 0;
}