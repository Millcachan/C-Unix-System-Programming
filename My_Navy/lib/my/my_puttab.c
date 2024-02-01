/*
** EPITECH PROJECT, 2023
** my_show_word_array.c
** File description:
** showwordarray
*/

#include "../../include/my.h"

void my_puttab(char **tab, int fd)
{
    for (int i = 0; tab[i] != 0; i++) {
        my_putstr(tab[i], fd);
        my_putchar('\n', fd);
    }
}
