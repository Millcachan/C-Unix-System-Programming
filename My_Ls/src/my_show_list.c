/*
** EPITECH PROJECT, 2023
** tests
** File description:
** my_show_list
*/

#include "../include/my.h"

static char *my_strcat(char *dest, char *src)
{
    int len = my_strlen(dest) +  my_strlen(src);
    int len_dest = my_strlen(dest);

    for (int i = 0; i != len; i++)
        dest[i + len_dest] = src[i];
    return dest;
}

static char *strcatalloc(char *dest, char *src)
{
    int no_slash = dest[my_strlen(dest) - 1 ] != '/';
    char *new = malloc(sizeof(char) *
    (my_strlen(dest) + my_strlen(src) + 10 + no_slash));

    if (dest == NULL)
        dest = "./";
    for (int i = 0; i < my_strlen(dest) + my_strlen(src); i++)
        new[i] = '\0';
    my_strcat(new, dest);
    if (no_slash)
        my_strcat(new, "/");
    return my_strcat(new, src);
}

char *strcatalloctest(char *dest, char *src)
{
    if (dest == NULL)
        dest = "./";
    return strcatalloc(dest, src);
}

void my_show_simple(struct linked_list const *list, struct flags *flags)
{
    while (list != NULL) {
        if (list->data[0] != '.' && flags->l == true)
            flag_l(strcatalloctest(list->path, list->data));
        if (list->data[0] != '.' && flags->l == false)
            my_putstr(list->data);
        if (list->next != NULL && list->data[0] != '.' && flags->l == false)
            my_putstr("  ");
        if (list->next != NULL && list->data[0] != '.' && flags->l == true)
            my_putchar('\n');
        list = list->next;
    }
    if (flags->r == false)
        my_putchar('\n');
}

void my_show_d(struct linked_list const *list, struct flags *flags)
{
    while (list != NULL) {
        if (flags->l == true)
            flag_l_file(list->data);
        my_putstr(list->data);
        if (list->next != NULL && flags->l == false)
            my_putstr("  ");
        if (list->next != NULL && flags->l == true)
            my_putchar('\n');
        list = list->next;
    }
    my_putchar('\n');
}

void my_showlist(struct linked_list const *list, struct flags *flags)
{
    while (list != NULL) {
        if (flags->l == true)
            flag_l(strcatalloctest(list->path, list->data));
        else
            my_putstr(list->data);
        if (list->next != NULL && flags->l == false)
            my_putstr("  ");
        if (list->next != NULL && flags->l == true)
            my_putchar('\n');
        list = list->next;
    }
    my_putchar('\n');
}
