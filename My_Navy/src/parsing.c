/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-titouan.pradoura
** File description:
** parsing
*/

#include "../include/my.h"
#include "../include/navy.h"

static int is_valid_pos(char *line)
{
    if (line[0] < '2' || line[0] > '5')
        return ERROR;
    if (line[1] != ':')
        return ERROR;
    if (line[2] < 'A' || line[2] > 'H')
        return ERROR;
    if (line[3] < '1' || line[3] > '8')
        return ERROR;
    if (line[4] != ':')
        return ERROR;
    if (line[5] < 'A' || line[5] > 'H')
        return ERROR;
    if (line[6] < '1' || line[7] > '8')
        return ERROR;
    return SUCCESS;
}

static int check_value(char comp, char *line, int *enc)
{
    if (line[0] == comp) {
            if (*enc)
                return ERROR;
            *enc = 1;
        }
    if (line[5] - line[2] != line[0] - 49 && line[6] - line[3] != line[0] - 49)
        return ERROR;
    return SUCCESS;
}

static int is_valid_boat(char *line, int nb)
{
    static int enc_2 = 0;
    static int enc_3 = 0;
    static int enc_4 = 0;
    static int enc_5 = 0;

    if (nb)
        return enc_2 && enc_3 && enc_4 && enc_5;
    if (check_value('2', line, &enc_2) != 0)
        return ERROR;
    if (check_value('3', line, &enc_3) != 0)
        return ERROR;
    if (check_value('4', line, &enc_4) != 0)
        return ERROR;
    if (check_value('5', line, &enc_5) != 0)
        return ERROR;
    return SUCCESS;
}

static int is_valid_line(char *line)
{
    int len = my_strlen(line);

    if (len != 7 && len != 8)
        return ERROR;
    if (is_valid_boat(line, 0))
        return ERROR;
    if (is_valid_pos(line) == ERROR)
        return ERROR;
    return SUCCESS;
}

static int new_boat(map_t *map, char *line)
{
    if (is_valid_line(line) == ERROR)
        return ERROR;
    if (line[2] != line[5] && line[3] != line[6])
        return ERROR;
    for (int x = line[2] - 65; x <= line[5] - 65; x++)
        for (int y = line[3] - 49; y <= line[6] - 49; y++)
            map->map_p[y][x] = line[0];
    free(line);
    return SUCCESS;
}

int init_map(map_t *map, char *filepath)
{
    FILE *file = fopen(filepath, "r");
    char *buffer = NULL;
    size_t n;
    int i = 0;

    if (!file)
        return ERROR;
    for (i = 0; getline(&buffer, &n, file) != -1; i++)
        if (new_boat(map, my_strdup(buffer)) == ERROR)
            return ERROR;
    if (!is_valid_boat("", 1))
        return ERROR;
    free(buffer);
    fclose(file);
    return SUCCESS;
}
