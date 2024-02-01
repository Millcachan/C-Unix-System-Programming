/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-titouan.pradoura
** File description:
** my
*/

#include <signal.h>

#ifndef MY_H_
    #define MY_H_

    #define WRONG 0
    #define MISS 1
    #define HIT 2

typedef struct map_s {
    char **map_p;
    char **map_e;
} map_t;

typedef struct player_s {
    int defeat;
    int pid_p;
    int pid_e;
    int check;
    int turn;
} player_t;

typedef struct navy_s {
    player_t player;
    map_t map;
} navy_t;

int help(void);
int connect(void);
char *get_pos(void);
int win(navy_t *navy);
int lose(navy_t *navy);
int game(navy_t *navy);
void display(map_t *map);
void free_navy(navy_t *navy);
int player_one(navy_t *navy);
void send_attack(navy_t *navy);
int navy(int argc, char **argv);
void recieve_attack(navy_t *navy);
int init(navy_t *navy, char *filepath);
int actualize(int x, int y, char **map);
int init_map(map_t *map, char *filepath);
void display_attack(int x, int y, int state);
int player_two(navy_t *navy, int player_one_pid);
void actualize_attack(char *pos, char **map_e, int sig);

#endif
