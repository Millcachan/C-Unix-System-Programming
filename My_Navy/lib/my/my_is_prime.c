/*
** EPITECH PROJECT, 2023
** my_is_prime.c
** File description:
** isprime
*/

#include "../../include/my.h"

int my_is_prime(int nb)
{
    if (nb <= 1)
        return false;
    for (int i = 2; (i * i) <= nb; i++)
        if ((nb % i) == 0)
            return 0;
    return true;
}
