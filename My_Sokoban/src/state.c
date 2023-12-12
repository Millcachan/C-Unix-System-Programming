/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-sokoban-camille.billard
** File description:
** state
*/

#include "../include/my.h"

static int is_blocked_right(map_t *map, int x, int y)
{
    if (x == my_strlen(map->map[y]) - 2)
        return 1;
    if (map->map[y][x + 1] == '#' || map->map[y][x + 1] == 'X')
        return 1;
    return 0;
}

static int is_blocked_left(map_t *map, int x, int y)
{
    if (x == 0)
        return 1;
    if (map->map[y][x - 1] == '#' || map->map[y][x - 1] == 'X')
        return 1;
    return 0;
}

static int is_blocked_down(map_t *map, int x, int y)
{
    if (y == map->height)
        return 1;
    if (map->map[y + 1][x] == '#' || map->map[y + 1][x] == 'X')
        return 1;
    return 0;
}

static int is_blocked_up(map_t *map, int x, int y)
{
    if (y == 0)
        return 1;
    if (map->map[y - 1][x] == '#' || map->map[y - 1][x] == 'X')
        return 1;
    return 0;
}

static int is_blocked(map_t *map, int y, int x)
{
    if (map->map[y][x] != 'X')
        return 0;
    if (is_blocked_up(map, x, y)) {
        if (is_blocked_right(map, x, y))
            return 1;
        if (is_blocked_left(map, x, y))
            return 1;
    }
    if (is_blocked_down(map, x, y)) {
        if (is_blocked_right(map, x, y))
            return 1;
        if (is_blocked_left(map, x, y))
            return 1;
    }
    return 0;
}

static int check_lose(sokoban_t *game)
{
    int nb_box_blocked = 0;

    for (int i = 0; game->map.map[i] != NULL; i++)
        for (int j = 0; game->map.map[i][j] != '\0'; j++)
            nb_box_blocked += is_blocked(&game->map, i, j);
    if (nb_box_blocked == game->map.nb_boxes)
        game->state = 1;
    return (nb_box_blocked == game->map.nb_boxes);
}

static int check_win(sokoban_t *game)
{
    for (int i = 0; i < game->map.nb_slots; i++)
        if (game->map.map[game->map.boxes_y[i]][game->map.boxes_x[i]] != 'X')
            return 0;
    game->state = 0;
    return 1;
}

static void restart_game(sokoban_t *game)
{
    if (game->key == SPACE) {
        free_sokoban(game);
        init_sokoban(game->filepath, game);
    }
}

void state_game(sokoban_t *game)
{
    restart_game(game);
    game->key = check_win(game) ? ESCAPE : game->key;
    game->key = check_lose(game) ? ESCAPE : game->key;
}
