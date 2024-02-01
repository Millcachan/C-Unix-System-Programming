/*
** EPITECH PROJECT, 2023
** my_str_isnum.c
** File description:
** strisnum
*/

#include "../../include/my.h"

int my_isnum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return false;
    return true;
}
