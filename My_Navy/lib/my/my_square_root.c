/*
** EPITECH PROJECT, 2023
** my_compute_square_root.c
** File description:
** computesquareroot
*/

#include "../../include/my.h"

int my_square_root(int nb)
{
    static int i = 0;

    if ((i * i) < nb) {
        i++;
        my_square_root(nb);
    } else if ((i * i) == nb)
        return i;
    return 0;
}
