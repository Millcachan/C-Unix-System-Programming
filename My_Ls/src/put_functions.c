/*
** EPITECH PROJECT, 2023
** 1.3
** File description:
** put_fonctions
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char *str)
{
    int i = 0;

    if (!str)
        return 0;
    while (str[i] != '\0')
        i++;
    return i;
}

int my_putstr(char *str)
{
    return write(1, str, my_strlen(str));
}

int my_puterrorstr(char *str)
{
    return write(2, str, my_strlen(str));
}

void my_putnbr(long long nbr)
{
    if (nbr < 0) {
        my_putchar('-');
        nbr = -nbr;
    }
    if (nbr >= 10)
        my_putnbr(nbr / 10);
    my_putchar('0' + nbr % 10);
}
