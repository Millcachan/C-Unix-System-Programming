/*
** EPITECH PROJECT, 2023
** my_strncat.c
** File description:
** strncat
*/

#include "../../include/my.h"

char *my_strncat(char *dest, char *src, int nb)
{
    int len;
    int i;

    len = my_strlen(dest);
    for (i = 0; i < nb && src[i]; i++)
        dest[len + i] = src[i];
    dest[len + i] = '\0';
    return dest;
}
