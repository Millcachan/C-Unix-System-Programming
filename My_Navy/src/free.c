/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-titouan.pradoura
** File description:
** free
*/

#include "../include/my.h"
#include "../include/navy.h"

void free_navy(navy_t *navy)
{
    for (int i = 0; navy->map.map_p[i]; i++) {
        free(navy->map.map_p[i]);
        free(navy->map.map_e[i]);
    }
    free(navy->map.map_p);
    free(navy->map.map_e);
}
