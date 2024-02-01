/*
** EPITECH PROJECT, 2023
** my_strncmp.c
** File description:
** strncmp
*/

#include "../../include/my.h"

int my_strncmp(char *s1, char *s2, int n)
{
    if (n <= 0)
        return 0;
    for (int i = 0; n > 0; i++) {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return -1;
        if (s1[i] == '\0' && s2[i] == '\0')
            return 0;
        n--;
    }
    return 0;
}
