/*
** EPITECH PROJECT, 2023
** my_put_number.c
** File description:
** putnumber
*/

#include "../../include/my.h"

int my_putnbr(long long nbr, int fd)
{
    int counter = 0;

    if (nbr < 0) {
        counter += my_putchar('-', fd);
        nbr = -nbr;
    }
    if (nbr >= 10)
        counter += my_putnbr(nbr / 10, fd);
    counter += my_putchar((char)('0' + nbr % 10), fd);
    return counter;
}
