/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** strlen
*/

#include "../../include/my.h"

int my_strlen(char *str)
{
    int i = 0;

    if (!str)
        return 0;
    while (str[i] != '\0')
        i++;
    return i;
}
