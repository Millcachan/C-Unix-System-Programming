/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-titouan.pradoura
** File description:
** attack
*/

#include "../include/my.h"
#include "../include/navy.h"
#include "../include/signal.h"

void reset(void)
{
    connection.signal_recieved = 0;
    connection.signal_end = 0;
    connection.pid_e = 0;
    connection.x = 0;
    connection.y = 0;
}

void attack_signal_handling(int sig, siginfo_t *siginfo, void *context)
{
    (void)context;
    connection.pid_e = siginfo->si_pid;
    if (sig == SIGUSR2)
        connection.signal_end += 1;
    if (sig == SIGUSR1 && connection.signal_end == 0)
        connection.x += 1;
    if (sig == SIGUSR1 && connection.signal_end == 1)
        connection.y += 1;
}

void response_signal_handling(int sig, siginfo_t *siginfo, void *context)
{
    (void)context;
    connection.pid_e = siginfo->si_pid;
    if (sig == SIGUSR1)
        connection.signal_recieved += 1;
    if (sig == SIGUSR2)
        connection.signal_end = 1;
}

static void recieve_response(void)
{
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = response_signal_handling;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGUSR1, &sa, NULL))
        my_putstr("Error: cannot handle SIGUSR1\n", 2);
    if (sigaction(SIGUSR2, &sa, NULL))
        my_putstr("Error: cannot handle SIGUSR2\n", 2);
    while (connection.signal_end == 0)
        usleep(100);
}

void send_attack(navy_t *navy)
{
    char *pos = get_pos();

    reset();
    for (int i = 0; i < pos[0] - 65; i++) {
        kill(navy->player.pid_e, SIGUSR1);
        usleep(20);
    }
    kill(navy->player.pid_e, SIGUSR2);
    for (int i = 0; i < pos[1] - 48; i++) {
        kill(navy->player.pid_e, SIGUSR1);
        usleep(20);
    }
    kill(navy->player.pid_e, SIGUSR2);
    recieve_response();
    if (connection.signal_recieved == 0) {
        my_putstr("\n\nwrong position\n", 1);
        send_attack(navy);
        return;
    }
    actualize_attack(pos, navy->map.map_e, connection.signal_recieved);
}

static int send_response(navy_t *navy, int x, int y, char **map)
{
    int sig = actualize(x, y - 1, map);

    for (int i = 0; i < sig; i++) {
        kill(navy->player.pid_e, SIGUSR1);
        usleep(20);
    }
    kill(navy->player.pid_e, SIGUSR2);
    return sig;
}

void recieve_attack(navy_t *navy)
{
    struct sigaction sa;
    int state;

    reset();
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = attack_signal_handling;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGUSR1, &sa, NULL))
        my_putstr("Error: cannot handle SIGUSR1\n", 2);
    if (sigaction(SIGUSR2, &sa, NULL))
        my_putstr("Error: cannot handle SIGUSR2\n", 2);
    while (connection.signal_end < 2)
        usleep(100);
    state = send_response(navy, connection.x, connection.y, navy->map.map_p);
    if (!state) {
        recieve_attack(navy);
        return;
    }
    display_attack(connection.x, connection.y, state);
}
