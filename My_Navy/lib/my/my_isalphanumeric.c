/*
** EPITECH PROJECT, 2024
** lib_my
** File description:
** my_isalphanumeric
*/

#include "../../include/my.h"


int my_isalphanumeric(char c)
{
    if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return false;
    return true;
}
