/*
** EPITECH PROJECT, 2023
** my_str_isupper.c
** File description:
** strisupper
*/

#include "../../include/my.h"

int my_isupper(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 'A' || str[i] > 'Z')
            return false;
    return true;
}
