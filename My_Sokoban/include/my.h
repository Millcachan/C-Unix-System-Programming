/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my
*/

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef MY_H
    #define MY_H

    #define SPACE 32
    #define ESCAPE 27

typedef struct player_s {
    int x;
    int y;
} player_t;

typedef struct map_s {
    int nb_slots;
    int nb_boxes;
    char **map;
    int height;
    int width;
    int *boxes_x;
    int *boxes_y;
} map_t;

typedef struct sokoban_s {
    player_t player;
    char *filepath;
    char *resize;
    int state;
    map_t map;
    int key;
} sokoban_t;

int my_strlen(char *str);
int my_putstr(char *str);
char *my_strdup(char *src);
void ncurses(sokoban_t *game);
void movements(sokoban_t *game);
void state_game(sokoban_t *game);
int push_boxe_r(sokoban_t *game);
int push_boxe_l(sokoban_t *game);
int push_boxe_u(sokoban_t *game);
int push_boxe_d(sokoban_t *game);
int my_strcmp(char *s1, char *s2);
void free_sokoban(sokoban_t *game);
int is_wrong_size(sokoban_t *game);
char *my_strcat(char *dest, char *src);
void init_sokoban(char *filepath, sokoban_t *game);
void resize_terminal(sokoban_t *game, char *resize);

#endif
