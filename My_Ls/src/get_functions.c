/*
** EPITECH PROJECT, 2023
** 1.3
** File description:
** get_functions
*/

#include "../include/my.h"

static void test_flag_l(struct flags *flags, struct linked_list *cur)
{
    if (flags->l == true) {
        my_putstr((flags->succes == true) ? "\n" : "");
        flag_l_file(cur->data);
        my_putstr(cur->data);
    } else {
        my_putstr((flags->succes == true) ? " " : "");
        my_putstr(cur->data);
    }
}

static void print_files(struct linked_list *no_flags, struct flags *flags)
{
    struct linked_list *cur = no_flags;
    struct stat buf;

    while (cur) {
        if (stat(cur->data, &buf) == -1) {
            cur = cur->next;
            continue;
        }
        if ((S_ISREG(buf.st_mode)) == 1 && flags->d == false) {
            test_flag_l(flags, cur);
            flags->succes = true;
        }
        cur = cur->next;
    }
    if (flags->succes == true)
        my_putchar('\n');
}

static void print_no_fd(struct linked_list *no_flags, struct flags *flags)
{
    struct linked_list *cur = no_flags;
    struct stat buf;

    while (cur) {
        if (my_strncmp(cur->data, "/root", 5) == 0) {
            my_puterrorstr("ls: cannot open directory '");
            my_puterrorstr(cur->data);
            my_puterrorstr("': Permission denied\n");
            flags->error = true;
            cur = cur->next;
            continue;
        }
        if (stat(cur->data, &buf) == -1) {
            my_puterrorstr("ls: cannot access '");
            my_puterrorstr(cur->data);
            my_puterrorstr("': No such file or directory\n");
            flags->error = true;
        }
        cur = cur->next;
    }
}

void unknown(struct linked_list *no_flags, struct flags *flags)
{
    struct linked_list *cur = no_flags;

    if (flags->is_no_flag == true || !cur)
        return;
    print_no_fd(no_flags, flags);
    print_files(no_flags, flags);
}

void get_no_flags(struct linked_list *list, struct flags *flags)
{
    struct linked_list *cur = list;
    struct linked_list *no_flags = NULL;

    if (!cur)
        return;
    while (cur) {
        if (cur->data[0] != '-')
            no_flags = add_at(no_flags, cur->data, NULL);
        cur = cur->next;
    }
    unknown(no_flags, flags);
    free_list(no_flags);
    return;
}

void get_arg(struct linked_list *list, struct linked_list **to_ls
    , struct flags *flags)
{
    struct linked_list *cur = list;
    struct stat buf;

    if (!cur)
        return;
    while (cur) {
        if (my_strncmp(cur->data, "/root", 5) == 0
        || stat(cur->data, &buf) == -1) {
            cur = cur->next;
            continue;
        }
        if (cur->data[0] != '-' && ((S_ISREG(buf.st_mode) && flags->d == true)
        || S_ISDIR(buf.st_mode))) {
            *to_ls = add_at(*to_ls, cur->data, cur->path);
        }
        cur = cur->next;
    }
    return;
}

void check_flags(struct flags *flags, char c)
{
    if (flags->is_no_flag == true)
        return;
    if (c == 'a')
        flags->a = true;
    if (c == 'l')
        flags->l = true;
    if (c == 't')
        flags->t = true;
    if (c == 'd')
        flags->d = true;
    if (c == 'r')
        flags->r = true;
    if (c == 'R')
        flags->up_r = true;
    if (c != 'a' && c != 'l' && c != 't' && c != 'd' && c != 'r' && c != 'R') {
        my_putstr("ls: invalid option -- '");
        my_putchar(c);
        my_putstr("'\nTry 'ls --help' for more information.\n");
        flags->is_no_flag = true;
    }
}

void get_flag(struct flags *flags, struct linked_list *list)
{
    struct linked_list *flags_only = NULL;
    struct linked_list *cur = list;

    if (!cur)
        return;
    while (cur) {
        if (cur->data[0] == '-')
            flags_only = add_at(flags_only, cur->data, NULL);
        cur = cur->next;
    }
    cur = flags_only;
    for (int j = 0; j < my_list_size(flags_only); j++) {
        for (int i = 1; cur->data[i] != '\0'; i++)
            check_flags(flags, cur->data[i]);
        cur = cur->next;
    }
    free_list(flags_only);
    return;
}
