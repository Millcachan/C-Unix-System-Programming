/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-sokoban-camille.billard
** File description:
** map
*/

#include "../include/my.h"

static int is_wrong_char(char c)
{
    switch (c) {
    case '#':
        return 0;
    case ' ':
        return 0;
    case 'O':
        return 0;
    case 'X':
        return 0;
    case 'P':
        return 0;
    case '\n':
        return 0;
    }
    return 1;
}

static void stock_o(sokoban_t *game)
{
    int count = 0;

    game->map.boxes_x = malloc(sizeof(int *) * game->map.nb_slots);
    game->map.boxes_y = malloc(sizeof(int *) * game->map.nb_slots);
    for (int i = 0; game->map.map[i] != NULL; i++) {
        for (int j = 0; game->map.map[i][j] != '\0'; j++) {
            game->map.boxes_x[count] = (game->map.map[i][j] == 'O') ? j : 0;
            game->map.boxes_y[count] = (game->map.map[i][j] == 'O') ? i : 0;
            count += (game->map.map[i][j] == 'O');
            game->map.width = (j > game->map.width) ? j : game->map.width;
        }
        game->map.height = i;
    }
}

static int test_map(sokoban_t *game)
{
    int player = 0;
    int slots = 0;
    int boxes = 0;
    int wrong_char = 0;

    for (int i = 0; game->map.map[i] != NULL; i++) {
        for (int j = 0; game->map.map[i][j] != '\0'; j++) {
            player += (game->map.map[i][j] == 'P');
            slots += (game->map.map[i][j] == 'O');
            boxes += (game->map.map[i][j] == 'X');
            wrong_char += is_wrong_char(game->map.map[i][j]);
        }
    }
    if ((slots != boxes) || player != 1 || wrong_char != 0)
        exit(84);
    game->map.nb_boxes = boxes;
    game->map.nb_slots = slots;
    stock_o(game);
    return 0;
}

static int nb_lines(char *filepath)
{
    int	fd;
    int	size = 1;
    char buffer[1];
    int	count = 0;

    fd = open(filepath, O_RDONLY);
    while (size != 0){
        size = read(fd, buffer, 1);
        if (buffer[0] == '\n')
            count++;
    }
    close(fd);
    return (count + 2);
}

static char **init_map(char *filepath, char **map)
{
    FILE *file = fopen(filepath, "r");
    char *buffer = NULL;
    size_t n;
    int i = 0;

    for (i = 0; getline(&buffer, &n, file) != -1; i++)
        map[i] = my_strdup(buffer);
    map[i] = NULL;
    free(buffer);
    fclose(file);
    return map;
}

void init_sokoban(char *filepath, sokoban_t *game)
{
    char **map = malloc(sizeof(char *) * nb_lines(filepath));

    game->state = -1;
    game->filepath = filepath;
    game->key = 0;
    game->map.map = init_map(filepath, map);
    game->resize = "Please resize !";
    test_map(game);
}
