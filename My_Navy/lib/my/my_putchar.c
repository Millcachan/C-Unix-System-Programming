/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** putchar
*/

#include "../../include/my.h"

int my_putchar(char c, int fd)
{
    return (int)write(fd, &c, 1);
}
