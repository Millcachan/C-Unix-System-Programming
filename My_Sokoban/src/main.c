/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-bssokoban-camille.billard
** File description:
** main
*/

#include "../include/my.h"

void help(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map file representing the warehouse map,");
    my_putstr("containing ‘#’ for walls\n");
    my_putstr("     ‘P’ for the player,");
    my_putstr("‘X’ for boxes and ‘O’for storage locations.\n");
}

void error(int argc, char **argv)
{
    struct stat stats_map;

    if (argc != 2)
        exit(84);
    if (my_strcmp(argv[1], "-h") == 0)
        help();
    if (stat(argv[1], &stats_map) == -1)
        exit(84);
    if (stats_map.st_size == 0)
        exit(84);
}

int main(int argc, char **argv)
{
    sokoban_t game;

    error(argc, argv);
    init_sokoban(argv[1], &game);
    ncurses(&game);
    return game.state;
}
