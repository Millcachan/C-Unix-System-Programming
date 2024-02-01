/*
** EPITECH PROJECT, 2024
** lib_my
** File description:
** my_strcmp
*/

#include "../../include/my.h"

int my_strcmp(char *s1, char *s2)
{
    for (int i = 0; true; i++) {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return -1;
        if (s1[i] == '\0' && s2[i] == '\0')
            return 0;
    }
}
