/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-titouan.pradoura
** File description:
** signal
*/

#ifndef SIGNAL_H_
    #define SIGNAL_H_

typedef struct connection_s {
    int signal_recieved;
    int signal_end;
    int pid_e;
    int x;
    int y;
} connection_t;

static connection_t connection;

#endif
