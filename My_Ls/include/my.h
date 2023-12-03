/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my
*/

#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>

#ifndef MY_H
    #define MY_H

struct flags {
    bool a;
    bool l;
    bool t;
    bool d;
    bool r;
    bool up_r;
    bool error;
    bool succes;
    bool is_no_flag;
};

struct linked_list {
    char *data;
    char *path;
    struct linked_list *next;
};

void my_simple_ls(void);
void my_putchar(char c);
int my_putstr(char *str);
int my_strlen(char *str);
void flag_l(char *to_ls);
void flag_l_file(char *to_ls);
void my_putnbr(long long nbr);
int my_puterrorstr(char *str);
int my_time_cmp(char *s1, char *s2);
char **my_str_to_word_array(char *str);
int my_strncmp(char *s1, char *s2, int n);
char *strcatalloctest(char *dest, char *src);
void my_rev_list(struct linked_list **begin);
int my_strcasecmp(const char *s1, const char *s2);
int my_list_size(struct linked_list const *begin);
struct linked_list *free_list(struct linked_list *list);
void my_ls(struct linked_list *to_ls, struct flags *flags);
void my_sort_list(struct linked_list **begin, int (*cmp)());
void get_flag(struct flags *flags, struct linked_list *list);
struct linked_list *my_params_to_list(int ac, char *const *av);
void print_total(struct flags *flags, struct linked_list *list);
void ls_sort(struct linked_list **to_sort, struct flags *flags);
void my_sort_list_time(struct linked_list **begin, int (*cmp)());
void get_no_flags(struct linked_list *list, struct flags *flags);
void my_sort_list_time_d(struct linked_list **begin, int (*cmp)());
void my_show_d(struct linked_list const *list, struct flags *flags);
void my_showlist(struct linked_list const *list, struct flags *flags);
void my_show_simple(struct linked_list const *list, struct flags *flags);
struct linked_list *add_at(struct linked_list *list, char *dat, char *path);
void get_arg(struct linked_list *list,
    struct linked_list **to_ls, struct flags *flags);

#endif
