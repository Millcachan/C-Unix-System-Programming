/*
** EPITECH PROJECT, 2023
** 1.3
** File description:
** flag_l
*/

#include "../include/my.h"

static char *print_name(char *str)
{
    char *ptr;

    if (!str)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '/' && str[i + 1] != '\0')
            ptr = &str[i + 1];
    return ptr;
}

void print_total(struct flags *flags, struct linked_list *list)
{
    struct linked_list *current = list;
    struct stat buf;
    int total = 0;
    char *path;

    while (current->next) {
        path = strcatalloctest(current->path, current->data);
        stat(path, &buf);
        free(path);
        if (flags->a == true && current->data[0] == '.')
            total += (buf.st_blocks / 2);
        if (current->data[0] != '.')
            total += (buf.st_blocks / 2);
        current = current->next;
    }
    my_putnbr(total);
}

static void print_type(struct stat *buf)
{
    if (S_ISDIR(buf->st_mode) != 0)
        my_putchar('d');
    if (S_ISREG(buf->st_mode) != 0)
        my_putchar('-');
    if (S_ISLNK(buf->st_mode) != 0)
        my_putchar('l');
    if (S_ISCHR(buf->st_mode) != 0)
        my_putchar('c');
    if (S_ISBLK(buf->st_mode) != 0)
        my_putchar('b');
    if (S_ISFIFO(buf->st_mode) != 0)
        my_putchar('p');
    if (S_ISSOCK(buf->st_mode) != 0)
        my_putchar('s');
}

void print_sticky_bit(struct stat *buf)
{
    if (buf->st_mode & S_ISVTX)
        my_putchar((buf->st_mode & S_IXOTH) ? 't' : 'T');
    else
        my_putchar((buf->st_mode & S_IXOTH) ? 'x' : '-');
}

static void printf_permissions(struct stat *buf)
{
    print_type(buf);
    my_putchar((buf->st_mode & S_IRUSR) ? 'r' : '-');
    my_putchar((buf->st_mode & S_IWUSR) ? 'w' : '-');
    my_putchar((buf->st_mode & S_IXUSR) ? 'x' : '-');
    my_putchar((buf->st_mode & S_IRGRP) ? 'r' : '-');
    my_putchar((buf->st_mode & S_IWGRP) ? 'w' : '-');
    my_putchar((buf->st_mode & S_IXGRP) ? 'x' : '-');
    my_putchar((buf->st_mode & S_IROTH) ? 'r' : '-');
    my_putchar((buf->st_mode & S_IWOTH) ? 'w' : '-');
    print_sticky_bit(buf);
    my_putstr(". ");
}

void print_time(char *time)
{
    char **time_split = my_str_to_word_array(time);

    my_putstr(time_split[2]);
    my_putchar(' ');
    my_putstr(time_split[1]);
    my_putstr(".  ");
    my_putstr(time_split[3]);
    my_putchar(':');
    my_putstr(time_split[4]);
    for (int i = 0; i < 7; i++)
        free(time_split[i]);
    free(time_split);
}

void flag_l_file(char *to_ls)
{
    struct stat buf;
    struct passwd *passwd;
    struct group *group;

    stat(to_ls, &buf);
    passwd = getpwuid(buf.st_uid);
    group = getgrgid(buf.st_gid);
    printf_permissions(&buf);
    my_putnbr(buf.st_nlink);
    my_putchar(' ');
    my_putstr(passwd->pw_name);
    my_putchar(' ');
    my_putstr(group->gr_name);
    my_putchar(' ');
    my_putnbr(buf.st_size);
    my_putchar(' ');
    print_time(ctime(&buf.st_mtime));
    my_putchar(' ');
    return;
}

void flag_l(char *to_ls)
{
    struct stat buf;
    struct passwd *passwd;
    struct group *group;

    stat(to_ls, &buf);
    passwd = getpwuid(buf.st_uid);
    group = getgrgid(buf.st_gid);
    printf_permissions(&buf);
    my_putnbr(buf.st_nlink);
    my_putchar(' ');
    my_putstr(passwd->pw_name);
    my_putchar(' ');
    my_putstr(group->gr_name);
    my_putchar(' ');
    my_putnbr(buf.st_size);
    my_putchar(' ');
    print_time(ctime(&buf.st_mtime));
    my_putchar(' ');
    my_putstr(print_name(to_ls));
    return free(to_ls);
}
