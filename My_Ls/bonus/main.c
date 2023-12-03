/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-bsmyls-camille.billard
** File description:
** main
*/

#include "include/my.h"

void fs_cat_x_bytes(char const *filepath, int x)
{
    char buf[x];
    int fd = open(filepath, O_RDWR);

    read(fd, buf, x);
    for (int i = 0; buf[i] != '\0'; i++)
        write(1, &buf[i], 1);
    close(fd);
}

void flag_help(struct linked_list *list)
{
    struct linked_list *current = list;

    while (current) {
        if (my_strcmp(current->data, "--help") == 0) {
            free_list(list);
            fs_cat_x_bytes("asset/help.txt", 7729);
            my_putchar('\n');
            exit(0);
        }
        current = current->next;
    }
}

int error(struct flags *flags)
{
    if (flags->error == true)
        return 84;
    if (flags->is_no_flag == true)
        return 84;
    return 0;
}

void my_simple_ls(void)
{
    struct flags temp = {0};
    DIR *dir = opendir(".");
    struct linked_list *list = NULL;
    struct dirent *entries = readdir(dir);

    while (entries != NULL) {
        list = add_at(list, entries->d_name, NULL);
        entries = readdir(dir);
    }
    my_sort_list(&list, &my_strcasecmp);
    my_show_simple(list, &temp);
    free_list(list);
    closedir(dir);
}

int main(int ac, char **av)
{
    struct flags flags = {0};
    struct linked_list *to_ls = NULL;
    struct linked_list *list = my_params_to_list(ac, av);

    flag_help(list);
    if (ac < 2) {
        my_simple_ls();
        free_list(list);
        free_list(to_ls);
        return 0;
    }
    get_flag(&flags, list);
    get_no_flags(list, &flags);
    get_arg(list, &to_ls, &flags);
    if (flags.is_no_flag == false)
        my_ls(to_ls, &flags);
    free_list(list);
    free_list(to_ls);
    return (error(&flags));
}
