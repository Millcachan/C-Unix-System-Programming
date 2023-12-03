/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-myls-camille.billard
** File description:
** my_sort_time
*/

#include "../include/my.h"

int my_time_cmp(char *s1, char *s2)
{
    struct stat buf;
    int a;
    int b;

    stat(s1, &buf);
    a = buf.st_mtime;
    stat(s2, &buf);
    b = buf.st_mtime;
    if (a > b)
        return -1;
    if (a < b)
        return 1;
    return 0;
}

void my_sort_list_swap_time_d(struct linked_list *list, int (*cmp)())
{
    void *swap = NULL;
    void *swap2 = NULL;

    if (cmp(list->data, list->next->data) > 0) {
        swap = list->data;
        swap2 = list->path;
        list->data = list->next->data;
        list->path = list->next->path;
        list->next->data = swap;
        list->next->path = swap2;
    }
}

void my_sort_list_time_d(struct linked_list **begin, int (*cmp)())
{
    struct linked_list *list1 = *begin;
    struct linked_list *list2 = *begin;
    int len = my_list_size(list1);

    for (int i = 0; i < len - 1; i++) {
        list2 = list1;
        for (int j = 0; j < len - i - 1; j++) {
            my_sort_list_swap_time_d(list2, cmp);
            list2 = list2->next;
        }
    }
}

void my_sort_list_swap_time(struct linked_list *list, int (*cmp)())
{
    void *swap = NULL;
    void *swap2 = NULL;
    char *path1 = strcatalloctest(list->path, list->data);
    char *path2 = strcatalloctest(list->next->path, list->next->data);

    if (cmp(path1, path2) > 0) {
        swap = list->data;
        swap2 = list->path;
        list->data = list->next->data;
        list->path = list->next->path;
        list->next->data = swap;
        list->next->path = swap2;
    }
    free(path1);
    free(path2);
}

void my_sort_list_time(struct linked_list **begin, int (*cmp)())
{
    struct linked_list *list1 = *begin;
    struct linked_list *list2 = *begin;
    int len = my_list_size(list1);

    for (int i = 0; i < len - 1; i++) {
        list2 = list1;
        for (int j = 0; j < len - i - 1; j++) {
            my_sort_list_swap_time(list2, cmp);
            list2 = list2->next;
        }
    }
}
