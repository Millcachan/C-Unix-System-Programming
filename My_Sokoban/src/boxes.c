/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** boxes
*/

#include "../include/my.h"

int push_boxe_r(sokoban_t *game)
{
    if (game->player.x == my_strlen(game->map.map[game->player.y]) - 3)
        return 0;
    if (game->map.map[game->player.y][game->player.x + 2] == 'X'
    || game->map.map[game->player.y][game->player.x + 2] == '#')
        return 0;
    game->map.map[game->player.y][game->player.x + 2] = 'X';
    return 1;
}

int push_boxe_l(sokoban_t *game)
{
    if (game->player.x - 1 == 0)
        return 0;
    if (game->map.map[game->player.y][game->player.x - 2] == 'X'
    || game->map.map[game->player.y][game->player.x - 2] == '#')
        return 0;
    game->map.map[game->player.y][game->player.x - 2] = 'X';
    return 1;
}

int push_boxe_u(sokoban_t *game)
{
    if (game->player.y - 1 == 0)
        return 0;
    if (game->map.map[game->player.y - 2][game->player.x] == 'X'
    || game->map.map[game->player.y - 2][game->player.x] == '#')
        return 0;
    game->map.map[game->player.y - 2][game->player.x] = 'X';
    return 1;
}

int push_boxe_d(sokoban_t *game)
{
    if (game->player.y - 1 == game->map.height - 2)
        return 0;
    if (game->map.map[game->player.y + 2][game->player.x] == 'X'
    || game->map.map[game->player.y + 2][game->player.x] == '#')
        return 0;
    game->map.map[game->player.y + 2][game->player.x] = 'X';
    return 1;
}
