/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-titouan.pradoura
** File description:
** player
*/

#include "../include/my.h"
#include "../include/navy.h"

int player_one(navy_t *navy)
{
    navy->player.turn = true;
    navy->player.pid_p = getpid();
    my_putstr("my_pid: ", 1);
    my_putnbr(navy->player.pid_p, 1);
    my_putstr("\n\nwaiting for enemy connection...\n", 1);
    navy->player.pid_e = connect();
    display(&navy->map);
    return game(navy);
}

int player_two(navy_t *navy, int player_one_pid)
{
    navy->player.turn = false;
    navy->player.pid_p = getpid();
    navy->player.pid_e = player_one_pid;
    if (kill(navy->player.pid_e, SIGUSR1) == -1)
        return (ERROR);
    my_putstr("my_pid: ", 1);
    my_putnbr(navy->player.pid_p, 1);
    my_putstr("\n\nsuccessfully connected\n", 1);
    display(&navy->map);
    return game(navy);
}
