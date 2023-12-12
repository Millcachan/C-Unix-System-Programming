/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** sokoban
*/

#include "../include/my.h"

void free_sokoban(sokoban_t *game)
{
    free(game->map.boxes_x);
    free(game->map.boxes_y);
    for (int i = 0; game->map.map[i] != NULL; i++)
        free(game->map.map[i]);
    free(game->map.map);
}

static void print_sokoban(sokoban_t *game)
{
    clear();
    for (int i = 0; i < game->map.height + 1; i++)
        mvprintw(i, 0, game->map.map[i]);
    refresh();
}

void sokoban(sokoban_t *game)
{
    print_sokoban(game);
    movements(game);
    state_game(game);
}

static void init(void)
{
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    ESCDELAY = 5;
}

static void end(sokoban_t *game)
{
    if (game->state == 0 || game->state == 1) {
        print_sokoban(game);
        usleep(50000);
    }
    endwin();
    free_sokoban(game);
}

void ncurses(sokoban_t *game)
{
    init();
    while (game->key != ESCAPE) {
        if (is_wrong_size(game)) {
            resize_terminal(game, game->resize);
            continue;
        }
        sokoban(game);
    }
    end(game);
}
