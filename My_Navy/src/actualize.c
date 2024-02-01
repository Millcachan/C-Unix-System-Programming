/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-navy-titouan.pradoura
** File description:
** actualize.c
*/

#include "../include/my.h"
#include "../include/navy.h"

int actualize(int x, int y, char **map)
{
    if (map[y][x] == 'x' || map[y][x] == 'o')
        return MISS;
    if (map[y][x] == '.') {
        map[y][x] = 'o';
        return MISS;
    }
    if (map[y][x] >= '2' && map[y][x] <= '5') {
        map[y][x] = 'x';
        return HIT;
    }
    return WRONG;
}

void actualize_ennemi(int x, int y, char **map, int state)
{
    if (state == 1)
        map[y][x] = 'o';
    if (state == 2)
        map[y][x] = 'x';
}

void display_attack(int x, int y, int state)
{
    char *pos[8] = {"A", "B", "C", "D", "E", "F", "G", "H"};

    my_putstr("\nresult:\n", 1);
    my_putstr(pos[x], 1);
    my_putnbr(y, 1);
    if (state == MISS)
        my_putstr(": missed\n", 1);
    if (state == HIT)
        my_putstr(": hit\n", 1);
}

void actualize_attack(char *pos, char **map_e, int sig)
{
    display_attack(pos[0] - 65, pos[1] - 48, sig);
    actualize_ennemi(pos[0] - 65, pos[1] - 49, map_e, sig);
}
