/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-sokoban-camille.billard
** File description:
** movements
*/

#include "../include/my.h"

static int get_pos_player(sokoban_t *game)
{
    for (int i = 0; game->map.map[i] != NULL; i++) {
        for (int j = 0; game->map.map[i][j] != '\0'; j++) {
            game->player.x = (game->map.map[i][j] == 'P') ? j : game->player.x;
            game->player.y = (game->map.map[i][j] == 'P') ? i : game->player.y;
        }
    }
    return 84;
}

static void move_r(sokoban_t *game)
{
    char c = ' ';

    if (game->player.x == my_strlen(game->map.map[game->player.y]) - 2)
        return;
    if (game->map.map[game->player.y][game->player.x + 1] == 'X')
        if (!push_boxe_r(game))
            return;
    for (int i = 0; i < game->map.nb_slots; i++) {
        if (game->player.x == game->map.boxes_x[i]
        && game->player.y == game->map.boxes_y[i])
        c = 'O';
    }
    if (game->map.map[game->player.y][game->player.x + 1] == '#')
        return;
    game->map.map[game->player.y][game->player.x] = c;
    game->map.map[game->player.y][game->player.x + 1] = 'P';
}

static void move_l(sokoban_t *game)
{
    char c = ' ';

    if (game->player.x == 0)
        return;
    if (game->map.map[game->player.y][game->player.x - 1] == 'X')
        if (!push_boxe_l(game))
            return;
    for (int i = 0; i < game->map.nb_slots; i++) {
        if (game->player.x == game->map.boxes_x[i]
        && game->player.y == game->map.boxes_y[i])
        c = 'O';
    }
    if (game->map.map[game->player.y][game->player.x - 1] == '#')
        return;
    game->map.map[game->player.y][game->player.x] = c;
    game->map.map[game->player.y][game->player.x - 1] = 'P';
}

static void move_u(sokoban_t *game)
{
    char c = ' ';

    if (game->player.y == 0)
        return;
    if (game->map.map[game->player.y - 1][game->player.x] == 'X')
        if (!push_boxe_u(game))
            return;
    for (int i = 0; i < game->map.nb_slots; i++) {
        if (game->player.x == game->map.boxes_x[i]
        && game->player.y == game->map.boxes_y[i])
        c = 'O';
    }
    if (game->map.map[game->player.y - 1][game->player.x] == '#')
        return;
    game->map.map[game->player.y][game->player.x] = c;
    game->map.map[game->player.y - 1][game->player.x] = 'P';
}

static void move_d(sokoban_t *game)
{
    char c = ' ';

    if (game->player.y == game->map.height)
        return;
    if (game->map.map[game->player.y + 1][game->player.x] == 'X')
        if (!push_boxe_d(game))
            return;
    for (int i = 0; i < game->map.nb_slots; i++) {
        if (game->player.x == game->map.boxes_x[i]
        && game->player.y == game->map.boxes_y[i])
        c = 'O';
    }
    if (game->map.map[game->player.y + 1][game->player.x] == '#')
        return;
    game->map.map[game->player.y][game->player.x] = c;
    game->map.map[game->player.y + 1][game->player.x] = 'P';
}

void movements(sokoban_t *game)
{
    game->key = getch();
    get_pos_player(game);
    switch (game->key) {
        case KEY_RIGHT:
            move_r(game);
            break;
        case KEY_LEFT:
            move_l(game);
            break;
        case KEY_UP:
            move_u(game);
            break;
        case KEY_DOWN:
            move_d(game);
    }
    return;
}
