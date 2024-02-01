/*
** EPITECH PROJECT, 2024
** lib_my
** File description:
** my_str_to_word_array
*/

#include "../../include/my.h"

int count_words(char *str)
{
    int new_word = 1;
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((my_isalphanumeric(str[i]) == 0))
            new_word = 1;
        if ((my_isalphanumeric(str[i]) == 1) && new_word == 1) {
            new_word = 0;
            count++;
        }
    }
    return (count);
}

int word_position(char *str, int pos)
{
    int i = 0;

    while (str[pos + i] != '\0' && my_isalphanumeric(str[pos + i]) == 1)
        i++;
    while (str[pos + i] != '\0' && my_isalphanumeric(str[pos + i]) == 0)
        i++;
    return i;
}

int len_word(char *str, int pos, int isalpha)
{
    int i = pos;

    while (my_isalphanumeric(str[i]) == isalpha)
        i++;
    return (i - pos);
}

char **my_str_to_word_array(char *str)
{
    int nb_words = count_words(str);
    char **tab = NULL;
    int nb_char = 0;
    int pos = len_word(str, 0, 0);

    tab = malloc((size_t)((int)sizeof(char *) * (nb_words + 1)));
    tab[nb_words] = NULL;
    for (int i = 0; i < nb_words; i++) {
        nb_char = len_word(str, pos, 1);
        tab[i] = malloc((size_t)((int)sizeof(char) * (nb_char + 1)));
        my_strncpy(tab[i], str + pos, nb_char);
        pos = pos + word_position(str, pos);
    }
    return tab;
}
