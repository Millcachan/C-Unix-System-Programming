/*
** EPITECH PROJECT, 2023
** my_str_isprintable.c
** File description:
** strisprintable
*/

#include "../../include/my.h"

int my_isprintable(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 32 || str[i] > 126)
            return false;
    return true;
}
