/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-titouan.pradoura
** File description:
** usage
*/

#include "../include/my.h"
#include "../include/navy.h"

int help(void)
{
    my_putstr("USAGE\n", 1);
    my_putstr("     ./my_navy [first_player_pid] navy_positions\n", 1);
    my_putstr("DESCRIPTION\n", 1);
    my_putstr("     first_player_pid: only for the 2nd player. ", 1);
    my_putstr("pid of the first player.\n", 1);
    my_putstr("     navy_positions: file representing ", 1);
    my_putstr("the positions of the ships.\n", 1);
    return 0;
}
