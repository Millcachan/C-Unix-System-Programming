/*
** EPITECH PROJECT, 2023
** my_str_isalpha.c
** File description:
** : strisalpha
*/

#include "../../include/my.h"

int my_isalpha(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return false;
    return true;
}
