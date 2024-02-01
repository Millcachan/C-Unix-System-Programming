/*
** EPITECH PROJECT, 2023
** my_is_prime_sup.c
** File description:
** isprimesup
*/

#include "../../include/my.h"

int my_prime_sup(int nb)
{
    int test = nb;

    while (my_is_prime(test) != 1)
        test++;
    return test;
}
