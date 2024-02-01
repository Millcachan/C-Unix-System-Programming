/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** putstr
*/

#include "../../include/my.h"

int my_putstr(char *str, int fd)
{
    return (int)write(fd, str, (size_t)my_strlen(str));
}
