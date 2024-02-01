/*
** EPITECH PROJECT, 2023
** my_strncpy.c
** File description:
** strncpy
*/

#include "../../include/my.h"

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    for (i = 0; src[i] != '\0' && n > i; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
