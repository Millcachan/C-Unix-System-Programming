/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-titouan.pradoura
** File description:
** navy
*/

#include "../include/my.h"
#include "../include/navy.h"

int navy(int argc, char **argv)
{
    int return_value = ERROR;
    navy_t navy;

    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        return help();
    if (argc == 2)
        if (init(&navy, argv[1]) == SUCCESS)
            return_value = player_one(&navy);
    if (argc == 3)
        if (init(&navy, argv[2]) == SUCCESS)
            return_value = player_two(&navy, (int)my_getnbr(argv[1]));
    return return_value;
}
