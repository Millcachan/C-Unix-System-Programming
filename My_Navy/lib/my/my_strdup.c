/*
** EPITECH PROJECT, 2023
** my_strdup.c
** File description:
** allocate memory to an str
*/

#include "../../include/my.h"

char *my_strdup(char const *src)
{
    char *dest;
    size_t len = 0;

    while (src[len] != '\0') {
        len++;
    }
    dest = malloc(sizeof(char) * (len + 1));
    for (size_t i = 0; i <= len; i++) {
        dest[i] = src[i];
    }
    return dest;
}
