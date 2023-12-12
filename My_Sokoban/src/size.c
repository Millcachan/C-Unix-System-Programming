/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** size
*/

#include "../include/my.h"

void resize_terminal(sokoban_t *game, char *resize)
{
    clear();
    mvprintw((LINES / 2), (COLS / 2 - my_strlen(resize) / 2), resize);
    refresh();
    game->key = getch();
}

int is_wrong_size(sokoban_t *game)
{
    if (COLS < game->map.width)
        return 1;
    if (LINES < game->map.height + 1)
        return 1;
    return 0;
}
