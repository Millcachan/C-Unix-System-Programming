/*
** EPITECH PROJECT, 2023
** 1.3
** File description:
** linked_list
*/

#include "../include/my.h"

struct linked_list *free_list(struct linked_list *list)
{
    struct linked_list *temp = NULL;

    while (list) {
        temp = list->next;
        free(list);
        list = temp;
    }
    return (list);
}

int my_list_size(struct linked_list const *begin)
{
    int len = 0;

    while (begin) {
        len++;
        begin = begin->next;
    }
    return (len);
}

static struct linked_list *create_cell(char *data)
{
    struct linked_list *cell = malloc(sizeof(struct linked_list));

    if (!cell)
        return (NULL);
    cell->data = data;
    cell->next = NULL;
    return (cell);
}

struct linked_list *add_at(struct linked_list *list, char *data, char *path)
{
    struct linked_list *cell = create_cell(data);

    cell->path = path;
    cell->next = list;
    return (cell);
}

struct linked_list *my_params_to_list(int ac, char *const *av)
{
    struct linked_list *list = NULL;

    if (ac == 0)
        return (list);
    for (int i = 1; i < ac; i++)
        list = add_at(list, av[i], av[i]);
    return (list);
}

void my_rev_list(struct linked_list **begin)
{
    struct linked_list *next = NULL;
    struct linked_list *previous = NULL;
    struct linked_list *current = *begin;

    while (current) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *begin = previous;
}
