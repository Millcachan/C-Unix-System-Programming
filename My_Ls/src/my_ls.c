/*
** EPITECH PROJECT, 2023
** tests
** File description:
** my_ls
*/

#include "../include/my.h"

void my_ls_flags(DIR *dir, struct dirent *entries,
    struct flags *flags, char *path)
{
    struct linked_list *list = NULL;

    while (entries != NULL) {
        list = add_at(list, entries->d_name, path);
        entries = readdir(dir);
    }
    ls_sort(&list, flags);
    if (flags->l == true) {
        my_putstr("total ");
        print_total(flags, list);
        my_putchar('\n');
    }
    if (flags->a == true)
        my_showlist(list, flags);
    else
        my_show_simple(list, flags);
    free_list(list);
}

void check_d(struct linked_list *to_ls, struct flags *flags)
{
    ls_sort(&to_ls, flags);
    if (!to_ls && flags->l) {
        flag_l(".");
        my_putchar('\n');
        return;
    }
    if (!to_ls) {
        my_putstr(".\n");
        return;
    }
    return my_show_d(to_ls, flags);
}

void my_ls_no_arg(struct linked_list *to_ls, struct flags *flags)
{
    DIR *dir;
    struct dirent *entries;
    struct linked_list *current = to_ls;

    if (my_list_size(to_ls) == 1) {
        dir = opendir(current->data);
        entries = readdir(dir);
        my_ls_flags(dir, entries, flags, current->data);
    } else if (my_list_size(to_ls) == 0 && flags->error == false
    && flags->succes == false) {
        dir = opendir(".");
        entries = readdir(dir);
        my_ls_flags(dir, entries, flags, NULL);
    } else {
        return;
    }
    closedir(dir);
}

void my_ls_bis(struct linked_list *to_ls, struct flags *flags)
{
    DIR *dir;
    struct dirent *entries;
    struct linked_list *current = to_ls;

    ls_sort(&to_ls, flags);
    current = to_ls;
    my_putstr((flags->succes) ? "\n" : "");
    while (current) {
        my_putstr(current->data);
        my_putstr(":\n");
        dir = opendir(current->data);
        entries = readdir(dir);
        my_ls_flags(dir, entries, flags, current->data);
        my_putstr((current->next) ? "\n" : "");
        current = current->next;
        closedir(dir);
    }
}

void my_ls(struct linked_list *to_ls, struct flags *flags)
{
    if (flags->d == true)
        return check_d(to_ls, flags);
    else if ((my_list_size(to_ls) == 1 && flags->error == false) ||
    (my_list_size(to_ls) == 0 && flags->error == false))
        return my_ls_no_arg(to_ls, flags);
    return my_ls_bis(to_ls, flags);
}
