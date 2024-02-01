/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-titouan.pradoura
** File description:
** connect
*/

#include "../include/my.h"
#include "../include/navy.h"
#include "../include/signal.h"

void signal_handling(int sig, siginfo_t *siginfo, void *context)
{
    (void)context;
    connection.pid_e = siginfo->si_pid;
    if (sig == SIGUSR1 || sig == SIGUSR2)
        connection.signal_recieved = 1;
}

int connect(void)
{
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = signal_handling;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGUSR1, &sa, NULL))
        my_putstr("Error: cannot handle SIGUSR1\n", 2);
    if (sigaction(SIGUSR2, &sa, NULL))
        my_putstr("Error: cannot handle SIGUSR2\n", 2);
    while (connection.signal_recieved == 0)
        usleep(100);
    my_putstr("\nenemy connected\n", 1);
    return connection.pid_e;
}
