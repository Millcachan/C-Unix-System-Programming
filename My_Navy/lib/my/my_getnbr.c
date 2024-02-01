/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** getnbr
*/

#include "../../include/my.h"

long long my_getnbr(char *str)
{
    long long nbr = 0;
    int i = 0;
    int signe = 1;

    while ((str[i] == '-' || str[i] == '+') && str[i] != '\0')
        if (str[i] == '-') {
            signe = -signe;
            i++;
        }
    while (str[i] >= '0' && str[i] <= '9') {
        nbr = nbr * 10 + (str[i] - 48);
        i++;
    }
    return (nbr * signe);
}
