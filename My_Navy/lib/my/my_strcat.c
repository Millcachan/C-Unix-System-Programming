/*
** EPITECH PROJECT, 2023
** my_strcat.c
** File description:
** strcat
*/

#include "../../include/my.h"

char *my_strcat(char *dest, char *src)
{
    int len = my_strlen(dest) + my_strlen(src);
    int len_dest = my_strlen(dest);

    for (int i = 0; i != len; i++)
    dest[i + len_dest] = src[i];
    return dest;
}
