/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-titouan.pradoura
** File description:
** game
*/

#include "../include/my.h"
#include "../include/navy.h"

char *get_pos(void)
{
    long unsigned size = 3;
    char *buffer = malloc((size_t)sizeof(char) * size + 1);

    my_putstr("\nattack: ", 1);
    if (getline(&buffer, &size, stdin) == -1)
        return (NULL);
    if (my_strlen(buffer) != 3 || buffer[0] < 'A' || buffer[0] > 'H' ||
        buffer[1] < '1' || buffer[1] > '8') {
        free(buffer);
        my_putstr("\nwrong position\n", 1);
        get_pos();
    }
    return (buffer);
}

int game(navy_t *navy)
{
    if (lose(navy))
        return 1;
    if (win(navy))
        return 0;
    if (navy->player.turn == true)
        send_attack(navy);
    else {
        my_putstr("\nwaiting for enemy's attack...\n", 1);
        recieve_attack(navy);
    }
    display(&navy->map);
    navy->player.turn = !(navy->player.turn && true);
    return game(navy);
}
