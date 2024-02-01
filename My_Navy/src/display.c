/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-titouan.pradoura
** File description:
** display_map
*/

#include "../include/my.h"
#include "../include/navy.h"

static void display_map(char **map)
{
    my_putstr(" |A B C D E F G H\n-+---------------\n", 1);
    for (int i = 0; i < 8; i++) {
        my_putnbr(i + 1, 1);
        my_putchar('|', 1);
        for (int j = 0; j < 7; j++) {
            my_putchar(map[i][j], 1);
            my_putchar(' ', 1);
        }
        my_putchar(map[i][7], 1);
        my_putchar('\n', 1);
    }
}

void display(map_t *map)
{
    my_putstr("\nmy navy:\n", 1);
    display_map(map->map_p);
    my_putstr("\nenemy navy:\n", 1);
    display_map(map->map_e);
}
