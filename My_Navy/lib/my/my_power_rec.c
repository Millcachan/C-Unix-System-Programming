/*
** EPITECH PROJECT, 2023
** my_compute_power_rec.c
** File description:
** computepower
*/

#include "../../include/my.h"

long long my_power_rec(long long nb, int p)
{
    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    if (p != 1)
        nb *= my_power_rec(nb, p - 1);
    return nb;
}
