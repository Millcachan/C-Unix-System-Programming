/*
** EPITECH PROJECT, 2023
** my_str_islower.c
** File description:
** strislower
*/

#include "../../include/my.h"

int my_islower(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 'a' || str[i] > 'z')
            return false;
    return true;
}
