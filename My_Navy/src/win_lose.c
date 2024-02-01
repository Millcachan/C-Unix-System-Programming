/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-navy-titouan.pradoura
** File description:
** win_lose.c
*/

#include "../include/my.h"
#include "../include/navy.h"

static int check_line(char *line)
{
    for (int x = 0; line[x]; x++)
        if (line[x] >= '2' && line[x] <= '5')
            return 0;
    return 1;
}

int lose(navy_t *navy)
{
    for (int y = 0; navy->map.map_p[y]; y++)
        if (check_line(navy->map.map_p[y]) == 0)
            return 0;
    display(&navy->map);
    my_putstr("\nEnemy won\n", 1);
    return 1;
}

int win(navy_t *navy)
{
    int count = 0;

    for (int y = 0; navy->map.map_e[y]; y++)
        for (int x = 0; navy->map.map_e[y][x]; x++)
            count += (navy->map.map_e[y][x] == 'x');
    if (count == 14) {
        display(&navy->map);
        my_putstr("\nI won\n", 1);
        return 1;
    }
    return 0;
}
