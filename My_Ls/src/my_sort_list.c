/*
** EPITECH PROJECT, 2023
** tests
** File description:
** my_sort_list
*/

#include "../include/my.h"

int my_strcasecmp(const char *s1, const char *s2)
{
    char c1;
    char c2;

    while (*s1 && *s2) {
        c1 = *s1;
        c2 = *s2;
        if (c1 >= 'A' && c1 <= 'Z') {
            c1 = c1 - 'A' + 'a';
        }
        if (c2 >= 'A' && c2 <= 'Z') {
            c2 = c2 - 'A' + 'a';
        }
        if (c1 != c2) {
            return c1 - c2;
        }
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

int my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;

    if (n <= 0)
        return (0);
    while (n > 0) {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return -1;
        if (s1[i] == '\0' && s2[i] == '\0')
            return 0;
        i++;
        n--;
    }
    return 0;
}

void my_sort_list_swap(struct linked_list *list, int (*cmp)())
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

void my_sort_list(struct linked_list **begin, int (*cmp)())
{
    struct linked_list *list1 = *begin;
    struct linked_list *list2 = *begin;
    int len = my_list_size(list1);

    for (int i = 0; i < len - 1; i++) {
        list2 = list1;
        for (int j = 0; j < len - i - 1; j++) {
            my_sort_list_swap(list2, cmp);
            list2 = list2->next;
        }
    }
}

void ls_sort(struct linked_list **to_sort, struct flags *flags)
{
    my_sort_list(to_sort, &my_strcasecmp);
    if (flags->t == true && flags->d == false)
        my_sort_list_time(to_sort, &my_time_cmp);
    if (flags->t == true && flags->d == true)
        my_sort_list_time_d(to_sort, &my_time_cmp);
    if (flags->r == true)
        my_rev_list(to_sort);
    return;
}
