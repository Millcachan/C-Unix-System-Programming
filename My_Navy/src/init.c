/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-titouan.pradoura
** File description:
** init
*/

#include "../include/my.h"
#include "../include/navy.h"

static int init_maps(map_t *map, char *filepath)
{
    map->map_p = malloc((size_t)(sizeof(char *) * 9));
    map->map_e = malloc((size_t)(sizeof(char *) * 9));
    for (int i = 0; i < 8; i++) {
        map->map_p[i] = my_strdup("........");
        map->map_e[i] = my_strdup("........");
    }
    map->map_p[8] = NULL;
    map->map_e[8] = NULL;
    return init_map(map, filepath);
}

static void init_player(player_t *player)
{
    player->pid_p = 0;
    player->pid_e = 0;
    player->check = 0;
}

int init(navy_t *navy, char *filepath)
{
    init_player(&navy->player);
    return init_maps(&navy->map, filepath);
}
